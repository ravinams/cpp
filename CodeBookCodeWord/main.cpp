
#include <iostream>
#include "generateValue.h"
#include "Mint.h"
#include "Melt.h"
#include "Codeword.cpp" 
#include "Codebook.cpp" 


using namespace std;

//// remove this in final delivery
//
//int generateMint(int seed, int modulus) {
//    
//     srand(seed);
//     return(rand() % modulus) ;
//
//}
//
//// remove this in final delivery
//
//char generateMelt(int seed) {
//
//}

int Mint::modulas = 0;

int main(int argc, char** argv) {

    cout << "The codebook " << endl;
    unsigned int usecase = 1, seed = 1, length = 3, size = 4, modulus = 10;
    if (argc < 5) {
        cout << "Insufficient arguments" << endl;
        cout<<"correct usage : ./CFC <case> <seed> <length> <size> <modulus>"<<endl;
        exit(-1);
    }

    usecase = atoi(argv[1]);
    seed = atoi(argv[2]);
    length = atoi(argv[3]);
    size = atoi(argv[4]);
    if (argc > 5)
        modulus = atoi(argv[5]);

    //    cout << "Case = " << Case << " | seed = " << seed << " | length = " << length << " | size = " << size << " | modulus = " << modulus << endl;


    switch (usecase) {

        case 0: // Mint case

        {
            Mint::modulas = modulus; // dont delete this line , this is how we pass the modulus to Mint class .

//            int arr[4][3] = {
//                {0, 0, 0},
//                {4, 9, 7},
//                {9, 0, 1},
//                {3, 9, 1}
//            };

            Codebook<Codeword < Mint >> mintcb(size);

            for (int i = 0; i < size; i++) {
                Codeword<Mint> mintcw(length);
                for (int j = 0; j < length; j++) {
                    Mint m(generateMint(seed,modulus));
                    mintcw.addSymbol(m);
                }
                mintcb.addCodeword(mintcw);
            }

            mintcb.Display();
            break;
        }

        case 1: // Melt case

        {

//            // Melt case
//            char charArry[4][3] = {
//                {'a', 'a', 'a'},
//                {'k', 'z', 's'},
//                {'y', 'a', 'd'},
//                { 'h', 'z', 'd'}
//            };



            Codebook<Codeword < Melt >> meltcb(size);

            for (int i = 0; i < size; i++) {
                Codeword<Melt> meltcw(length);
                for (int j = 0; j < length; j++) {
                    Melt m(generateMelt(seed));
                    meltcw.addSymbol(m);
                }
                meltcb.addCodeword(meltcw);
            }

            meltcb.Display();

            break;
        }
        default: //Invalid case ;
            cout << "Invalid choice" << endl;
            break;

    }

    return 0;
}

