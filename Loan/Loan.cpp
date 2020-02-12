#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string userInput ;
    cout << "Would you like to take out loan ?? \n";
    getline(cin, userInput);
    cout << "You entered: " << userInput << endl << endl;
    return 0;
}