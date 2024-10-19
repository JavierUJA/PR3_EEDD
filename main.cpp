//
// Created by Francisco Javier González Rodríguez fjgr0029@red.ujaen.es
// Created by Juan Ávila de la Haba jah00012@red.ujaen.es
//
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>
#include "VDinamico.h"
#include "Coche.h"
#include "ListaDEnlazada.h"
#include "Usuario.h"
#include "cstring"
#include "ReanelCar.h"
/*int main(int argc, const char * argv[]) {
    // Crear una lista de enteros
    ListaDEnlazada<int> lista;

    // Inserta números del 101 al 200 al final de la lista
    for (int i = 101; i <= 200; ++i) {
        lista.insertarFin(i);
    }

    // Inserta números del 98 al 1 al inicio de la lista
    for (int i = 98; i >= 1; --i) {
        lista.insertarInicio(i);
    }

    // Iterador para navegar por la lista
    Iterador<int> it = lista.iterador();
    // Inserta un número específico antes de un dato particular
    while (it.haySiguiente()) {
        if (it.getSiguiente()->dato == 102) {
            int dato = 100;
            lista.inserta(it, dato);
            break;
        }
        it.siguiente();
    }

    // Otro iterador para otra inserción
    it = lista.iterador();
    while (it.haySiguiente()) {
        if (it.getSiguiente()->dato == 101) {
            int dato = 99;
            lista.inserta(it, dato);
            break;
        }
        it.siguiente();
    }

    // Inserta el número 200 al final de la lista
    int num = 200;
    lista.insertarFin(num);

    // Muestra el contenido de la lista tras las inserciones
    std::cout << "Lista tras inserciones:" << std::endl;
    it = lista.iterador();
    while (it.haySiguiente()) {
        std::cout << it.dato() << " ";
        it.siguiente();
    }

    std::cout << std::endl << std::endl;

    // Borra los primeros 10 elementos de la lista
    for (int i = 0; i < 10; ++i) {
        lista.borraInicio();
    }

    // Borra los últimos 10 elementos de la lista
    for (int i = 0; i < 10; ++i) {
        lista.borraFinal();
    }

    // Muestra el contenido de la lista tras la eliminación de datos
    std::cout << "Lista tras borrar los 10 primeros y 10 últimos datos:" << std::endl;
    it = lista.iterador();
    while (it.haySiguiente()) {
        std::cout << it.dato() << " ";
        it.siguiente();
    }

    std::cout << std::endl << std::endl;

    // Elimina múltiplos de 10 de la lista
    it = lista.iterador();
    while (it.haySiguiente()) {
        if (it.dato() % 10 == 0) {
            Iterador<int> actual = it;
            ++it; // Mueve el iterador al siguiente elemento
            lista.borra(actual); // Borra el elemento actual
        } else {
            ++it; // Solo avanza el iterador si no se borra
        }
    }

    // Muestra el contenido final de la lista
    std::cout << "Lista tras borrar los múltiplos de 10:" << std::endl;
    it = lista.iterador();
    while (it.haySiguiente()) {
        std::cout << it.dato() << " ";
        it.siguiente();
    }
    std::cout << std::endl;

    return 0; // Código de salida exitoso
}*/