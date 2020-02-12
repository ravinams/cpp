/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: oracle
 *
 * Created on April 9, 2018, 9:16 PM
 */

#include <cstdlib>
#include <iostream>
#include "RetailItem.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    RetailItem item1, item2, item3;

    std::string d;
    int u;
    double p;


    cout << "Welcome to the Retail store!\n" << endl;

    // input for Item1  .

    do {
        cout << "Price must be greater than 0" << endl;
        cout << "Please enter the price for item 1:";
        cin>>p;
    }    while (p <= 0);

    do {
        cout << "Inventory must be greater than 0" << endl;
        cout << "Please enter the units on hand for item 1:";
        cin>>u;
    } while (u <= 0);

    cout << "Please enter the description for item 1:";
    cin>>d;

    item1.setPrice(p);
    item1.setUnitsOnHand(u);
    item1.setDescription(d);

    // input for Item2  .
    cout<<"\n" ;
    do {
        cout << "Price must be greater than 0" << endl;
        cout << "Please enter the price for item 2:";
        cin>>p;
    }    while (p <= 0);

    do {
        cout << "Inventory must be greater than 0" << endl;
        cout << "Please enter the units on hand for item 2:";
        cin>>u;
    } while (u <= 0);

    cout << "Please enter the description for item 2:";
    cin>>d;

    item2.setPrice(p);
    item2.setUnitsOnHand(u);
    item2.setDescription(d);

    // input for Item3  .
    cout<<"\n" ;
    do {
        cout << "Price must be greater than 0" << endl;
        cout << "Please enter the price for item 3:";
        cin>>p;
    }    while (p <= 0);

    do {
        cout << "Inventory must be greater than 0" << endl;
        cout << "Please enter the units on hand for item 3:";
        cin>>u;
    } while (u <= 0);

    cout << "Please enter the description for item 3:";
    cin>>d;

    item3.setPrice(p);
    item3.setUnitsOnHand(u);
    item3.setDescription(d);

    // display all

    cout << "Display All items" << endl;


    cout << "\nDescription :" << item1.getDescription() << endl;
    cout << "Units on hand:  :" << item1.getUnitsOnHand() << endl;
    cout << "Price :$" << item1.getPrice() << endl;

    cout << "\nDescription :" << item2.getDescription() << endl;
    cout << "Units on hand:  :" << item2.getUnitsOnHand() << endl;
    cout << "Price :$" << item2.getPrice() << endl;

    cout << "\nDescription :" << item3.getDescription() << endl;
    cout << "Units on hand:  :" << item3.getUnitsOnHand() << endl;
    cout << "Price :$" << item3.getPrice() << endl;

    cout << "\nDisplay the total inventory" << endl;
    cout << "The total inventory is " << item1.getUnitsOnHand() + item2.getUnitsOnHand() + item3.getUnitsOnHand();

    return 0;

}

