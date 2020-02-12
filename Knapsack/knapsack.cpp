
#include<bits/stdc++.h>
using namespace std;

int knapsack_dp(int n, int M, int w[], int p[])
{
    int i,j;
    int knapsack[n+1][M+1];

    for(j=0;j<=M;j++)
        knapsack[0][j]=0;

    for(i=0;i<=n;i++)
        knapsack[i][0]=0;
    
    int s = 1,c=0 ;

    
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=M;j++)
        {
             
    
            if(w[i-1]<=j)
            {
                knapsack[i][j]=max(knapsack[i-1][j],p[i-1]+knapsack[i-1][j-w[i-1]]);
            }

            else
            {
                knapsack[i][j]=knapsack[i-1][j];
            }
            
        
            
        }
       
         
          
    }
    
   
    return knapsack[n][M];
}

int main()
{
    int i,j;
    int n;  
    int M; 

    cout<<"Enter a number of items : ";
    cin>>n;
    cout<<"Enter knapsack capacity : ";
    cin>>M;
    int w[n];  
    int p[n]; 

    cout<<"Enter weights and values of "<<n<<" items :"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<" Item "<<i+1<<": ";      
        cin>>w[i]>>p[i];       
    }

    int result=knapsack_dp(n,M,w,p);

    cout<<"value = $"<<result<<endl;

    return 0;
}

