#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct weatherData {
    double precipitation;
    int maxTemp;
    int minTemp;
};

struct monthWeatherStats {
    int numOfDays;
    double avgMaxTemp;
    double avgMinTemp;
    double avgPrecipitation;
    int rainyDays;
};

monthWeatherStats getWeatherStatsForMonth(int monNum) {
    
    string fileNames[12] = {"01-2016.csv", "02-2016.csv", "03-2016.csv", "04-2016.csv", "05-2016.csv", "06-2016.csv", "07-2016.csv", "08-2016.csv", "09-2016.csv", "10-2016.csv", "11-2016.csv", "12-2016.csv"};
    string currentMonthFileName = fileNames[monNum - 1]; // since array index starts 0 , 0 - January, 1-February .. etc

    ifstream myfile(currentMonthFileName);

    if (!myfile.is_open()) {
        cout << "unable to open the file " << currentMonthFileName;
        exit(-1);
    }

    int numOfDays;
    myfile>>numOfDays; // read the first line ; first line contains 'numOfdays'

    // cout<<"numOfDays = "<<numOfDays<<endl ;
    struct weatherData *wdata = new weatherData[numOfDays];
    string line;
    int arrayIndex = 0;
    getline(myfile, line); // this is just to ignore first line
    while (std::getline(myfile, line)) {
        string precipitation, maxTemp, minTemp;
        std::stringstream ss(line);
        std::getline(ss, precipitation, ',');
        std::getline(ss, maxTemp, ',');
        std::getline(ss, minTemp, ',');

        wdata[arrayIndex].precipitation = stod(precipitation);
        wdata[arrayIndex].maxTemp = stoi(maxTemp);
        wdata[arrayIndex].minTemp = stoi(minTemp);

        arrayIndex++;
    }

    int totalMaxTemp = 0;
    int totalMinTemp = 0;
    double totalPrecipitation = 0;
    int rainyDays = 0;
    for (int i = 0; i < numOfDays; i++) {
        // cout<<wdata[i].precipitation<<" "<<wdata[i].maxTemp<<" "<<wdata[i].minTemp<<endl; ;
        totalMaxTemp = totalMaxTemp + wdata[i].maxTemp;
        totalMinTemp = totalMinTemp + wdata[i].minTemp;
        totalPrecipitation = totalPrecipitation + wdata[i].precipitation;

        if (wdata[i].precipitation > 0)
            rainyDays++;
    }

    // cout<<"totalMaxTemp = "<<setprecision(2) << fixed<<totalMaxTemp<<" totalMinTemp = "<<setprecision(2) << fixed<<totalMinTemp<<" totalPrecipitation = "<<setprecision(2) << fixed<<totalPrecipitation<<" rainyDays ="<<rainyDays<<endl ;

    struct monthWeatherStats monthWeatherStats;
    monthWeatherStats.numOfDays = numOfDays;
    monthWeatherStats.avgMaxTemp = totalMaxTemp / numOfDays;
    monthWeatherStats.avgMinTemp = totalMinTemp / numOfDays;
    monthWeatherStats.avgPrecipitation = totalPrecipitation / numOfDays;
    monthWeatherStats.rainyDays = rainyDays;


   // cout<<"averageHigh = "<<setprecision(2)<<fixed<<monthWeatherStats.avgMaxTemp<<" averageLow = "<<monthWeatherStats.avgMinTemp<<" averageParicipation = "<<monthWeatherStats.avgPrecipitation<<" rainyDays = "<<rainyDays<<endl ;

    delete[] wdata;

    myfile.close();

    return monthWeatherStats;
}

int main() {
    int choice = 1;
    char continueFlag;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    cout << "Welcome to Miami Temperature App.\n" << endl;

    do {
        continueFlag = 'N';

        cout << "Please choose from the following menu options:" << endl;
        cout << "1." <<setw(8)<< months[0] << endl;
        cout << "2." <<setw(9)<< months[1] << endl;
        cout << "3." <<setw(6)<< months[2] << endl;
        cout << "4." <<setw(6)<< months[3] << endl;
        cout << "5." <<setw(4)<< months[4] << endl;
        cout << "6." <<setw(5)<< months[5] << endl;
        cout << "7." <<setw(5)<< months[6] << endl;
        cout << "8." <<setw(7)<< months[7] << endl;
        cout << "9." <<setw(10)<< months[8] << endl;
        cout << "10."<<setw(7)<< months[9] << endl;
        cout << "11."<<setw(8)<< months[10] << endl;
        cout << "12."<<setw(8)<< months[11] << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice :";
        cin>>choice;

        if ( cin.fail() || choice < 0  ||  choice > 12 ) {
            cout << "\nInvalid choice , please choose again \n";
            continueFlag = 'Y';
            cin.clear();
            cin.ignore(256,'\n');
        }

    } while (continueFlag == 'Y');

    if (choice != 0) {
        struct monthWeatherStats monthstats;
        monthstats = getWeatherStatsForMonth(choice);
        cout << "\nDisplaying the statistics for the month of " << months[choice - 1] << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << "Number Days" << setw(15) << "Average High" << setw(15) << "Average Low" << setw(25) << "Average Precipitation" << setw(20) << "Number Rainy days" << endl;
        ;
        cout << setw(5) << monthstats.numOfDays;
        cout << setw(15) << setprecision(2) << fixed << monthstats.avgMaxTemp;
        cout << setw(15) << setprecision(2) << fixed << monthstats.avgMinTemp;
        cout << setw(20) << setprecision(2) << fixed << monthstats.avgPrecipitation;
        cout << setw(20) << monthstats.rainyDays << endl;
        cout << "--------------------------------------------------------------"<<endl;
    }

    return 0;
}
