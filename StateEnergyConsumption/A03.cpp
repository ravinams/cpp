//
// Name: YOUR_FIRST_NAME & YOUR_LAST_NAME
// SSID: YOUR_STUDENT_ID
// Assignment #: ASSIGNMENT_NUMBER
// Submission Date: DATE_YOU_SUBMIT
//
// Description of program: 
//


#include <cstdlib>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

/*
 * 
 */
// sec = state energy consumption 

struct sec {
    string name;
    double coal;
    double naturalGas;
    double petrolem;
    double nuclear;
    double otherRenewables;
    double solar;
    double wind;

};

void ReadData(ifstream & ifs, struct sec sc[], int size) {
    std::string line;
    std::getline(ifs, line); // ignore the header line ;
    int recNum = 0;
    string state;
    string c, ng, fo, jf, hgl, mg, rfo, nep, hep, ww, fe, gt, s, w;
    double totlConsumption = 0.0;

    while (std::getline(ifs, line)) {
        stringstream ss(line);
        totlConsumption = 0.0;
        // ss >> state >> c >> ng >> fo >> jf >> hgl >> mg >> rfo >> nep >> hep >> ww >> fe >> gt>>s>>w  ;
        // cout<<recNum <<" -->"<<line << endl;
        
        getline(ss, state, ',');  // state
        getline(ss, c, ',');  // coal
        getline(ss, ng, ','); // natural gas 
        getline(ss, fo, ','); 
        getline(ss, jf, ',');
        getline(ss, hgl, ',');
        getline(ss, mg, ',');
        getline(ss, rfo, ',');
        getline(ss, nep, ',');
        getline(ss, hep, ',');
        getline(ss, ww, ',');
        getline(ss, fe, ',');
        getline(ss, gt, ',');
        getline(ss, s, ',');
        getline(ss, w, ',');

        totlConsumption = atof(c.c_str()) + atof(ng.c_str()) + atof(fo.c_str()) + atof(jf.c_str()) + atof(hgl.c_str()) + atof(mg.c_str()) + atof(rfo.c_str()) + atof(nep.c_str()) + atof(hep.c_str()) + atof(ww.c_str()) + atof(fe.c_str()) + atof(gt.c_str()) + atof(s.c_str()) + atof(w.c_str());
        // totlConsumption = atof(c.c_str()) ;



        sc[recNum].name = state;
        sc[recNum].coal = ((atof(c.c_str()) / totlConsumption) * 100);
        sc[recNum].naturalGas = (atof(ng.c_str()) / totlConsumption) * 100;
        // petroleum: Fuel Oil + Jet Fuel + HGL Other + Motor Gasoline + Residual Fuel Oil
        sc[recNum].petrolem = ((atof(fo.c_str()) + atof(jf.c_str()) + atof(hgl.c_str()) + atof(mg.c_str()) + atof(rfo.c_str())) / totlConsumption) * 100;
        sc[recNum].nuclear = (atof(nep.c_str()) / totlConsumption) * 100;
        // other renewables: Hydroelectric Power + Wood and Waste + Fuel Ethanol + Geothermal
        sc[recNum].otherRenewables = ((atof(hep.c_str()) + atof(ww.c_str()) + atof(fe.c_str()) + atof(gt.c_str())) / totlConsumption) * 100;
        sc[recNum].solar = (atof(s.c_str()) / totlConsumption) * 100;
        sc[recNum].wind = (atof(w.c_str()) / totlConsumption) * 100;

        recNum++;

    }
}

void displayData(string stateName, struct sec sc[], int size) {
    bool stateNotExists = true;
    for (int i = 0; i < size; i++) {
        if (stateName.compare(sc[i].name) == 0) {

            cout << "Coal: " << setprecision(2) << sc[i].coal << "%" << endl;
            cout << "Natural Gas: " << setprecision(2) << sc[i].naturalGas << "%" << endl;
            cout << "Petroleum: " << setprecision(2) << sc[i].coal << "%" << endl;
            cout << "Nuclear: " << setprecision(2) << sc[i].nuclear << "%" << endl;
            cout << "Other Renewables: " << setprecision(2) << sc[i].otherRenewables << "%" << endl;
            cout << "Solar: " <<setprecision(2) << sc[i].solar << "%" << endl;
            cout << "Wind: " << setprecision(2) << sc[i].wind << "%" << endl;


            // record found ,no need to continue with further looping 
            stateNotExists = false;
            break;
        }

    }

    if (stateNotExists) {
        cout << "The Given state name does not exists" << endl;
    }


}

int main(int argc, char** argv) {
    int size = 51;
    struct sec s[size];
    string stateName;

    std::ifstream dataFile("Data2016.csv");
    if (!dataFile.is_open()) {
        cout << "Unable to open the file";
        exit(1);
    }

    // This will read the file into structure 
    ReadData(dataFile, s, size);

    do {
        cout << "\nEnter a statename or 'q' to exit:" << endl;
        cin>>stateName;

        if (stateName != "q") {
            displayData(stateName, s, size);
        }

    } while (stateName != "q");

    cout << "Gudbye" << endl;

    return 0;
}

