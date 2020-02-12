/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sparseAdd.cpp
 * Author: oracle
 *
 * Created on February 24, 2018, 5:52 AM
 */

#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <math.h> 
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

struct element {
    int r;
    int c;
    double value;
};

// this struct created to avoid multiple reads of the same file ;

struct dimension {
    int rows; // no of rows in matrix .. 
    int cols; // no of rows in matrix
    int validEntriesCnt; // no of valid entries . excluding  '#' line , 'dimension' line , 'out of bouds' lines in file
};

/*
 * 
 */

dimension findDimensionOfMatrix(string filename);

void printMatrixFromFile(string filename);
void printMatrixFromStruct(element *matrix, int);
void populateStructFromFile(element[], string);

element* addSparseMatrices(element *matrixA, int matrixAS, element *matrixB, int matrixBS);

void printMatrixToFile(element *, int size);



string matrixCFile = "output.txt";

int main(int argc, char** argv) {

    string matrixAFile, matrixBFile;

    ifstream ifs;

    cout << "Enter 1st matrix file name : ";
    cin>>matrixAFile;
    cout << endl << "Enter 2nd matrix file name : ";
    cin>>matrixBFile;


    if (matrixAFile.compare(matrixBFile) == 0) {
        cout << "Both file are same , please enter different files ,  existing program";
        exit(1);
    }

    ifs.open(matrixAFile.c_str(), ios_base::in);
    if (ifs.fail()) {
        cout << "Failed to open 1st file ,  The program will end." << "\n";
        exit(1);
    }
    ifs.close();

    ifs.open(matrixBFile.c_str(), ios_base::in);
    if (ifs.fail()) {
        cout << "Failed to open 2nd file ,  The program will end." << "\n";
        exit(1);
    }
    ifs.close();

    //        // print MatrixA.
    //        cout<<"-----"<<endl ;
    //        printMatrixFromFile(matrixAFile) ;
    //        // print MatrixB
    //        cout<<"-----"<<endl ;
    //        printMatrixFromFile(matrixBFile) ;
    //        cout<<"-----"<<endl ;


    dimension matrixAD = findDimensionOfMatrix(matrixAFile);
    dimension matrixBD = findDimensionOfMatrix(matrixBFile);


    if (matrixAD.rows * matrixAD.cols == matrixBD.rows * matrixBD.cols) {

        element* matrixA = new element[matrixAD.validEntriesCnt]; // 
        element* matrixB = new element[matrixBD.validEntriesCnt]; // 

        populateStructFromFile(matrixA, matrixAFile);
        populateStructFromFile(matrixB, matrixBFile);

        //uncomment the below line to print the contents of the struct A & B
        //        cout << "-----" << endl;
        //        printMatrixFromStruct(matrixA, matrixAD.validEntriesCnt);
        //        cout << "-----" << endl;
        //        printMatrixFromStruct(matrixB, matrixBD.validEntriesCnt);
        //        cout << "-----" << endl;

        element* matrixC = addSparseMatrices(matrixA, matrixAD.validEntriesCnt, matrixB, matrixBD.validEntriesCnt);

        // set the matrix size at the beging 
        matrixC[0].r = matrixAD.rows;
        matrixC[0].c = matrixAD.cols;
        matrixC[0].value = 0.0;



        //  uncomment the below line to print the contents of the struct C
        // printMatrixFromStruct(matrixC, matrixAD.validEntriesCnt + matrixBD.validEntriesCnt);
        
        printMatrixToFile(matrixC, matrixAD.validEntriesCnt + matrixBD.validEntriesCnt);

        delete[]matrixA;
        delete[]matrixB;
        delete[]matrixC;

    } else // different sizes 
    {
        cout << "Both matrices are incompatible due to different dimensions ." << endl;
        ofstream ofs;
        ofs.open(matrixCFile.c_str(), ofstream::out);
        ofs.close();
        exit(0);
    }

    return 0;
}

dimension findDimensionOfMatrix(string filename) {

    dimension matrixD;


    stringstream ss;
    ifstream ifs;
    ifs.open(filename.c_str(), ios_base::in);

    string line = "";

    int validLineCount = 0;
    while (getline(ifs, line)) {
        int rowIndex, colIndex;
        double value = 0.0;
        if (line[0] == '#')
            continue;
        else {// exclude lines starts with '#'
            ss.clear(); //Clears the stream so you can re-use it          
            ss.str(line);
            ss >> rowIndex >> colIndex>>value;

            // to debug , uncomment below line 
            // cout<<" Line:  "<<line<<" - rowIndex :"<<rowIndex<<" - colIndex:"<<colIndex<<" value :"<<value<<endl;  

            if (value == 0.0) { // the first entry  after '#' rows is dimension entry
                matrixD.rows = rowIndex;
                matrixD.cols = colIndex;

                continue;
            } else {
                // Attempting bonus points 
                if (rowIndex <= matrixD.rows && colIndex <= matrixD.cols) // this is to filter out 'out of bound' rows .
                {
                    validLineCount = validLineCount + 1;
                    matrixD.validEntriesCnt = validLineCount;
                }
            }

        }

    }

    ifs.close();
    return matrixD;
}

void printMatrixFromStruct(element* matrix, int size) {
    for (int i = 0; i < size && matrix[i].r != 0; i++) {
        cout << matrix[i].r << " " << matrix[i].c << " " << setprecision(2) << fixed << matrix[i].value << endl;
    }
}

void populateStructFromFile(element *matrix, string filename) {
    stringstream ss;
    ifstream ifs;
    ifs.open(filename.c_str(), ios_base::in);
    string line = "";
    int num = 0;
    int rows = 0, cols = 0;

    ss.clear();

    while (getline(ifs, line)) {
        int rowIndex, colIndex;
        double value = 0.0;
        if (line[0] == '#')
            continue;
        else {// exclude lines starts with '#'
            ss.clear(); //Clears the stream so you can re-use it          
            ss.str(line);
            ss >> rowIndex >> colIndex>>value;

            // to debug , uncomment below line 
            // cout<<" Line:  "<<line<<" - rowIndex :"<<rowIndex<<" - colIndex:"<<colIndex<<endl;  

            if (value == 0.0) { // the first entry  after '#' rows is dimension entry
                rows = rowIndex;
                cols = colIndex;

                continue;
            } else {
                // Attempting bonus points 
                if (rowIndex <= rows && colIndex <= cols) // this is to filter out 'out of bound' rows .
                {
                    matrix[num].r = rowIndex;
                    matrix[num].c = colIndex;
                    matrix[num].value = value;

                    // cout<<num<<" "<<matrix[num].r<<" "<<matrix[num].c<<" "<< matrix[num].value<<endl ;  
                    num++;
                }
            }

        }

    }
}


// this is test function to verify the contents of file 

void printMatrixFromFile(string filename) {
    ifstream ifs;
    ifs.open(filename.c_str(), ios_base::in);

    string line = "";
    while (getline(ifs, line)) {
        cout << line << endl;
    }
    ifs.close();
}

element* addSparseMatrices(element *matrixA, int matrixAS, element *matrixB, int matrixBS) {
    element* matrixC = new element[matrixAS + matrixBS];


    // Addition and subtraction
    int i = 0, j = 0, s = 1, t1, t2;
    t1 = matrixAS;
    t2 = matrixBS;

    while ((i < t1)&&(j < t2)) {
        if (matrixA[i].r == matrixB[j].r) // if rows are equal
        {
            if (matrixA[i].c == matrixB[j].c) // if columns are equal
            {
                matrixC[s].r = matrixA[i].r;
                matrixC[s].c = matrixA[i].c;
                matrixC[s].value = matrixA[i].value + matrixB[j].value;

                i++;
                j++;
                s++;


            } else // if columns are not equal
            {
                if (matrixA[i].c < matrixB[j].c) {
                    matrixC[s].r = matrixA[i].r;
                    matrixC[s].c = matrixA[i].c;
                    matrixC[s].value = matrixA[i].value;
                    i++;
                    s++;


                } else {
                    matrixC[s].r = matrixB[j].r;
                    matrixC[s].c = matrixB[j].c;
                    matrixC[s].value = matrixB[j].value;
                    s++;
                    j++;


                }
            }
        } else //   if rows are not equal
        {
            if (matrixA[i].r < matrixB[j].r) {
                matrixC[s].r = matrixA[i].r;
                matrixC[s].c = matrixA[i].c;
                matrixC[s].value = matrixA[i].value;
                i++;
                s++;

            } else {
                matrixC[s].r = matrixB[j].r;
                matrixC[s].c = matrixB[j].c;
                matrixC[s].value = matrixB[j].value;
                s++;
                j++;


            }
        }
    } // end of while
    if (i < t1) {
        for (int p = i; p < t1; p++) {
            matrixC[s].r = matrixA[p].r;
            matrixC[s].c = matrixA[p].c;
            matrixC[s].value = matrixA[p].value;
            s++;

        }
    } else if (j < t2) {
        for (int p = j; p < t2; p++) {
            matrixC[s].r = matrixB[p].r;
            matrixC[s].c == matrixB[p].c;
            matrixC[s].value = matrixB[p].value;

            s++;

        }
    }




    return matrixC;
}

void printMatrixToFile(element* matrix, int size) {
    ofstream ofs;
    ofs.open(matrixCFile.c_str(), ofstream::out);


    for (int i = 0; i < size && matrix[i].r != 0; i++) {


        ofs << matrix[i].r << " " << matrix[i].c;

        if (matrix[i].value != 0.00)

            ofs << " " << setprecision(2) << fixed << matrix[i].value << endl;

        else
            ofs << "" << endl;
    }
    ofs.close();
}






