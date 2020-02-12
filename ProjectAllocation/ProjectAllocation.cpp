#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include <stdexcept>

using namespace std ;


class Staff
{
   private :
	   string staffName ;
	   int supervisionLoad ;
	   int allocatedStudents;
   public :
      Staff(string n , int l) : staffName(n),supervisionLoad(l),allocatedStudents(0) {} ;
    
      string getStaffName()
      {
      	return staffName ;
      }
     
      int  getSupervisionLoad()
      {
      	return supervisionLoad ;
      }
      int getAllocatedStudents()
      {
      	return allocatedStudents ;
      }
      bool isAlreadyFull()
       {
       	  if ( allocatedStudents >= supervisionLoad )
       	  	 return true ;
       	  else
       	  	 return false ;
       }
      void allocateStudent()
      {
      	if (!isAlreadyFull())
      		allocatedStudents ++;
      	else
      	  throw std::domain_error("The supervisor is already full");
      }
};

class Project
{
  private :
	  int projectId ;
	  string staffName ;
	  int multiplicity ;
	  string projectName ;
	  int allocatedStudents;
  public :
      Project(int pid,string sn,int m,string pn) : projectId(pid),staffName(sn),multiplicity(m),projectName(pn),allocatedStudents(0) {} ;
    
       int getProjectId()
       {
       	return  projectId;
       }     

       string getStaffName()
       {
       	 return staffName ;
       }

       int getMultiplicity()
       {
       	return multiplicity ;
       }
   
       string getProjectName()
       {
       return projectName ;
       }

       int getAllocatedStudents()
       {
       	 return allocatedStudents ;
       }
       
       bool isAlreadyFull()
       {
       	  if ( allocatedStudents >= multiplicity )
       	  	 return true ;
       	  else
       	  	 return false ;
       }

     void allocateStudent()
      {
      	if ( !isAlreadyFull())
      		allocatedStudents ++;
      	else
      	  throw std::domain_error("The supervisor is already full");
      }
     
};

class Student
{
    private : 
	    string studentName ;   
	    int choice1 ;
	    int choice2 ;
	    int choice3 ;
	    int choice4 ;
	    int allocatedChoice ;
    public:
       Student(string n, int c1 , int c2 , int c3 , int c4):studentName(n),choice1(c1),choice2(c2),choice3(c3),choice4(c4),allocatedChoice(0) {} 

        string getStudentName() 
        {
        	return studentName ;
        }

	    int getChoice1() 
	    {
	    	return choice1 ;
	    }
	    int getChoice2() 
	    {
	    	return choice2 ;
	    }
	    int getChoice3()
	    {
	    	return choice3 ;
	    }
	    int getChoice4() 
	    {
	    	return choice4;
	    }
	    int getAllocatedChoice()
	    {
	    	return allocatedChoice ;
	    }
	    void allocateProject(int choice)
	    {
           allocatedChoice = choice ;
	    }
};

void readStaff(string staffFile , vector<Staff> &staff) ;

void readProjects(string projectFile , vector<Project> &projects) ;

void readStudents(string studentFile , vector<Student> &students) ;

void printStaff(vector<Staff> &staff) ;

void printProjects(vector<Project> &projects) ;

void printStudents(vector<Student> &students) ;

void allocateProjectsForStudents(vector<Staff> &staff,vector<Project> &projects,vector<Student> &students) ;

Staff&   findStaff(vector<Staff> &staff,string &staffName);
Project& findProject(vector<Project> &projects, int &projectId);



int main(int argc,char **argv)
{
    
    if (argc < 4)
    {
      std::cerr << "You must supply <Staff>, <Projects>,<Students> text files as command line arguments."<<std::endl;
      exit(1);
    }

    string staffFile , projectsFile , studentsFile ;

    staffFile = argv[1];
    projectsFile = argv[2];
    studentsFile = argv[3];
    
    // cout<<"TEST (1) " <<staffFile<<" "<<projectsFile<<" "<<studentsFile<<" "<<endl;
    
    vector<Staff>   staff;
    vector<Project> projects;
    vector<Student> students ;
    
    readStaff(staffFile,staff);  
    readProjects(projectsFile,projects);   
    readStudents(studentsFile,students);

    allocateProjectsForStudents(staff,projects,students);
   
        
    return 0 ;
}

void printStudents(vector<Student> &students)
{
   cout<<"==================="<<endl ;
   cout<<"====STUEDENTS====="<<endl ;
   cout<<"==================="<<endl ;
   for(int k = 0 ;k < students.size() ; k++)
   	 {
   	 	Student &s=students.at(k);
   	 	cout<<s.getStudentName()<<" "<<s.getChoice1()<<" "<<s.getChoice2()<<" "<<s.getChoice3()<<" "<<s.getChoice4()<<endl;
   	 }
}

void printStaff(vector<Staff> &staff) 
{

   cout<<"==================="<<endl ;
   cout<<"=======STAFF======="<<endl ;
   cout<<"==================="<<endl ;
  for(int k = 0 ;k < staff.size() ; k++)
   	 {
   	 	Staff &s=staff.at(k);
   	 	cout<<s.getStaffName()<<" "<<s.getSupervisionLoad()<<endl;
   	 }
}

void printProjects(vector<Project> &projects) 
{
   cout<<"==================="<<endl ;
   cout<<"======PROJECTS====="<<endl ;
   cout<<"==================="<<endl ;

	  for(int k = 0 ;k < projects.size() ; k++)
   	 {
   	 	Project &p=projects.at(k);
   	 	cout<<p.getProjectId()<<" "<<p.getStaffName()<<" "<<p.getMultiplicity()<<" "<<p.getProjectName()<<endl;
   	 }

}

void printAllocation(vector<Student> &students, int score)
{
    ofstream allocateFile("allocate.txt");
	if(!allocateFile)
	{
		std::cerr << "Cannot create the allocate.txt File : "<<std::endl;
		exit(1) ;
	}

	 for(int k = 0 ;k < students.size() ; k++)
   	 {
   	 	Student &s=students.at(k);
   	 	allocateFile<<s.getStudentName()<<" "<<s.getAllocatedChoice()<<endl;
   	 }

     allocateFile<<score<<endl;
     allocateFile.close(); 
}

void readStudents(string studentFile , vector<Student> &students)
{
	std::ifstream in(studentFile);
	if(!in)
	{
		std::cerr << "Cannot open the File : "<<studentFile<<std::endl;
		exit(1) ;
	}
 
	std::string str;
	while (std::getline(in, str))
	{
		istringstream ss(str); 
		string name ;
		int c1,c2,c3,c4 ;
		ss>>name;
		ss>>c1>>c2>>c3>>c4;
		students.push_back(Student(name,c1,c2,c3,c4));
	}
	in.close(); 
	printStudents(students); // Debug purpose
}

void readProjects(string projectFile , vector<Project> &projects)
{
	std::ifstream in(projectFile);
	if(!in)
	{
		std::cerr << "Cannot open the File : "<<projectFile<<std::endl;
		exit(1) ;
	}
 
	std::string str;
	while (std::getline(in, str))
	{
	    istringstream ss(str); 
		int pid;
		string sName ;
		int m ;
		string pName ;
		ss>>pid;
		ss>>sName ;
		ss>>m ;
		getline(ss, pName);
		projects.push_back(Project(pid,sName,m,pName));
	}
	in.close(); 
	printProjects(projects) ; // DEBUG purpose
}

void readStaff(string staffFile , vector<Staff> &staff)
{
	ifstream in(staffFile);
	if(!in)
	{
		std::cerr << "Cannot open the File : "<<staffFile<<std::endl;
		exit(1) ;
	}
 
	std::string str;
	while (std::getline(in, str))
	{
	//	cout<<str<<endl ;
		istringstream ss(str); 
		string name ;
		int load ;
		ss>>name;
		ss>>load;
		staff.push_back(Staff(name,load));

	}
	in.close(); 
	printStaff(staff) ; // DEBUG PURPOSE
}

Staff&   findStaff(vector<Staff> &staff,string &staffName)
{

  for(int k = 0 ;k < staff.size() ; k++)
   	 {
   	 	//Staff s=staff.at(k);
   	 	if ( staff.at(k).getStaffName()==staffName )
   	 		return staff.at(k);
   	 }
   	 //return nullptr ;
}

Project& findProject(vector<Project> &projects, int &projectId)
{
	 for(int k = 0 ;k < projects.size() ; k++)
   	 {
   	 	//Project p=projects.at(k);
   	 	if (projects.at(k).getProjectId() == projectId)
   	 		 return projects.at(k) ;   	 	
   	 }
   	 //return nullptr ;
}

bool isProjectORStaffFull(vector<Project> &projects, vector<Staff> &staff, int projectId)
{	
     Project &p = findProject(projects,projectId);
     string staffName = p.getStaffName();
     Staff &sf = findStaff(staff,staffName);

     if ( p.isAlreadyFull() || sf.isAlreadyFull())
     	 return true ;
     else
     	return false;
   
}
void allocateProject(vector<Project> &projects, vector<Staff> &staff,Student &s, int projectId)
{
     Project &p = findProject(projects,projectId);
     string staffName = p.getStaffName();
     Staff &sf = findStaff(staff,staffName);

   p.allocateStudent();
   sf.allocateStudent();
   s.allocateProject(projectId) ;   
}

void allocateProjectsForStudents(vector<Staff> &staff,vector<Project> &projects,vector<Student> &students) 
{
  
   //printProjects(projects);
   //printStaff(staff);

   int score = 0;
  for(int k = 0 ;k < students.size() ; k++)
   	 {
   	 	
   	 	Student &s = students.at(k);   	 	

        int choice1 = s.getChoice1();
        int choice2 = s.getChoice2();
        int choice3 = s.getChoice3();
        int choice4 = s.getChoice4();
        
        if (!isProjectORStaffFull(projects,staff,s.getChoice1())) // check for choice 1        
        {          
          allocateProject(projects,staff,s,s.getChoice1()) ; 
          score = score + 4 ;
        }
        else if (!isProjectORStaffFull(projects,staff,s.getChoice2())) // check for choice 2       
        {
         allocateProject(projects,staff,s,s.getChoice2()) ; 
         score = score + 3 ;
        }
        else if (!isProjectORStaffFull(projects,staff,s.getChoice3())) // check for choice 3        
        {
         allocateProject(projects,staff,s,s.getChoice3()) ; 
         score = score + 2 ;
        } 
        else if (!isProjectORStaffFull(projects,staff,s.getChoice4())) // check for choice 4        
        {
          allocateProject(projects,staff,s,s.getChoice4()) ; 
          score = score + 1 ;
        }
        else  // since all are full , allocate 0    
        {
          s.allocateProject(0) ;
          score = score + 0 ;
        }

      }

     printAllocation(students,score);
   
}