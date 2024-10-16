//
// Created by administrador on 1/10/24.
//

#include <iostream>
#include "Nodo.h"


#ifndef PR3_DEFINITIVO_ITERADOR_H
#define PR3_DEFINITIVO_ITERADOR_H

template<class T>
class Iterador{
private:
    Nodo<T> *nodo;
    //friend class ListaDEnlazada;
public:
    explicit Iterador(Nodo<T> *Nodo);
    bool hayAnterior();
    bool haySiguiente();
    void siguiente();
    void anterior();
    Nodo<T>* getSiguiente();
    Nodo<T>* getAnterior();
    T& dato();
    Nodo<T> *getNodo() {
        return nodo;   }
    T& operator*();
    Iterador& operator++ ();
    Iterador& operator-- ();
};


template<class T>
Iterador<T>::Iterador(Nodo<T> *Nodo): nodo(Nodo)
{

}


template<class T>
bool Iterador<T>::hayAnterior() {
    return nodo->ant != nullptr;
}


template<class T>
bool Iterador<T>::haySiguiente() {
    return nodo->sig != nullptr;
}


template<class T>
Nodo<T>* Iterador<T>::getSiguiente(){
    if(haySiguiente()){
        return nodo -> sig;
    }
    throw std::out_of_range("No hay más elementos");
}


template<class T>
Nodo<T>* Iterador<T>::getAnterior(){
    if(hayAnterior()){
        return nodo -> ant;
    }
    throw std::out_of_range("No hay más elementos");
}


template<class T>
void Iterador<T>::anterior(){
    nodo = nodo ->ant;
}


template<class T>
void Iterador<T>::siguiente(){
    nodo = nodo -> sig;
    //return nodo;
}

template<class T>
T& Iterador<T>::dato() {
    if (!nodo) throw std::out_of_range("El nodo actual es nulo.");
    return nodo->dato;
}


template<class T>
T& Iterador<T>::operator*() {
    return nodo->dato;
}


template<class T>
Iterador<T>& Iterador<T>::operator++() {
    if (nodo) {
        nodo = nodo->sig;
    }
    return *this;
}


template<class T>
Iterador<T>& Iterador<T>::operator--() {
    if (nodo) {
        nodo = nodo->ant;
    }
    return *this;
}

#endif //PR2_EEDD_ITERADOR_H

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::
