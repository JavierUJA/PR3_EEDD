//
// Created by fjavi on 02/10/2024.
//

#ifndef PR3_DEFINITIVO_REANELCAR_H
#define PR3_DEFINITIVO_REANELCAR_H

#include <iostream>
#include <vector>
#include "ListaDEnlazada.h"
#include "Coche.h"
#include "Usuario.h"
#include <fstream>
#include <sstream>
#include <map>
#include "VDinamico.h"

class ReanelCar {
private:
    VDinamico<Coche*> coches;
    ListaDEnlazada<Usuario> usuarios;
    VDinamico<Coche*> alquileres;

public:
    void cargarCoches(const std::string& filename);
    void cargarUsuarios(const std::string& filename);

    Usuario* buscarUsrNif(const std::string& nif);
    ListaDEnlazada<Usuario> buscarUsrNomb(const std::string& substring);
    Coche* buscarCochMat(const std::string& matricula);
    VDinamico<Coche*> buscarCochModelo(const std::string& modelo);
    VDinamico<Coche*> buscarCochModeloBinario(const std::string& modelo);
    ListaDEnlazada<Usuario> getUsuarios();
    void setUsuarios(ListaDEnlazada<Usuario> users);
    bool alquilar(Usuario &usuario, Coche &coche);
    bool usuarioConCoche(const std::string& dni);
};


#endif //PR2_EEDD_REANELCAR_H
