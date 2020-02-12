/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"RetailItem.h"
#include <iostream>

using namespace std;

RetailItem::RetailItem() {
    description = "";
    unitsOnHand = 0;
    price = 0.0;
}

RetailItem::RetailItem(string descr, int units, double pric) {
    description = descr;
    unitsOnHand = units;
    price = pric;
}

string RetailItem::getDescription() {
    return description;
}

void RetailItem::setDescription(string descr) {
    description = descr;
}

int RetailItem::getUnitsOnHand() {
    return unitsOnHand;
}

void RetailItem::setUnitsOnHand(int units) {
    unitsOnHand = units;
}

double RetailItem::getPrice() {
    return price;
}

void RetailItem::setPrice(double pric) {
    price = pric;
}