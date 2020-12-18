/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tupla.h
 * Author: Tyler C
 *
 * Created on December 18, 2020, 1:17 PM
 */

#ifndef TUPLA_H
#define TUPLA_H
#include <vector>
#include <string>
#include <iomanip>
using std::string;
using std::vector;
using namespace std;

class Tupla {
public:
    Tupla();
    Tupla(const Tupla& orig);
    virtual ~Tupla();
    
    Tupla(int, vector<string>);
        string toString();
private:
    int ID;
    vector<string> Atributes;
};

#endif /* TUPLA_H */

