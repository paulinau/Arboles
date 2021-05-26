/*  
    ArbolBinario.hpp
    Autor: Paulina Ugalde Carreño 
    Fecha: 21/11/2020
*/

#include "ArbolBinario.hpp"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

using namespace std; 

Nodo *arbol = NULL;                 //Inicializamos el arbol como vacio

Nodo *crearNodo(int tam, string nom, string ti, string fe){ 
    Nodo *nuevo_nodo = new Nodo();  //Creacion del nodo
    nuevo_nodo->nombre = nom;       //Asignacion de valores a cada atributo
    nuevo_nodo->tipo = ti;
    nuevo_nodo->fecha = fe;
    nuevo_nodo->tamano = tam;
    nuevo_nodo->der = NULL;         //Inicializacion de los punteros a NULL
    nuevo_nodo->izq = NULL;
    return nuevo_nodo;              //Retornamos la posicion del nuevo nodo
}

void insertar(Nodo *&arbol, int tam, string nom, string ti, string fe){ 
    if (arbol == NULL){             // Verificamos si el arbol no esta vacio
        Nodo *nuevo_nodo = crearNodo(tam, nom, ti, fe); //Guardamos nuestros datos en el nodo
        arbol = nuevo_nodo;
    }else{
        int raiz = arbol->tamano;   //Obtenemos el valor de la raiz
        if (tam < raiz)             //Si el nodo a ingresar es de menor tamaño que la raiz...
            insertar(arbol->izq, tam, nom, ti, fe);  //Se inserta el valor en el lado izquierdo
        else
            insertar(arbol->der, tam, nom, ti, fe);  //Se inserta el valor en el lado derecho
    } 
} 

void mostrar(Nodo *arbol, int cont){
    if (arbol == NULL)                  //Verifica si el arbol esta vacio
        return;
    else{
        mostrar(arbol->der, cont + 1);  //Mostramos el arbol
        for (int i = 0; i < cont; i++)
            cout <<"   ";               //Dejamos espacios para que se vea mejor nuestro arbol horizontal
        cout << arbol->tamano << " ";
        cout << arbol->nombre << " ";
        cout << arbol->tipo << " ";
        cout << arbol->fecha << " "<<endl;
        mostrar(arbol->izq, cont + 1);
    } 
}

//Funcion para hacer un recorrido en profundidad - PreOrden
void preOrden(Nodo *arbol){
    if (arbol == NULL)          //Verificamos que el arbol este vacio
        return;
    else{
        cout<<arbol->tamano<<" ";
        cout<<arbol->nombre<<" ";
        cout<<arbol->tipo  <<" ";
        cout<<arbol->fecha << " "<<endl;
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

//Funcion para hacer un recorrido en profundidad - InOrden
void inOrden(Nodo *arbol){
    if (arbol == NULL)
        return;
    else{
        inOrden(arbol->izq);
        cout<<arbol->tamano<< " ";
        cout<<arbol->nombre<< " ";
        cout<<arbol->tipo  << " ";
        cout<<arbol->fecha << " "<<endl;
        inOrden(arbol->der);
    }
}

//Funcion para hacer un recorrido en profundidad - PostOrden
void postOrden(Nodo *arbol){
    if (arbol == NULL)
        return;
    else{
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout<<arbol->tamano<< " ";
        cout<<arbol->nombre<< " ";
        cout<<arbol->tipo  << " ";
        cout<<arbol->fecha << " "<<endl;
    }
}

// Metodo para buscar por tamaño
bool busquedaTamano(Nodo *arbol, int n){
    if (arbol==NULL)           //Verifica si el arbol esta vacio
        return false;
    else if(arbol->tamano==n){
        cout<<"El elemento "<<n<<" ha sido encontrado en el arbol"<<endl;
        cout<<arbol->tamano<< " ";
        cout<<arbol->nombre<< " ";
        cout<<arbol->tipo  << " ";
        cout<<arbol->fecha << " "<<endl;
        return true;
    }else if(n<arbol->tamano)   //Si el dato que buscamos es menor al nodo raiz, busque por la izquierda
        return busquedaTamano(arbol->izq, n);
    else                       //Si el dato que buscamos es mayor al nodo raiz, busque por la derecha
        return busquedaTamano(arbol->der, n);
}

bool busquedaNom(Nodo *arbol, string nom){
    if (arbol == NULL) //Si el arbol esta vacio
        return false;
    else if(arbol->nombre == nom){ //Si el nodo es igual al dato que se busca
        cout<<"El elemento "<<nom<<" ha sido encontrado en el arbol"<<endl;
        cout<<arbol->tamano<< " ";
        cout<<arbol->nombre<< " ";
        cout<<arbol->tipo  << " ";
        cout<<arbol->fecha << " "<<endl;
        return true;
    }else if(nom < arbol->nombre) //Si el dato que buscamos es menor al nodo raiz, busque por la izquierda
        return busquedaNom(arbol->izq, nom);
    else                            //Si el dato que buscamos es mayor al nodo raiz, busque por la derecha
        return busquedaNom(arbol->der, nom);
}

bool busquedaFecha(Nodo *arbol, string fe){
    if (arbol == NULL) //Verifica si el arbol esta vacio
        return false;
    else if (arbol->fecha == fe){ //Si el nodo es igual al dato que se busca
        cout<<"El elemento "<<fe<<" ha sido encontrado en el arbol"<<endl;
        cout<<arbol->tamano<< " ";
        cout<<arbol->nombre<< " ";
        cout<<arbol->tipo  << " ";
        cout<<arbol->fecha << " "<<endl;
        return true;
    }else if (fe < arbol->fecha) //Si el dato que buscamos es menor al nodo raiz, busque por la izquierda
        return busquedaFecha(arbol->izq, fe);
    else //Si el dato que buscamos es mayor al nodo raiz, busque por la derecha
        return busquedaFecha(arbol->der, fe);
}

void menu(){
    int op, contador = 0;
    string nombre, tipo, fecha;
    int tamano;
    do{
        cout<<"*******Menu de opciones.*******\n[1] Insertar nodos.\n[2] Mostrar Nodos.\n[3] Mostrar arbol en Preorden.\n[4] Mostrar arbol en Inorden.\n[5] Mostrar arbol en Postorden.\n[6] Busqueda por nombre.\n[7] Busqueda por tamano.\n[8] Busqueda por fecha\n[9] Salir"<<endl;
        cout<<"Selecciona una opcion: ";
        cin>>op;
        switch(op){
        case 1:
            cout<<"Digite el tamano del archivo: ";  cin>>tamano; cin.ignore();
            cout<<"Digite el nombre del archivo: ";  getline(cin, nombre);   
            cout<<"Digite el tipo de archivo: ";     getline(cin, tipo);     
            cout << "Dgite la fecha: ";              getline(cin, fecha);   
            insertar(arbol, tamano, nombre, tipo, fecha);
            system("pause");
            break;
        case 2:
            mostrar(arbol, contador);   cout << "\n";
            system("pause");
            break;
        case 3:
            cout<<"\n***Recorrido en PreOrden:***\n";
            preOrden(arbol);            cout << "\n";
            system("pause");
            break;
        case 4:
            cout<<"\n***Recorrido en InOrden:***\n";
            inOrden(arbol);             cout<<"\n";
            system("pause");
            break;
        case 5:
            cout<<"\n***Recorrido en PostOrden:***\n";
            postOrden(arbol);           cout<<"\n";
            system("pause");
            break;
        case 6:
            cout<<"Ingresa el nombre del archivo a buscar "; cin>>nombre;
            if(busquedaNom(arbol, nombre) != true)
                cout<<"Elemento no encontrado"<<endl;
            system("pause");
            break;
        case 7:
            cout<<"Ingresa el tamano del archivo a buscar: ";  cin>>tamano;
            if(busquedaTamano(arbol, tamano) != true)
                cout<<"Elemento no encontrado"<<endl;
            system("pause");
            break;
        case 8:
            cout<<"Ingresa la fecha del archivo a buscar: ";  cin>>fecha;
            if(busquedaFecha(arbol, fecha) != true)
                cout<<"Elemento no encontrado"<<endl;
            system("pause");
            break;
        case 9:
            break;
        }
        cout<<endl;
    } while (op!=9);
}