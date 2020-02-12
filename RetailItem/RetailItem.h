/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RetailItem.h
 * Author: oracle
 *
 * Created on April 9, 2018, 9:17 PM
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H

#include <string>

class RetailItem {
private:

    std::string description;
    int unitsOnHand;
    double price;

public:
    RetailItem();
    RetailItem(std::string descr, int units, double pric);

    std::string getDescription();
    void setDescription(std::string descr);
    

    int getUnitsOnHand();
    void setUnitsOnHand(int units );

    double getPrice();
    void setPrice(double pric);

};


#endif /* RETAILITEM_H */

