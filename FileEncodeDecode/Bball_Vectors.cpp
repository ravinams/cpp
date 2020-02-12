#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

int main() {

    vector<int> teamHome;
    vector<int> teamAway;

    int Total1 = 0, Total2 = 0;

    for (int s = 0; s < 4; s++) {
        int input;
        cout << s + 1 << "Q home team score:" << endl;

        while (true) {
            cout << "Please enter an integer 0 or greater: ";
            cin >> input;

            if (input >= 0)
                break;
        }

        teamHome.push_back(input);
        Total1 += input;

        cout << s + 1 << "Q away team score:" << endl;

        while (true) {
            cout << "Please enter an integer 0 or greater: ";
            cin >> input;

            if (input >= 0)
                break;
        }

        teamAway.push_back(input);
        Total2 += input;
    }

    int numberofquarters = 4;

    for (int s = 4; Total1 == Total2; s++) {
        numberofquarters++;
        cout << "It's a tie!" << endl;

        int input;
        cout << s + 1 << "Q home team score:" << endl;

        while (true) {
            cout << "Please enter an integer 0 or greater: ";
            cin >> input;

            if (input >= 0)
                break;
        }

        teamHome.push_back(input);
        Total1 += input;

        cout << s + 1 << "Q away team score:" << endl;

        while (true) {
            cout << "Please enter an integer 0 or greater: ";
            cin >> input;

            if (input >= 0)
                break;
        }

        teamAway.push_back(input);
        Total2 += input;


    }

    cout << endl << left << setw(8) << " ";
    for (int s = 1; s <= numberofquarters; s++)
        cout << s << setw(3) << "Q";
    cout << endl;

    cout << setw(8) << "AWAY";
    for (int s = 0; s < numberofquarters; s++)
        cout << setw(4) << teamAway.pop_back();
    cout << Total2 << endl;

    cout << setw(8) << "HOME";
    for (int s = 0; s < numberofquarters; s++)
        cout << setw(4) << teamHome.pop_back();
    cout << Total1 << endl;

    cout << endl;
    return 0;
}

/* Execution Sample :

1Q home team score:
Please enter an integer 0 or greater: -1
Please enter an integer 0 or greater: 20
1Q away team score:
Please enter an integer 0 or greater: 20
2Q home team score:
Please enter an integer 0 or greater: 20
2Q away team score:
Please enter an integer 0 or greater: 20
3Q home team score:
Please enter an integer 0 or greater: 20
3Q away team score:
Please enter an integer 0 or greater: 20
4Q home team score:
Please enter an integer 0 or greater: 20
4Q away team score:
Please enter an integer 0 or greater: 20
It's a tie!
5Q home team score:
Please enter an integer 0 or greater: 17
5Q away team score:
Please enter an integer 0 or greater: 17
It's a tie!
6Q home team score:
Please enter an integer 0 or greater: 19
6Q away team score:
Please enter an integer 0 or greater: 16

        1Q  2Q  3Q  4Q  5Q  6Q
AWAY    20  20  20  20  17  16  113
HOME    20  20  20  20  17  19  116

Press any key to continue . . .

 */