/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Relacion.h
 * Author: Tyler C
 *
 * Created on December 18, 2020, 1:14 PM
 */

#ifndef RELACION_H
#define RELACION_H
#include "Tupla.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

class Relacion {
public:
    Relacion();
    Relacion(string,vector<string>);
    Relacion(const Relacion& orig);
    virtual ~Relacion();
    string getName();
    vector<string> getHeaders();
    void setTupla(Tupla t);
    vector<Tupla> getTuplas();
private:
    vector<string> headers;
    string name;
    vector <Tupla> tuplas;
};

#endif /* RELACION_H */

