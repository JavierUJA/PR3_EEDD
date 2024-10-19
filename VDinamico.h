//
// Created by Francisco Javier González Rodríguez fjgr0029@red.ujaen.es
// Created by Juan Ávila de la Haba jah00012@red.ujaen.es
//
#include <iostream>
#include <cmath>
#include <algorithm>
#include "Coche.h"


#ifndef UNTITLED_VDINAMICO_H
#define UNTITLED_VDINAMICO_H

template<class T>
class VDinamico {
private:
    long int tamF, tamL;
    T* datos;
public:
    VDinamico();
    ~VDinamico();
    VDinamico(unsigned int tamlog);
    VDinamico(const VDinamico& orig);
    VDinamico(const VDinamico& origen, unsigned int posinicial, unsigned int numelementos);
    void insertar(const T& dato, unsigned int pos = UINT_MAX);
    void eliminar(unsigned int pos = UINT_MAX);
    void ordenar();
    int busquedabinaria(const std::string &dato);
    unsigned int tamlog();
    T& operator=(const VDinamico& origen);
    T& operator[](unsigned int pos);
};



template<class T>
VDinamico<T>::VDinamico(){
    tamL = 0;
    tamF = 1;
    datos = new T[tamF];
}


/**
 * @brief Constructor parametrizado
 * @param tamlog Tamaño lógico que queremos asignar
 */
template<class T>
VDinamico<T>::VDinamico(unsigned int tamlog): tamL(tamlog)
{
    tamF = pow(2, tamlog + 1);
    datos = new T[tamF];
}


template<class T>
VDinamico<T>::~VDinamico() {
    delete[] datos;
}
/**
 * @brief Constructor de copia
 * @tparam orig Vector a copiar
 */
template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &orig){
    if(log(tamF)==0) {
        tamF=orig.tamF;
        tamL=orig.tamL;
        datos = new T[tamF];
        for (int i = 0; i < tamL; ++i) {
            datos[i] = orig.datos[i];
        }
    }
}


/**
 * @brief Construtor de copia parcial
 * @param origen Vector a copiar
 * @param posicionInicial Posicion del vector desde donde empezar
 * @param numElementos Numero de elementos a copiar
 */
template<class T>
VDinamico<T>::VDinamico(const VDinamico& origen, unsigned int posicionInicial,unsigned int numElementos) {
    if (posicionInicial >= origen.tamL) throw std::out_of_range("Posición inicial fuera de rango.");
    if (posicionInicial + numElementos > origen.tamL) numElementos = origen.tamL - posicionInicial;
    tamL = numElementos;
    tamF = pow(2,numElementos+1);
    datos = new T[tamF];
    for (unsigned int i = 0; i < tamL; ++i) {
        datos[i] = origen.datos[posicionInicial + i];
    }
}


/**
 * @brief Insertar dato en el vector
 * @param dato Dato a insertar
 * @param pos Posicion donde insertar
 */
template<class T>
void VDinamico<T>::insertar(const T& dato, unsigned int pos) {
    if(tamL == tamF) {
        T *vaux;
        vaux = new T[tamF=tamF*2];

        for(int i = 0; i < tamL; i++) {
            vaux[i] = datos[i];
        }

        delete[] datos;

        datos = vaux;
    }

    if(pos == UINT_MAX) {
        pos = tamL;
    }

    datos[pos] = dato;
    tamL++;
}


/**
 * @brief Eliminar un dato
 * @param pos Posicion a eliminar
 */
template<class T>
void VDinamico<T>::eliminar(unsigned int pos) {
    if(pos == UINT_MAX) {
        pos = tamL - 1;
    }

    for(unsigned i = pos; i < tamL; i++) {
        datos[i] = datos[i+1];
    }

    if(tamL*3 < tamF) {
        tamF=tamF/2;
        T *vaux = new T[tamF];
        for(unsigned i = 0; i < tamL; i++) {
            vaux[i] = datos[i];
        }

        delete[] datos;
        datos = vaux;
    }

    tamL--;
}


/**
 * @brief Ordenar vector
 */
template<class T>
void VDinamico<T>::ordenar() {
    std::sort(datos, datos + tamL, [](Coche *a, const Coche *b) { return *a < *b; }); // Ordenar usando std::sort
}


/**
 * @brief Busqueda binaria de un dato
 * @param dato Dato a buscar
 * @return
 */
template<class T>
int VDinamico<T>::busquedabinaria(const std::string& idBuscado) {
    int inf = 0;
    int sup = tamL - 1;
    int curIn;

    while (inf <= sup) {
        curIn = (inf + sup) / 2;
        std::string idActual = datos[curIn]->getModelo();

        if (idActual == idBuscado) {
            return curIn;
        } else if (idActual < idBuscado) {
            inf = curIn + 1;
        } else {
            sup = curIn - 1;
        }
    }

    return -1;
}


/**
 * @brief Consultar el tamaño lógico
 * @return tamL
 */
template<class T>
unsigned int VDinamico<T>::tamlog(){
    return tamL;
}


/**
 * @brief Operador =
 * @param origen Vector donde asignar los datos
 */
template<class T>
T& VDinamico<T>::operator=(const VDinamico& origen) {
    if (&origen != this) {
        delete [] datos;
        tamF = origen.tamF;
        tamL = origen.tamL;

        datos = new T[tamF];
        for (int c = 0; c < tamL; c++) {
            datos[c] = origen.datos[c];
        }


    }
    return *this;
}


/**
 * @brief Operador []
 * @param pos Posicion a la cual acceder
 */
template<class T>
T& VDinamico<T>::operator[](unsigned int pos){
    if (pos >= tamL) throw std::out_of_range("Índice fuera de rango.");
    return datos[pos];
}


#endif //UNTITLED_VDINAMICO_H


