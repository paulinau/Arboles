/*  
    ArbolGeneral.cpp
    Autor: Paulina Ugalde Carreño 
    Fecha: 27/11/2020
*/

#include "ArbolGeneral.hpp"
#include "Nodo.hpp"
#include <iostream>
#include <string>
using namespace std;

//**********************************************************
ArbolGeneral::ArbolGeneral(){
    this->raiz=NULL;            //inicializa la raiz como nula
}
//**********************************************************
Nodo* ArbolGeneral::getRaiz(){
    return this->raiz;          //retorna la raiz
}
//**********************************************************
void ArbolGeneral::setRaiz(Nodo* primero){
    this->raiz= primero;        //se establece la raiz 
}
//**********************************************************
void ArbolGeneral::agregarNodo(string hijo, string padre){      //Método para agregar el Nodo
    Nodo* nuevoNodo;
    if(this->raiz == NULL){         //Si la raiz es nula, significa que no hay arbol
        nuevoNodo = new Nodo(hijo); //por lo que el primer dato que obtengamos sera nuestra rai<
        this->raiz = nuevoNodo;
    }else{                          //Si ya tenemos nuestro arbol
        Nodo* padreNodo = buscar(padre, this->raiz);    //Buscaremos al papa del nodo a agregar
        if(padreNodo != NULL){                          //si lo encontramos, agregamos a su hijo
            nuevoNodo = new Nodo(hijo);
            padreNodo->agregarHijo(nuevoNodo);          
        }else                                           //sino, no puede nacer su hijo):
            cout<<"No exite: "<<padre<<", por lo que no puede nacer: "<<hijo<<endl;
    }
}
//**********************************************************
void ArbolGeneral::elimnarNodo(string objetivo, Nodo* n, string nuevoPadre){    //Metodo para eliminar un Nodo
    //En el caso de que el nodo a eliminar sea hermano y tenga hijos:
    //buscamos el nodo a eliminar, a su papa y el nuevo papa (que en este caso seria la raiz)
    Nodo* nodoEliminar;
    nodoEliminar=buscar(objetivo, n);
    Nodo* nodoPadre;
    nodoPadre=buscarPadre(objetivo, n);
    Nodo* padreNuevo;
    padreNuevo=buscar(nuevoPadre, this->raiz);
    
    list<Nodo*>* listasolita;               //instanciamos nuestra lista
    listasolita=nodoEliminar->getHijos();   //obtenemos a sus hijos
    cout<<"Eliminando a "<< nodoEliminar->getDato()<<" hijo de:  "<<nodoPadre->getDato()<<endl;
    cout<<"Los hijos ahora seran hijos de: "<<padreNuevo->getDato()<<endl;

    //Le asignamos a su nuevo papa 
    list<Nodo*>::iterator iterator;
    iterator=listasolita->begin();
    Nodo* aux;
    while (iterator != listasolita->end()){
        aux=*iterator;
        cout<<"Moviendo Nodo: "<<aux->getDato()<<"...";
        padreNuevo->agregarHijo(aux);
        iterator++;
    }

    iterator=nodoPadre->getHijos()->begin();
    while (iterator != nodoEliminar->getHijos()->end()){
        aux=*iterator;
        if(aux==nodoEliminar){
            nodoPadre->getHijos()->erase(iterator);
            cout<<"Elimiacion completa"<<endl;
            break;
        }
        iterator++;       
    }
}
//**********************************************************
void ArbolGeneral::eliminarNodo(string objetivo, Nodo*n){  //Metodo para eliminar el Nodo
    //buscamos el nodo a eliminar, a su papa y el nuevo papa
    Nodo* nodoEliminar;
    nodoEliminar=buscar(objetivo, n);
    Nodo* nodoPadre;
    nodoPadre=buscarPadre(objetivo, n);
    list<Nodo*>::iterator iterator;
    iterator=nodoPadre->getHijos()->begin();    //obtenemos a sus hijos
    Nodo* aux;
    while (iterator != nodoPadre->getHijos()->end()){       //recorrido de lista de hijos
        aux=*iterator;
        if(aux==nodoEliminar){
            nodoPadre->getHijos()->erase(iterator);
            cout<<"Eliminacion completa"<<endl;
            break;
        }
        iterator++;
    }
}
//**********************************************************
void ArbolGeneral::mostrar(Nodo* auxN, int nivel){          //Mostramos el arbol
    if(auxN != NULL){
        cout<<auxN->getDato()<<endl;
        list<Nodo*>::iterator it;
        it= auxN->getHijos()->begin();
        Nodo* aux;
        while (it != auxN->getHijos()->end()){
            for (size_t i = 0; i < nivel; i++)
                cout<<"\t";
            mostrar(*it, nivel+1);
            it++;
        }
    }
}
//**********************************************************
Nodo* ArbolGeneral::buscar(string bus, Nodo* n){        //Método para buscar el nodo solicitado 
    if(n !=NULL){
        if(n->getDato()==bus)
            return n;
        else{
            if(n->getHijos()->size()==0)
                return NULL;
            else{
                list<Nodo*>::iterator iter;
                iter=n->getHijos()->begin();
                Nodo* aux; 
                while (iter != n->getHijos()->end()){   //Analiza los hijos de n
                    aux=*iter;
                    if(aux->getDato()==bus)
                        return aux;
                    else
                        iter++;
                }
                Nodo* aux2;
                iter=n->getHijos()->begin();
                while (iter != n->getHijos()->end()){   //Analiza los hijos de los hijos
                    aux=*iter;
                    if(aux->getHijos()->size()==0)
                        iter++;
                    else{
                        aux2=buscar(bus, aux);//
                        if(aux2->getDato()==bus)
                            return aux2;
                        else
                            iter++;
                    }
                }
            }   
        }
    }else
        return NULL;
}
//**********************************************************
Nodo* ArbolGeneral::buscarPadre(string bus, Nodo* n){       //Método para buscar el padre de un Nodo
    if(n !=NULL){
        if(n->getDato()==bus)
            return n;
        else{
            if(n->getHijos()->size()==0)
                return NULL;
            else{
                list<Nodo*>::iterator iter;
                iter=n->getHijos()->begin();
                Nodo* aux;
                                                            //analiza cada hijo de n
                while (iter != n->getHijos()->end()){
                    aux=*iter;
                    if(aux->getDato()==bus)
                        return n;
                    else
                        iter++;
                }
                Nodo* aux2;
                iter=n->getHijos()->begin();
                                                            //analiza los nietos de n
                while (iter != n->getHijos()->end()){
                    aux=*iter;
                    if(aux->getHijos()->size()==0)
                        iter++;
                    else{
                        aux2=buscar(bus, aux);//
                        if(aux2->getDato()==bus)
                            return aux;
                        else
                            iter++;
                    }
                }
            }
        }
    }else
        return NULL;
}
//**********************************************************