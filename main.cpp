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
    ListaDEnlazada<int> lista;

    for (int i = 101; i <= 200; ++i) {
        lista.insertarFin(i);
    }

    for (int i = 98; i >= 1; --i) {
        lista.insertarInicio(i);
    }

    Iterador<int> it = lista.iterador();
    while (it.haySiguiente()) {
        if (it.getSiguiente()->dato == 102) {
            int dato = 100;
            lista.inserta(it, dato);
            break;
        }
        it.siguiente();
    }

    it = lista.iterador();
    while (it.haySiguiente()) {
        if (it.getSiguiente()->dato == 101) {
            int dato = 99;
            lista.inserta(it, dato);
            break;
        }
        it.siguiente();
    }

    int num = 200;
    lista.insertarFin(num);

    std::cout << "Lista tras inserciones:" << std::endl;
    it = lista.iterador();
    while (it.haySiguiente()) {
        std::cout << it.dato() << " ";
        it.siguiente();
    }

    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 10; ++i) {
        lista.borraInicio();
    }

    for (int i = 0; i < 10; ++i) {
        lista.borraFinal();
    }

    std::cout << "Lista tras borrar los 10 primeros y 10 últimos datos:" << std::endl;
    it = lista.iterador();
    while (it.haySiguiente()) {
        std::cout << it.dato() << " ";
        it.siguiente();
    }

    std::cout << std::endl;
    std::cout << std::endl;

    it = lista.iterador();
    while (it.haySiguiente()) {
        if (it.dato() % 10 == 0) {
            Iterador<int> actual = it;
            ++it;
            lista.borra(actual);
        } else {
            ++it;
        }
    }

    std::cout << "Lista tras borrar los múltiplos de 10:" << std::endl;
    it = lista.iterador();
    while (it.haySiguiente()) {
        std::cout << it.dato() << " ";
        it.siguiente();
    }
    std::cout << std::endl;

    return 0;
}*/