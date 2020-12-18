/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Relacion.cpp
 * Author: Tyler C
 * 
 * Created on December 18, 2020, 1:14 PM
 */

#include "Relacion.h"

Relacion::Relacion() {
}
Relacion::Relacion(string name, vector<string> headers) {
    this->name = name;
    this->headers = headers;
}

Relacion::Relacion(const Relacion& orig) {
}

Relacion::~Relacion() {
}

string Relacion::getName(){
    return this->name;
}

vector<string> Relacion::getHeaders() {
    return this->headers;
}

void Relacion::setTupla(Tupla newTupla) {
    tuplas.push_back(newTupla);
}

vector<Tupla> Relacion::getTuplas() {
    return this->tuplas;
}
