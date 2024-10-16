//
// Created by fjavi on 13/10/2024.
//

#include <iostream>

#ifndef PR3_DEFINITIVO_NODO_H
#define PR3_DEFINITIVO_NODO_H


template <class T>
class Nodo{
public:
    T dato;
    Nodo *sig, *ant;
    Nodo(T &dato, Nodo* Ant, Nodo* Sig = nullptr);
    Nodo(const Nodo& orig);
    Nodo<T> *getSiguiente();
    Nodo<T> *getAnterior();
};


template<class T>
Nodo<T>::Nodo(T &dato, Nodo<T> *Ant, Nodo* Sig): dato(dato),
                                                 sig(Sig),
                                                 ant(Ant)
{

}


template<class T>
Nodo<T>::Nodo(const Nodo& orig): dato(orig->dato),
                                 sig(orig->sig),
                                 ant(orig->ant)
{

}


template<class T>
Nodo<T>* Nodo<T>::getSiguiente(){
    return sig;
}


template<class T>
Nodo<T>* Nodo<T>::getAnterior(){
    return ant;
}

#endif //PR3_DEFINITIVO_NODO_H
