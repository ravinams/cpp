#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <signal.h>

using namespace std ;

// these are shared variables will be used across the threads .
static long maxNCarsInTunnel = 0, nCarsInTunnel = 0, waitedNCars = 0,totalNCars=0, whittierBound=0,bearBound=0;

// current allowed traffic direction .
static string tunnel_direction; 

//one mutex variable 
static pthread_mutex_t traffic_lock; 
//one condition variable 
static pthread_cond_t wake_up = PTHREAD_COND_INITIALIZER; // conditional variable 


// structure to hold the given car information .
typedef struct s_cars {
    int carNo;
    string direction ;
    int crossTime ;
} s_car;


/* method to be invoked by the Tunnel thread 
      a).Allow traffic towards "WB"
      b).Block the traffic 
      c).Allow traffic towards "BB"
      d).Block the traffic  
 */
void *tunnel(void *arg) {
        
       
   
   int done = 0 ;
   while(done == 0 ) {
       
        // Allow direction towards "WB"
          pthread_mutex_lock(&traffic_lock);
          tunnel_direction= "WB" ;  // this will assign "WB" to 'traffic' variable 
          printf("The tunnel is now open for Whittier-bound traffic.\n");
          pthread_cond_broadcast(&wake_up);
          pthread_mutex_unlock(&traffic_lock);
          sleep(5) ; //sleep for 5 seconds
          
           // Block traffic 
          pthread_mutex_lock(&traffic_lock);
          tunnel_direction=""; // this will assign null to 'traffic' variable 
          printf("The tunnel is now closed to ALL traffic.\n");
          pthread_cond_broadcast(&wake_up);
          pthread_mutex_unlock(&traffic_lock);
          sleep(5); //sleep for 5 seconds
          
            // Allow direction towards "BB"
          pthread_mutex_lock(&traffic_lock);
          tunnel_direction="BB" ; // this will assign "BB" to 'traffic' variable 
          printf("The tunnel is now open for Bear Valley-bound traffic.\n");
          pthread_cond_broadcast(&wake_up);
          pthread_mutex_unlock(&traffic_lock);
          sleep(5); // sleep for 5 seconrds .
          
          // Block the traffic 
          pthread_mutex_lock(&traffic_lock);
          tunnel_direction=""; // this will assign null to 'traffic' variable 
          printf("The tunnel is now closed to ALL traffic.\n");
          pthread_cond_broadcast(&wake_up);
          pthread_mutex_unlock(&traffic_lock);
          sleep(5) ; //sleep for 5 seconds
          
          // if all cars passed the tunnel , then quit the tunnel thread 
          if (totalNCars == (whittierBound + bearBound))
              done = 1 ;
              
    }  ;
    
      pthread_exit((void*) 0);
}

// method to be  executed by 'Bear Valley-bound' car threads .
void *BBcar(void *arg) 
{
    s_car *carData = (s_car*)arg ;
      
     cout<<"Car #"<<carData->carNo<<" going to Big Bear arrives at the tunnel.\n";
    
     // waiting for tunnel thread to allow traffic towards car's direction 
     pthread_mutex_lock(&traffic_lock);
     while(carData->direction !=tunnel_direction)
        pthread_cond_wait(&wake_up,&traffic_lock);
      pthread_mutex_unlock(&traffic_lock);
     
    
      // waiting for cars inside tunnel to pass  .
      pthread_mutex_lock(&traffic_lock);
      while(nCarsInTunnel >= maxNCarsInTunnel)
      {
          waitedNCars ++ ;
          pthread_cond_wait(&wake_up,&traffic_lock);
      }
      pthread_mutex_unlock(&traffic_lock);
      
      pthread_mutex_lock(&traffic_lock);
     
      cout<<"Car #"<<carData->carNo<<" going to Big Bear enters the tunnel.\n";
      nCarsInTunnel++;
      pthread_mutex_unlock(&traffic_lock);
      
      sleep(carData->crossTime) ; // sleep for cross time 
      
      pthread_mutex_lock(&traffic_lock);
   
     cout<<"Car #"<<carData->carNo<<" going to Big Bear exit the tunnel.\n";
    
     
     bearBound ++ ;
    
    nCarsInTunnel--;
    pthread_cond_broadcast(&wake_up);
    pthread_mutex_unlock(&traffic_lock);
     
    pthread_exit((void*) 0);
}

// method to be  executed by 'Whittier-bound' car threads .
void *WBcar(void *arg) 
{
    s_car *carData = (s_car*)arg ;
      
     cout<<"Car #"<<carData->carNo<<" going to Whittier-bound arrives at the tunnel.\n";
    
     // waiting for tunnel thread to allow traffic towards car's direction 
     pthread_mutex_lock(&traffic_lock);
     while(carData->direction !=tunnel_direction)
        pthread_cond_wait(&wake_up,&traffic_lock);
      pthread_mutex_unlock(&traffic_lock);
     
    
      // waiting for cars inside tunnel to pass  .
      pthread_mutex_lock(&traffic_lock);
      while(nCarsInTunnel >= maxNCarsInTunnel)
      {
          waitedNCars ++ ;
          pthread_cond_wait(&wake_up,&traffic_lock);
      }
      pthread_mutex_unlock(&traffic_lock);
      
      pthread_mutex_lock(&traffic_lock);
     
      cout<<"Car #"<<carData->carNo<<" going to Whittier-bound enters the tunnel.\n";
      nCarsInTunnel++;
      pthread_mutex_unlock(&traffic_lock);
      
      sleep(carData->crossTime) ; // sleep for cross time 
      
      pthread_mutex_lock(&traffic_lock);
   
     cout<<"Car #"<<carData->carNo<<" going to Whittier-bound exit the tunnel.\n";
    
     
         whittierBound ++ ;
    
     nCarsInTunnel--;
    pthread_cond_broadcast(&wake_up);
    pthread_mutex_unlock(&traffic_lock);
     
    pthread_exit((void*) 0);
}

int main(int argc, char** argv) {
    
   string fileName ;
   cout<<"Enter the file name  : ";
   cin>>fileName ;

    // Open file for Reading 
    ifstream inputFile;
    inputFile.open(fileName.c_str(),ios_base::in) ;

    if (!inputFile.is_open()) {
        perror("Error while opening the file.\n");
        exit(-1);
    }

    pthread_mutex_init(&traffic_lock, NULL) ; // initializing the tunnel thread
    pthread_t tunnel_tid ;
    pthread_t car_tid[100];
    
    int lineCnt = 0;
    string line ;
    while (std::getline(inputFile, line)) { // Read input file Line by Line
        
         int aTime;
         char direction[3]; // BB or WB
         int cTime;
    
        stringstream  iss(line);
 
        if (lineCnt == 0) { // First line 
            iss>>maxNCarsInTunnel ;         
            pthread_create(&tunnel_tid, NULL, tunnel, NULL); // create & invoke 'tunnel' thread 
        } else {  // second line onwards 
            s_car *carData = new s_car ;
            totalNCars ++ ;
            iss>>aTime>>direction>>cTime ;
            carData->carNo = lineCnt ;          
            carData->direction = direction ;
            carData->crossTime  = cTime ;
            
          
            sleep(aTime) ; // sleep for arrival time
            if (strcmp(direction,"WB") == 0) 
              pthread_create(&car_tid[lineCnt-1], NULL, WBcar, carData);  // create & invoke 'WBcar' thread
            else
              pthread_create(&car_tid[lineCnt-1], NULL, BBcar, carData);  // create & invoke 'BBcar' thread   
        }

        lineCnt++;
    }

    //  wait for the threads to finish 
    for (int k = 0; k < totalNCars; k++) {
        pthread_join(car_tid[k], NULL);
    }
    
    // print the statistics 
    cout<<"\n";
    cout<<bearBound<<" car(s) going to Bear Valley arrived at the tunnel.\n";
    cout<<whittierBound<<" car(s) going to Whittier arrived at the tunnel.\n";
    cout<<waitedNCars<<" car(s) were delayed.\n";
         
    return (0);
}



