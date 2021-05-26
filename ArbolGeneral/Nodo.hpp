/*  
    Nodo.hpp
    Autor: Paulina Ugalde Carreño 
    Fecha: 27/11/2020
*/

#ifndef Nodo_hpp
#define Nodo_hpp
#include <string>
#include <iostream>
#include <list>

using namespace std;
//**********************************************************
class Nodo{
    private:                //Atributos de la clase 
        string dato;
        list<Nodo*> hijos;  
    public:                 //Metodos de la clase
        Nodo(string);
        string getDato();
        list<Nodo*>* getHijos();
        void agregarHijo(Nodo*);
};
//**********************************************************
#endif /* Nodo_hpp*/