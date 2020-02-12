#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main() {

    string answer;
    int age;
    int number;
    // const int least = 1, highest = 36;
    string color;
    int bet;
    string effort;
    const int restrictionAge = 18;
    int bank = 1000;
    int balance;
    //char sign;
    int totalprofit = 0;
    string black = "b";
    string red = "r";
    int random = 1 + (rand() % 36);
    int gain = 0;
    int spin;
    int playerchoice;
    int loss;
number:
    "n";
color:
    "c";

    string typeofcolor;

    cout << "welcome to Roulette \n" << endl;

    //här frågas om spelaren vill spela.
    cout << "do you want to play? \n" << endl;
    //Genom att svara på ja elller nej
    cout << "answer yes or no (y/n): ";

    cout << endl;

    cin >> answer;

    if (answer == "yes") {

        cout << "continue to play the game" << endl;
    }
        //om spelaren svarar nej till spelet
    else if (answer == "no") {
        //önskar välkomen tillbaka ifall spelaren väljer nej
        cout << "welcome back " << endl;

        exit(0);
    }
    //frågatecknas hur gammal spelaren är 
    cout << "What's your age?" << endl;
    cin >> age;

    if (age < restrictionAge) {
        cout << "Sorry you are too young\n" << endl;

        exit(0);
    }

    cout << endl;

    cout << "how much would you like to bet? You can only bet 100,300,500 \n" << endl;

    cout << "You have 1000kr to play for" << endl;

    cin >> bet;


    while (bet != 100 && bet != 300 && bet != 500) {

        cout << "please choose your bet" << endl;
        cin >> bet;

    }

    if (bet == 100 && bet == 300 && bet == 500) {



    }
    cout << "choose between a number or a color " << endl;

    cin >> effort;

    if (effort == "c") {
        cout << "you have choosen color" << endl;

        cout << " which color would you like to bet" << endl;
        cout << " r for red and b for black";
        cin >> playerchoice;

        string black = "b";

        srand(time(0));
        spin = rand() % 36 + 1;
        if (playerchoice = 'b') {
            cout << "you have choosen black" << endl;


            if (spin % 2 == 0) {

                //computerchoice = 1;

                //cout << "Datorn valde rött";
                cout << " you won kr " << 2 * bet << "." << endl;
                bank = bank + (2 * bet);
                cout << "you have now" << bank << endl;
            }
            else {
                // computerchoice = 2;
                bank = bank + (2 * bet);
                cout << " you lose";
                cout << "your amount now is " << bank << endl;

            }
        }
        else if (playerchoice = 'r')
 {
            cout << "you have choosen red" << endl;


            if (spin % 2 == 0) {

                // computerchoice = 1;

                //cout << "Datorn valde rött";
                cout << " you won kr " << 2 * bet << "." << endl;
                bank = bank + (2 * bet);
                cout << "you have now" << bank << endl;
            }
            else {
                // computerchoice = 2;
                bank = bank + (2 * bet);
                cout << " you lose";
                cout << "your amount now is " << bank << endl;

            }

        }
        //cin >> typeofcolor;
        //cin >> typeofcolor;

    } else if (playerchoice == 'n') {

        cout << "you have choosen red color" << endl;

    }
    else {
        cout << "you chosen wrong letter \n" << endl;

    }

    cout << "you have choosen number \n" << endl;

    cout << " choose a number between 1-36";
    cin >> number;

    while (number < 0 || number > 36)
 {

        cout << "you choose wrong number " << endl;

        cin >> number;

    }

    while (number > 0 || number < 36)
 {
        cout << "you have choosen number " << number << endl;




        //int random = 1 + (rand () % 36);
        //cout << "the number is " << random << ".";

        //if (random % 2 == 0 ) {
        //gain = balance + balance + bank;
        //cout << "you have won! " : "; cout << gain; cout << "you got money !";

    }
    //srand (time(0));
    //cout << "the wheel is spinning"  << endl;
    //cout << "the random that come up" << random << endl;

}
// if (number >1 && number >=36)


//cout << rand() % 36 + 1 << endl;
// {









