/*  
    menu.cpp
    Autor: Paulina Ugalde Carreño 
    Fecha: 27/11/2020
    Programa: Implemente un arbol general donde se permita agregar y eliminar nodos

    Representación del arbol general:
                                                   SABRITAS
                                                       |
                DORITOS-------- RUFFLES -------------- FRITOS ---------------------- CHEETOS
                   |              |                      |                              |
                  ----         --------            --------------         -------------------------------
                   |           |      |            |      |     |         |          |        |         | 
                 ROJOS       QUESO   SAL       CHIPOTLE  SAL   QUESO     BOLITA TORCIDITOS  GARRITA  FLAMMING     
*/

#include "Nodo.hpp"
#include "ArbolGeneral.hpp"
#include <string>
#include <iostream>
using namespace std; 


int main(int argc, const char * argv[]){
    ArbolGeneral* arbol=new ArbolGeneral;
    arbol->agregarNodo("Sabritas","");
    arbol->agregarNodo("Hijo: Doritos", "Sabritas");
    arbol->agregarNodo("Hijo: Ruffles", "Sabritas");
    arbol->agregarNodo("Hijo: Fritos",  "Sabritas");
    arbol->agregarNodo("Hijo: Cheetos", "Sabritas");
    arbol->agregarNodo("Rojos", "Hijo: Doritos");
    arbol->agregarNodo("Queso", "Hijo: Ruffles");
    arbol->agregarNodo("Sal", "Hijo: Ruffles");
    arbol->agregarNodo("Chipotle", "Hijo: Fritos");
    arbol->agregarNodo("Sal", "Hijo: Fritos");
    arbol->agregarNodo("Queso", "Hijo: Fritos");
    arbol->agregarNodo("Bolita", "Hijo: Cheetos");
    arbol->agregarNodo("Torciditos","Hijo: Cheetos");
    arbol->agregarNodo("Garrita","Hijo: Cheetos");
    arbol->agregarNodo("Flamming","Hijo: Cheetos");
    
    arbol->mostrar(arbol->getRaiz(), 1);
    cout<<endl;
    system("pause");

    cout<<"Borraremos al hijo Doritos..."<<endl;
    arbol->elimnarNodo("Hijo: Doritos", arbol->getRaiz(), "Sabritas");
    arbol->mostrar(arbol->getRaiz(), 1);
    cout<<endl;
    system("pause");
    cout<<"Ahora borraremos al Hijo de Cheetos: Bolita...";
    arbol->eliminarNodo("Bolita", arbol->getRaiz());
    arbol->mostrar(arbol->getRaiz(), 1);
    cout<<endl;
    cout<<"Fin del programa "<<endl;
}
