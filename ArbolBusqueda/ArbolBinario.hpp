/*  
    ArbolBinario.hpp
    Autor: Paulina Ugalde Carreño 
    Fecha: 21/11/2020
*/

#ifndef ArbolBinario_hpp
#define ArbolBinario_hpp

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<string>

using namespace std;

class Nodo{
    public:                     //Atributos de la clase nodo
    string nombre, tipo, fecha;
    int tamano;
    Nodo *der;                  //Apuntador al nodo derecho
    Nodo *izq;                  //Apuntador al nodo izquierdo
};

Nodo *crearNodo(int, string, string, string);           //Metodo para crear el nodo
void insertar(Nodo *&, int, string, string, string );   //Metodo para insertar los datos en el arbol
void mostrar(Nodo *,int);                               //Metodo para mostrar el arbol
void menu();                                            //Menu de opciones
bool busquedaNombre(Nodo *, string);
bool busquedaFecha(Nodo *, string);
bool busquedaTamano(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);

#endif /* ArbolBinario_hpp */