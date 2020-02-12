#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void readData();

void writeData();


//Define Variables
double loanAmount, interestRate, loanLength, monthlyPayment, totalAmount,
interestPercent, newLength;

int choice = -1;

float newTotal;

char read = 'Y';

string FileName = "Loan_data.txt";

int main() {

    //Display message on screen and gather information from user.

    cout << "Welcome to the myBank loan calculator\n";

    cout << "\n";


    do {

        cout<<"\n\n ...................\n";
        cout <<
                "Press '1' for load the existing loan\n";

        cout <<
                "Press '2' for create new loan \n";

        cout <<
                "Press '3' to exit the program \n";

        cin >> choice;

        if (choice == 1)
            readData();
        else if (choice == 2)
            writeData();
        else if (choice == 3)
            return 0;
        else
            cout << "Invalid choice :" << endl;


    } while (true);



}


//function to calculate payments with desired loan length

double payment() {

    cout << "\nPlease enter the loan amount.";

    cin >> loanAmount;


    cout << "\nPlease enter the interest rate.";

    cin >> interestRate;

    interestPercent = interestRate / 100;


    cout << "\nPlease enter the length of the loan.";

    cin >> loanLength;


    //Calculate and display monthly payment
    totalAmount = (loanAmount * interestPercent) + loanAmount;

    monthlyPayment = totalAmount / loanLength;

    cout << "Congratulations, your monthly payments are $" << monthlyPayment
            << ".\n\n";

    cout << "\n";

    return 0;

}




//function to write data

void
writeData(void) {

    std::ofstream outfile;
    outfile.open(FileName.c_str(), std::ios_base::app);
    char ch = 'N';


    do {

        cout << "\nPlease enter the loan amount.";

        cin >> loanAmount;


        cout << "\nPlease enter the interest rate.";

        cin >> interestRate;

        interestPercent = interestRate / 100;


        cout << "\nPlease enter the length of the loan.";

        cin >> loanLength;


        //Calculate and display monthly payment
        totalAmount = (loanAmount * interestPercent) + loanAmount;

        monthlyPayment = totalAmount / loanLength;

        cout << "Congratulations, your monthly payments are $" << monthlyPayment
                << ".\n\n";

        outfile << loanAmount << "," << interestRate << "," << loanLength << "," << monthlyPayment << "\n";

        cout << "Do you want create another  loan (Y/y) ? ";
        cin>>ch;

    } while (ch == 'Y' || ch == 'y');

    outfile.close();
}

//function to read data

void
readData(void) {

    ifstream myfile(FileName.c_str());
    string line;

    if (myfile.is_open()) {

        int recordCount = 1; //keep track of the number of records read
        //set character to use as a line between record displays	
        string recBreaks = "";
        recBreaks.assign(20, '-');

        while (getline(myfile, line)) {
            // cout << recBreaks << endl;
            // cout << "record # " << recordCount++ << endl;

            // cout << line << endl;
            std::istringstream ss(line);
            std::string fieldBuffer;
            int fieldCount = 1; //keep track of the number of fields read
            while (std::getline(ss, fieldBuffer, ',')) {
                // std::cout << token <<"----";

                //display the field
                switch (fieldCount) {
                    case 1:
                        cout << recBreaks << endl;
                        cout << "record # " << recordCount++ << endl;
                        cout << "Loan Amount = ...." << fieldBuffer << endl;
                        break;
                    case 2:
                        cout << "Interest rate= .." << fieldBuffer << endl;
                        break;
                    case 3:
                        cout << "Length of loan = " << fieldBuffer << endl;
                        break;
                    case 4:
                        cout << "monthly payments =" << fieldBuffer << endl;
                        break;

                }
                fieldCount++;
            }
        }

        myfile.close();
    }
}

