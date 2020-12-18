/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Tyler C
 *
 * Created on December 18, 2020, 12:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Relacion.h"
#include "Tupla.h"

void loadFileRelaciones();
void listRelations(bool ask);
void seeStatus(int position);
void addTupla();

vector<Relacion*> loadFile(string fileName);
void writeFile(vector<Relacion*>& listRelacion, string fileName);

using namespace std;

/*
 * 
 */
vector<Relacion> listRelaciones;

int main(int argc, char** argv) {
    loadFileRelaciones();
    int mainOption = 0;
    while (mainOption != 4) {
        cout << "Option 1- Crear relacion" << endl <<
                "Option 2- Ver relaciones" << endl <<
                "Option 3- Insertar tupla" << endl << "Option 4- Salir" << endl;
        cout << "Ingrese su option: " << endl;
        cin >> mainOption;
        switch (mainOption) {
            case 1:
            {
                cout << "-----> Data Base <-----" << endl;
                vector<string> Headers;
                string name, headers;
                int cantHeaders;
                cout << "Ingrese el nombre de la relación: ";
                cin >> name;
                cout << "¿Ingrese la cantidad de Headers que desea en su relacion:  ";
                cin >> cantHeaders;
                Headers.push_back("ID");
                cout << "No tienes que poner ID ya esta auto!" <<endl;
                for (int i = 0; i < cantHeaders; i++) {
                    cout << ": ";
                    cin >> headers;
                    Headers.push_back(headers);
                }

                Relacion relacion(name, Headers);
                listRelaciones.push_back(relacion);

                ofstream archiveRelations("allRelations.txt", ios::app);
                archiveRelations << relacion.getName() + " - ";
                for (int i = 0; i < Headers.size(); i++) {
                    if (i == Headers.size() - 1) {
                        archiveRelations << Headers[i] + "\n";
                    } else {
                        archiveRelations << Headers[i] + ",";
                    }
                }

                ofstream otherRelation(name + ".txt", ios::out);
                break;
            }
            case 2:
            {
                listRelations(true);
                break;
            }
            case 3:
            {
                addTupla();
                break;
            }
            case 4:
            {
                mainOption = 4;
                break;
            }
        }
    }
    return 0;
}

void loadFileRelaciones() {
    ifstream fileRelations("allRelations.txt", ios::in);
    if (fileRelations) {
        string name, header, split;
        while (fileRelations >> name >> split >> header) {
            vector<string> headers;
            string headerActual;
            for (int i = 0; i < header.size(); i++) {
                if (header[i] == ',') {
                    headers.push_back(headerActual);
                    headerActual = "";
                } else {
                    headerActual += header[i];
                }
            }
            headers.push_back(headerActual);
            Relacion r(name, headers);

            ifstream fileTupla(name + ".txt", ios::in);
            if (fileTupla) {
                string auxiliary;
                while (fileTupla >> auxiliary) {
                    vector<string> attributes, aux_attributes;
                    string att;
                    for (int i = 0; i < auxiliary.size(); i++) {
                        if (auxiliary[i] == ',') {
                            attributes.push_back(att);
                            att = "";
                        } else {
                            att += auxiliary[i];
                        }
                    }
                    attributes.push_back(att);
                    for (int i = 1; i < attributes.size(); i++) {
                        aux_attributes.push_back(attributes[i]);
                    }

                    Tupla t(stoi(attributes[0]), aux_attributes);
                    r.setTupla(t);
                }
            }

            listRelaciones.push_back(r);
        }
    }
}

void listRelations(bool ask) {
    ifstream archiveRelations("allRelations.txt", ios::in);
    if(!archiveRelations) {
        cout << "No hay ninguna relación hasta el momento." << endl;
    } else {
        cout << "----- Lista de Relaciones en Memoria -----" <<endl;
        int contador = 1;
        string name, headers, split;
        while(archiveRelations >> name >> split >> headers) {
            cout << contador << ". " << name << endl;
            contador++;
        }
        cout << endl;

        if (ask) {
            int posRelation;
            cout << "De que relacion desea ver el estado?: ";
            cin >> posRelation;
            while(posRelation < 1 || posRelation > listRelaciones.size()) {
                cout << "El numero que ingreso no corresponde a las relaciones mostradas en la lista." << endl;
                cout << "Intente de nuevo: ";
                cin >> posRelation;
            }
            seeStatus(posRelation);
        }
    }
}

void seeStatus(int position) {
    Relacion r = listRelaciones[position - 1];
    int n_headers = r.getHeaders().size();
    
    cout << endl<<"Estado de la relacion " << r.getName() << ":" << endl << endl;
    for (int i = 0; i < n_headers; i++) {
        cout << r.getHeaders()[i];
        if (r.getHeaders()[i] == "ID") {
            cout << endl;
        } else {
            cout << "\t\t";
        }
    }
    cout << endl;

    for (int i = 0; i < r.getTuplas().size(); i++) {
        cout << r.getTuplas()[i].toString();
        cout << endl;
    }
}

void addTupla() {
    listRelations(false);
    int posRelation;
    cout << "En que relacion desea ingresar la tupla?: ";
    cin >> posRelation;
    Relacion r = listRelaciones[posRelation - 1];
    vector<string> attributes;
    srand(time(NULL));
    int random = 1000 + rand()%(9998);
    cout << endl <<"Agregando tupla a la relacion " + r.getName() << endl;
    cout << "size: " << r.getHeaders().size() <<endl;
    for (int i = 1; i < r.getHeaders().size(); i++) {
        cout <<"Hello" <<endl;
        string att;
        cout << r.getHeaders()[i] << ": ";
        cin >> att;
        attributes.push_back(att);
    }
    Tupla tupla(random, attributes);
    r.setTupla(tupla);

    ofstream currentFile(r.getName() + ".txt", ios::app);
    currentFile << random << ",";
    for (int i = 0; i < attributes.size(); i++) {
        if (i == attributes.size() - 1) {
            currentFile << attributes[i] + "\n";
        } else {
            currentFile << attributes[i] + ",";
        }
    }
}


