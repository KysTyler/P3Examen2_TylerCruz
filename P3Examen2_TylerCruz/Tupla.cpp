/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tupla.cpp
 * Author: Tyler C
 * 
 * Created on December 18, 2020, 1:17 PM
 */

#include "Tupla.h"

Tupla::Tupla() {
}

Tupla::Tupla(const Tupla& orig) {
}

Tupla::~Tupla() {
}

Tupla :: Tupla(int id, vector<string> att) {
    this->ID = id;
   this-> Atributes = att;
}

string Tupla :: toString() {
    string attributes;
    attributes += to_string(ID);
    attributes += "\t";
    for (int i = 0; i < Atributes.size(); i++) {
        attributes += Atributes[i];
        attributes += "\t\t";
    }
    return attributes;
}

