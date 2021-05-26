/*  
    ArbolGeneral.hpp
    Autor: Paulina Ugalde Carreño 
    Fecha: 27/11/2020
*/

#ifndef ArbolGeneral_hpp
#define ArbolGeneral_hpp
#include "Nodo.hpp"
#include <iostream>
#include <string>

using namespace std;
//**********************************************************
class ArbolGeneral{
    private:
        Nodo* raiz;
    public:
        ArbolGeneral();                             //constructor
        Nodo* getRaiz();                            //Método para obtener la raiz 
        void setRaiz(Nodo*);                        //Método para establecer la raiz 
        void agregarNodo(string, string);           //Nodo hijo, Nodo padre
        void elimnarNodo(string, Nodo*, string);    //dato a eliminar, nodo referencia, nodo nuevo padre
        void eliminarNodo(string, Nodo*);           //dato a eliminar, nodo refrencia
        void mostrar(Nodo*, int);                   //Método para mostrar el Arbol
        Nodo* buscar(string, Nodo*);                //Método para buscar un Nodo
        Nodo* buscarPadre(string, Nodo*);           //Método para buscar su padre
};
//**********************************************************
#endif /*ArbolGeneral_hpp*/