#include "Codebook.h"

template <typename T>
Codebook<T>::Codebook() {
    numOfCodewords = 0;
    cnt = 0;
    codeword = nullptr;
    distanceMtrix = nullptr;
}

template <typename T>
Codebook<T>::Codebook(int n) {
    numOfCodewords = n;
    cnt = 0;
    codeword = new T[n];


    distanceMtrix = new int* [numOfCodewords];
    // Create a row for every pointer 
    for (int i = 0; i < numOfCodewords; i++) {
        distanceMtrix[i] = new int[numOfCodewords];
        for (int j = 0; j < numOfCodewords; j++)
            distanceMtrix[i][j] = 0;
    }

}

template <typename T>
Codebook<T>::~Codebook() {
    //   if (codeword != nullptr)
    //        delete[] codeword;

    numOfCodewords = 0;
    cnt = 0;
    codeword = nullptr;
}

template <typename T>
int Codebook<T>::addCodeword(const T &cw) {
    if (cnt < numOfCodewords) {
        codeword[cnt++] = cw;
        return 1;
    }

    return 0;
}

template <typename T>
int Codebook<T>::minimumWeight() {

    int min = codeword[1].Weight();
    for (int i = 1; i < numOfCodewords; i++) {
        if (codeword[i].Weight() < min)
            min = codeword[i].Weight();

    }
    return min;
}

template <typename T>
void Codebook<T>::calcDistance() {

    for (int m = 0; m < numOfCodewords; m++) {
        for (int n = 0; n < numOfCodewords; n++)
            distanceMtrix[m][n] = codeword[m].Distance(codeword[n]);
    }

}

template <typename T>
int Codebook<T>::minimumDistance() {

    int min = distanceMtrix[0][0];
    for (int i = 0; i < numOfCodewords; i++)
        for (int j = 0; j < numOfCodewords; j++)
        {   if (min ==0 && distanceMtrix[i][j] !=0)
              min = distanceMtrix[i][j] ;
           else if (distanceMtrix[i][j]!=0 && distanceMtrix[i][j] < min)
               min = distanceMtrix[i][j];
        }
    return min;
}

template <typename T>
void Codebook<T>::Display() {

    for (int i = 0; i < numOfCodewords; i++) {
        codeword[i].Display();
    }
    cout << endl << "Minimum Weight : " << minimumWeight() << endl;

    calcDistance();
    cout << endl << "The distance matrix" << endl << endl;
    for (int i = 0; i < numOfCodewords; i++) {
        for (int j = 0; j < numOfCodewords; j++)
            cout << distanceMtrix[i][j] << " ";
        cout << endl;
    }

    cout<<endl<<"Minimum distance: "<<minimumDistance()<<endl;

}



