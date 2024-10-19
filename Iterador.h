//
// Created by administrador on 1/10/24.
//

#include <iostream>
#include "Nodo.h"


#ifndef PR3_DEFINITIVO_ITERADOR_H
#define PR3_DEFINITIVO_ITERADOR_H

#include <stdexcept>

/**
 * @class Iterador
 * @brief Clase que representa un iterador para una lista doblemente enlazada.
 *
 * La clase Iterador permite recorrer los elementos de una lista doblemente enlazada,
 * proporcionando métodos para avanzar, retroceder y acceder a los datos del nodo actual.
 */
template<class T>
class Iterador {
private:
    Nodo<T>* nodo; ///< Puntero al nodo actual del iterador.

public:
    /**
     * @brief Constructor del iterador.
     *
     * Inicializa un iterador en el nodo especificado.
     *
     * @param Nodo Puntero al nodo donde comenzará el iterador.
     */
    explicit Iterador(Nodo<T>* Nodo);

    /**
     * @brief Verifica si hay un nodo anterior.
     *
     * @return Verdadero si existe un nodo anterior; falso en caso contrario.
     */
    bool hayAnterior();

    /**
     * @brief Verifica si hay un nodo siguiente.
     *
     * @return Verdadero si existe un nodo siguiente; falso en caso contrario.
     */
    bool haySiguiente();

    /**
     * @brief Avanza al siguiente nodo.
     *
     * Si hay un siguiente, el iterador se moverá a él; de lo contrario, lanzará una excepción.
     */
    void siguiente();

    /**
     * @brief Retrocede al nodo anterior.
     *
     * Si hay un anterior, el iterador se moverá a él; de lo contrario, lanzará una excepción.
     */
    void anterior();

    /**
     * @brief Obtiene el nodo siguiente.
     *
     * @return Puntero al nodo siguiente.
     * @throws std::out_of_range Si no hay un siguiente.
     */
    Nodo<T>* getSiguiente();

    /**
     * @brief Obtiene el nodo anterior.
     *
     * @return Puntero al nodo anterior.
     * @throws std::out_of_range Si no hay un anterior.
     */
    Nodo<T>* getAnterior();

    /**
     * @brief Obtiene el dato del nodo actual.
     *
     * @return Referencia al dato del nodo actual.
     * @throws std::out_of_range Si el nodo actual es nulo.
     */
    T& dato();

    /**
     * @brief Obtiene el nodo actual.
     *
     * @return Puntero al nodo actual.
     */
    Nodo<T>* getNodo() {
        return nodo;
    }

    /**
     * @brief Sobrecarga del operador de desreferencia.
     *
     * @return Referencia al dato del nodo actual.
     */
    T& operator*();

    /**
     * @brief Sobrecarga del operador de incremento.
     *
     * Avanza el iterador al siguiente nodo.
     *
     * @return Referencia al iterador actualizado.
     */
    Iterador& operator++();

    /**
     * @brief Sobrecarga del operador de decremento.
     *
     * Retrocede el iterador al nodo anterior.
     *
     * @return Referencia al iterador actualizado.
     */
    Iterador& operator--();
};

template<class T>
Iterador<T>::Iterador(Nodo<T>* Nodo) : nodo(Nodo) { }

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
        return nodo->sig;
    }
    throw std::out_of_range("No hay más elementos");
}

template<class T>
Nodo<T>* Iterador<T>::getAnterior(){
    if(hayAnterior()){
        return nodo->ant;
    }
    throw std::out_of_range("No hay más elementos");
}

template<class T>
void Iterador<T>::anterior(){
    nodo = nodo->ant;
}

template<class T>
void Iterador<T>::siguiente(){
    nodo = nodo->sig;
}

template<class T>
T& Iterador<T>::dato() {
    if (!nodo) throw std::out_of_range("El nodo actual es nulo.");
    return nodo->dato;
}

template<class T>
T& Iterador<T>::operator*() {
    return dato();
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

#endif // PR3_DEFINITIVO_ITERADOR_H