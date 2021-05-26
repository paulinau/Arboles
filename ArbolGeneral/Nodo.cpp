/*  
    Nodo.cpp
    Autor: Paulina Ugalde Carreño 
    Fecha: 27/11/2020
*/

#include "Nodo.hpp"
#include <list>
#include <string>
#include <iostream>

using namespace std;
//**********************************************************
Nodo::Nodo(string n){                   //Constructor
    this->dato=n;
}
//**********************************************************
string Nodo::getDato(){                 //Obtencion del Dato
return this->dato;
};
//**********************************************************
list<Nodo*>* Nodo::getHijos(){          //Obtencion de la lista de hijos
    list<Nodo*>* auxH=&this->hijos; 
    return auxH;
};
//**********************************************************
void Nodo::agregarHijo(Nodo* a){        //Método para agregar hijos
    this->hijos.push_back(a);           //se agrega a la lista
}