//
// Created by administrador on 1/10/24.
//

#include <iostream>
#include "Iterador.h"
#include "Nodo.h"



#ifndef PR3_DEFINITIVO_LISTADENLAZADA_H
#define PR3_DEFINITIVO_LISTADENLAZADA_H

template <class T>
class ListaDEnlazada{
private:
    Nodo<T> *cabecera, *cola;
    int numelementos = 0;
public:
    ListaDEnlazada();
    ListaDEnlazada(const ListaDEnlazada<T>& origen);
    ~ListaDEnlazada();
    Iterador<T> iterador() const;
    T& inicio();
    T& fin();
    int tam();
    void inserta(Iterador<T>& i, T& dato);
    void insertarInicio(T& dato);
    void insertarFin(T& dato);
    void borra(Iterador<T>& i);
    void borraInicio();
    void borraFinal();
    ListaDEnlazada<T>& operator=(ListaDEnlazada& otra_list);

};


template<class T>
ListaDEnlazada<T>::ListaDEnlazada(): cabecera(0),
                                     cola(0)
{

}


template<class T>
ListaDEnlazada<T>::ListaDEnlazada(const ListaDEnlazada& origen): cabecera(nullptr),
                                                                 cola(nullptr)
{
    if(origen.cabecera == nullptr){
        return;
    };

    Iterador<T> it = origen.iterador();
    while(it.haySiguiente()) {
        Nodo <T>* nuevo = new Nodo<T>(it.dato(), it.getAnterior(), it.getSiguiente());

        if(cabecera == nullptr){
            cabecera = nuevo;
            cola = nuevo;
        }else{
            cola->sig = nuevo;
            nuevo->ant = cola;

            cola = nuevo;
        }
        it.siguiente();
    }
}


template<class T>
ListaDEnlazada<T>& ListaDEnlazada<T>::operator=(ListaDEnlazada& otra_list){
    this->cabecera = otra_list.cabecera;
    this->cola = otra_list.cola;
}


template<class T>
T& ListaDEnlazada<T>::inicio() {
    Nodo<T> *nodo = cabecera;

    return nodo->dato;
}


template<class T>
T& ListaDEnlazada<T>::fin() {
    Nodo<T> *nodo = cola;

    return nodo->dato;
}


template<class T>
Iterador<T> ListaDEnlazada<T>::iterador() const{
    return Iterador<T>(cabecera);
}

template<class T>
void ListaDEnlazada<T>::insertarInicio(T &dato) {
    Nodo<T> *nuevo;
    nuevo = new Nodo<T>(dato, 0, cabecera);

    if (cola == nullptr){
        cola = nuevo;
    };

    if (cabecera != nullptr){
        cabecera->ant = nuevo;
    }
    cabecera = nuevo;

    numelementos++;

}


template<class T>
void ListaDEnlazada<T>::insertarFin(T &dato) {
    Nodo<T> *nuevo;
    nuevo = new Nodo<T>(dato, cola, 0);

    if (cabecera == 0){
        cabecera = nuevo;
    }

    if (cola != 0){
        cola->sig = nuevo;
    }

    cola = nuevo;

    numelementos++;

}


template<class T>
void ListaDEnlazada<T>::inserta(Iterador<T>& i, T& dato) {
    Nodo<T>* actual = i.getNodo();
    if (actual == nullptr) throw std::invalid_argument("Iterador no válido");

    Nodo<T>* nuevo = new Nodo<T>(dato, actual->ant, actual);

    if (actual->ant != nullptr) {
        actual->ant->sig = nuevo;
    } else {
        cabecera = nuevo;
    }
    actual->ant = nuevo;
    numelementos++;
}


template<class T>
void ListaDEnlazada<T>::borraInicio() {
    if (cabecera == nullptr) return;

    Nodo<T>* borrado = cabecera;
    cabecera = cabecera->getSiguiente();

    if (cabecera != nullptr) {
        cabecera->ant = nullptr;
    } else {
        cola = nullptr;
    }

    delete borrado;
    numelementos--;
}


template<class T>
void ListaDEnlazada<T>::borraFinal() {
    if (cola == nullptr) return;

    Nodo<T>* borrado = cola;
    cola = cola->getAnterior();

    if (cola != nullptr) {
        cola->sig = nullptr;
    } else {
        cabecera = nullptr;
    }

    delete borrado;
    numelementos--;
}


template<class T>
void ListaDEnlazada<T>::borra(Iterador<T>& i) {
    Nodo<T>* actual = i.getNodo();
    if (actual == nullptr) throw std::invalid_argument("Iterador no válido");

    if (actual->getAnterior() != nullptr) {
        actual->getAnterior()->sig = actual->getSiguiente();
    } else {
        cabecera = actual->getSiguiente();
    }

    if (actual->getSiguiente() != nullptr) {
        actual->getSiguiente()->ant = actual->getAnterior();
    } else {
        cola = actual->getAnterior();
    }

    delete actual;
    numelementos--;
}


template<class T>
int ListaDEnlazada<T>::tam() {
    return numelementos;
}


template<class T>
ListaDEnlazada<T>::~ListaDEnlazada() {
    while (cabecera != nullptr) {
        Nodo<T>* borrado = cabecera;
        cabecera = cabecera->getSiguiente();
        delete borrado;
    }
    cola = nullptr;
    numelementos = 0;
}


#endif //PR2_EEDD_LISTADENLAZADA_H

