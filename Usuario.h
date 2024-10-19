#ifndef PR3_DEFINITIVO_USUARIO_H
#define PR3_DEFINITIVO_USUARIO_H

#include <string>
#include "Coche.h"

class Usuario {
private:
    std::string nif;
    std::string contrasena;
    std::string nombre;
    std::string direccion;
    Coche* coche = nullptr;

public:
    Usuario(const std::string& dni, const std::string& contrasena, const std::string& nombre, const std::string& direccion)
            : nif(dni), contrasena(contrasena), nombre(nombre), direccion(direccion) {}

    std::string getDNI() const { return nif; }
    std::string getContrasena() const { return contrasena; }
    std::string getNombre() const { return nombre; }
    std::string getDireccion() const { return direccion; }

    void setContrasena(const std::string& newContrasena) { contrasena = newContrasena; }
    void setDireccion(const std::string& newDireccion) { direccion = newDireccion; }

    void setCoche(Coche& coche) {
        this->coche = &coche;
        std::cout << "Coche " << coche.getModelo() << " asignado temporalmente a " << nombre << "." << std::endl;
        coche.setAlquilado(true);
    }

    Coche* getCoche() const { return coche; }
};

#endif //PR2_EEDD_USUARIO1_H