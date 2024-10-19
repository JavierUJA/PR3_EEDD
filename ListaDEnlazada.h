//
// Created by administrador on 1/10/24.
//

#include <iostream>
#include "Iterador.h"
#include "Nodo.h"

#ifndef PR3_DEFINITIVO_LISTADENLAZADA_H
#define PR3_DEFINITIVO_LISTADENLAZADA_H

/**
 * @class ListaDEnlazada
 * @brief Clase que representa una lista doblemente enlazada.
 *
 * La clase ListaDEnlazada permite almacenar y gestionar una colección de elementos
 * de tipo genérico T, proporcionando métodos para insertar, borrar y acceder
 * a elementos en la lista.
 */
template <class T>
class ListaDEnlazada {
private:
    Nodo<T>* cabecera; ///< Puntero al primer nodo de la lista.
    Nodo<T>* cola; ///< Puntero al último nodo de la lista.
    int numelementos = 0; ///< Número de elementos en la lista.

public:
    ListaDEnlazada(); ///< Constructor por defecto.
    ListaDEnlazada(const ListaDEnlazada<T>& origen); ///< Constructor de copia.
    ~ListaDEnlazada(); ///< Destructor.

    Iterador<T> iterador() const; ///< Crea un iterador para recorrer la lista.
    T& inicio(); ///< Devuelve el dato del primer nodo.
    T& fin(); ///< Devuelve el dato del último nodo.
    int tam(); ///< Devuelve el número de elementos en la lista.
    void inserta(Iterador<T>& i, T& dato); ///< Inserta un elemento en la posición del iterador.
    void insertarInicio(T& dato); ///< Inserta un elemento al inicio de la lista.
    void insertarFin(T& dato); ///< Inserta un elemento al final de la lista.
    void borra(Iterador<T>& i); ///< Borra el nodo en la posición del iterador.
    void borraInicio(); ///< Borra el primer nodo de la lista.
    void borraFinal(); ///< Borra el último nodo de la lista.
    ListaDEnlazada<T>& operator=(ListaDEnlazada& otra_list); ///< Sobrecarga del operador de asignación.
};

template<class T>
ListaDEnlazada<T>::ListaDEnlazada() : cabecera(0), cola(0) { }

template<class T>
ListaDEnlazada<T>::ListaDEnlazada(const ListaDEnlazada& origen) : cabecera(nullptr), cola(nullptr) {
    if (origen.cabecera == nullptr) {
        return;
    }

    Iterador<T> it = origen.iterador();
    while (it.haySiguiente()) {
        Nodo<T>* nuevo = new Nodo<T>(it.dato(), it.getAnterior(), it.getSiguiente());

        if (cabecera == nullptr) {
            cabecera = nuevo;
            cola = nuevo;
        } else {
            cola->sig = nuevo;
            nuevo->ant = cola;
            cola = nuevo;
        }
        it.siguiente();
    }
}

template<class T>
ListaDEnlazada<T>& ListaDEnlazada<T>::operator=(ListaDEnlazada& otra_list) {
    this->cabecera = otra_list.cabecera;
    this->cola = otra_list.cola;
    return *this;
}

template<class T>
T& ListaDEnlazada<T>::inicio() {
    Nodo<T>* nodo = cabecera;
    return nodo->dato;
}

template<class T>
T& ListaDEnlazada<T>::fin() {
    Nodo<T>* nodo = cola;
    return nodo->dato;
}

template<class T>
Iterador<T> ListaDEnlazada<T>::iterador() const {
    return Iterador<T>(cabecera);
}

template<class T>
void ListaDEnlazada<T>::insertarInicio(T& dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato, 0, cabecera);

    if (cola == nullptr) {
        cola = nuevo;
    }

    if (cabecera != nullptr) {
        cabecera->ant = nuevo;
    }
    cabecera = nuevo;

    numelementos++;
}

template<class T>
void ListaDEnlazada<T>::insertarFin(T& dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato, cola, 0);

    if (cabecera == 0) {
        cabecera = nuevo;
    }

    if (cola != 0) {
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
    cabecera = cabecera->sig;

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
    cola = cola->ant;

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

    if (actual->ant != nullptr) {
        actual->ant->sig = actual->sig;
    } else {
        cabecera = actual->sig;
    }

    if (actual->sig != nullptr) {
        actual->sig->ant = actual->ant;
    } else {
        cola = actual->ant;
    }

    i.siguiente();
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

#endif // PR3_DEFINITIVO_LISTADENLAZADA_H