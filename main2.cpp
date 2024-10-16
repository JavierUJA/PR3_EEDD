//
// Created by Francisco Javier González Rodríguez fjgr0029@red.ujaen.es
// Created by Juan Ávila de la Haba jah00012@red.ujaen.es
//
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>
#include "VDinamico.h"
#include "Coche.h"
#include "ListaDEnlazada.h"
#include "cstring"
#include "ReanelCar.h"
int main(int argc, const char * argv[]) {
    ReanelCar empresa;

    empresa.cargarCoches("../coches.csv");
    empresa.cargarUsuarios("../usuarios1.csv");

    //ListaDEnlazada<Usuario> usuariosW = empresa.buscarUsrNomb("W");
    //VDinamico<Coche *> cochesFordFiesta = empresa.buscarCochModelo("Fiesta");
    ListaDEnlazada<Usuario> usuarios = empresa.getUsuarios();
    //Iterador<Usuario> itW = usuariosW.iterador();

    /*if (!itW.haySiguiente()) {
        std::cerr << "No se encontraron usuarios cuyo nombre empieza con 'W'." << std::endl;
    } else {

        int cont = 0;
        while (itW.haySiguiente()) {
            Usuario &usuario = itW.dato();
            std::cout << usuario.getNombre() << std::endl;
            itW.siguiente();

            if (cochesFordFiesta.tamlog() > 0) {
                bool exito = empresa.alquilar(usuario, *cochesFordFiesta[cont]);
                if (!exito) {
                    std::cout << "No se pudo alquilar el coche " << cochesFordFiesta[cont]->getModelo() << " para el usuario " << usuario.getNombre() << std::endl;
                }

                cont++;
            } else {
                std::cout << "No hay Ford Fiesta disponible para el usuario " << usuario.getNombre() << std::endl;
            }
        }
    }*/

    ListaDEnlazada<Usuario> usuariosWa = empresa.buscarUsrNomb("Wa");
    Iterador<Usuario> itWa = usuariosWa.iterador();
    Iterador<Usuario> itU = usuarios.iterador();
    if (itWa.haySiguiente()) {
        while (itWa.haySiguiente()) {
            std::string usuarioWa = itWa.dato().getNombre();
            while(itU.haySiguiente()) {
                std::string user = itU.dato().getNombre();
                if(user == usuarioWa){
                    std::cout << "Eliminando usuario: " << itWa.dato().getNombre() << std::endl;
                    usuarios.borra(itU);
                    break;
                }else{
                    itU.siguiente();
                };
            }
            itWa.siguiente();
        }
    } else {
        std::cerr << "No se encontraron usuarios cuyo nombre empieza con 'Wa'." << std::endl;
    }
/*
    int usuariosConCoche = 0;
    Iterador<Usuario>it = usuariosW.iterador();
    if (!it.haySiguiente()) {
        Iterador<Usuario> itW = usuariosW.iterador();
        while (itW.haySiguiente()) {
            Usuario& usuario = itW.dato();
            itW.siguiente();
            if (empresa.usuarioConCoche(usuario.getDNI())) {
                usuariosConCoche++;
            }
        }
    }


    std::cout << "Usuarios cuyo nombre empieza con 'W' y tienen coche alquilado: " << usuariosConCoche << std::endl;

    auto inicioSecuencial = std::chrono::high_resolution_clock::now();
    VDinamico<Coche*> resultadoSecuencial = empresa.buscarCochModelo("Ford Fiesta");
    auto finSecuencial = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracionSecuencial = finSecuencial - inicioSecuencial;

    auto inicioBinaria = std::chrono::high_resolution_clock::now();
    VDinamico<Coche*> resultadoBinario = empresa.buscarCochModeloBinario("Ford Fiesta");
    auto finBinaria = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracionBinaria = finBinaria - inicioBinaria;

    std::cout << "Tiempo de búsqueda secuencial: " << duracionSecuencial.count() << " segundos" << std::endl;
    std::cout << "Tiempo de búsqueda binaria: " << duracionBinaria.count() << " segundos" << std::endl;

    return 0;*/


    Iterador<Usuario> itu = usuarios.iterador();
    while(itu.haySiguiente()){
        std::cout << itu.dato().getNombre() << ", ";
        itu.siguiente();
    }
}