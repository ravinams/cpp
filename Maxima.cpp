#include <iostream>
#include <fstream>    // For input and output files
#include <algorithm>  // Needed for sort()
#include <map>        // Needed for map<double, double> bst
using namespace std;
class Point
{  public:
      void setMaximal();       // Sets maximal to true: The point is maximal

      double getX() const;
      double getY() const;

      bool getMaximal() const;
            bool operator<(const Point& p) const;
      // Returns (*this < p)

      friend istream& operator>>(istream& ISObj, Point& p);
      // Inputs a single point: Its x, y and z coords

      friend ostream& operator<<(ostream& OSObj, const Point& p);
      // Outputs a single point: Its x, y and z coords

   private:
      double x = 0, y = 0, z = 0;  // Coords of the point
      bool maximal = false;        // Whether the point is maximal
};

typedef map<double, double> mapdd;

void inputPoints(ifstream& infile, Point* points, int* numPoints);
void findMaximal(Point* points, int numPoints, int* maxNum);
void printMaximal(ofstream& outfile, Point* points, int numPoints, int maxNum);

int main(int argc, char *argv[])
{  if (argc != 3)
   {  // Error check

   }

   ifstream infile(argv[1]);
   ofstream outfile(argv[2]);


   for (int i=1; i<=10; i++)  // Iterate on 10 sets of points
   {  int numPoints = 0;  // Number of points in the i-th set
      Point points[1000]; // points[0..(numPoints-1)]
      inputPoints(   );   // Reads the i-th input set
      sort(   );          // Sorts points[0..(numPoints-1)]

      int maxNum = 0;     // Number of maximal points in the i-th set
      findMaximal(   );   // Finds the maximal points
      outfile << "Output for " << i << "-th Set of Points\n";
      printMaximal(  );
   }
   //close files
    infile.close();
    outfile.close();

}
void inputPoints(  )
// Inputs all the points into points[]
{
    
  
    // infile >> points[i];
}






