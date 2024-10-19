//
// Created by fjavi on 13/10/2024.
//

#include <iostream>

#ifndef PR3_DEFINITIVO_NODO_H
#define PR3_DEFINITIVO_NODO_H

/**
 * @class Nodo
 * @brief Clase que representa un nodo en una lista doblemente enlazada.
 *
 * Cada nodo contiene un dato de tipo genérico T, así como punteros al nodo siguiente y anterior.
 */
template <class T>
class Nodo {
public:
    T dato; ///< Dato almacenado en el nodo.
    Nodo* sig; ///< Puntero al siguiente nodo.
    Nodo* ant; ///< Puntero al nodo anterior.

    /**
     * @brief Constructor de Nodo.
     * @param dato Referencia al dato a almacenar en el nodo.
     * @param Ant Puntero al nodo anterior.
     * @param Sig Puntero al siguiente nodo (por defecto es nullptr).
     */
    Nodo(T& dato, Nodo* Ant, Nodo* Sig = nullptr);

    /**
     * @brief Constructor de copia.
     * @param orig Nodo a copiar.
     */
    Nodo(const Nodo& orig);

    /**
     * @brief Obtiene el puntero al siguiente nodo.
     * @return Puntero al siguiente nodo.
     */
    Nodo<T>* getSiguiente();

    /**
     * @brief Obtiene el puntero al nodo anterior.
     * @return Puntero al nodo anterior.
     */
    Nodo<T>* getAnterior();
};

template<class T>
Nodo<T>::Nodo(T& dato, Nodo<T>* Ant, Nodo* Sig) : dato(dato), sig(Sig), ant(Ant) { }

template<class T>
Nodo<T>::Nodo(const Nodo& orig) : dato(orig.dato), sig(orig.sig), ant(orig.ant) { }

template<class T>
Nodo<T>* Nodo<T>::getSiguiente() {
    return sig;
}

template<class T>
Nodo<T>* Nodo<T>::getAnterior() {
    return ant;
}

#endif // PR3_DEFINITIVO_NODO_H