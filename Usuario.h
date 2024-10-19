#ifndef PR3_DEFINITIVO_USUARIO_H
#define PR3_DEFINITIVO_USUARIO_H

#include <string>
#include "Coche.h"

/**
 * @brief Clase que representa a un usuario del sistema.
 */
class Usuario {
private:
    std::string nif;        ///< NIF del usuario.
    std::string contrasena; ///< Contraseña del usuario.
    std::string nombre;     ///< Nombre del usuario.
    std::string direccion;  ///< Dirección del usuario.
    Coche* coche = nullptr; ///< Puntero al coche alquilado por el usuario.

public:
    /**
     * @brief Constructor de la clase Usuario.
     * @param dni NIF del usuario.
     * @param contrasena Contraseña del usuario.
     * @param nombre Nombre del usuario.
     * @param direccion Dirección del usuario.
     */
    Usuario(const std::string& dni, const std::string& contrasena, const std::string& nombre, const std::string& direccion)
            : nif(dni), contrasena(contrasena), nombre(nombre), direccion(direccion) {}

    /**
     * @brief Obtiene el NIF del usuario.
     * @return NIF del usuario.
     */
    std::string getDNI() const { return nif; }

    /**
     * @brief Obtiene la contraseña del usuario.
     * @return Contraseña del usuario.
     */
    std::string getContrasena() const { return contrasena; }

    /**
     * @brief Obtiene el nombre del usuario.
     * @return Nombre del usuario.
     */
    std::string getNombre() const { return nombre; }

    /**
     * @brief Obtiene la dirección del usuario.
     * @return Dirección del usuario.
     */
    std::string getDireccion() const { return direccion; }

    /**
     * @brief Establece una nueva contraseña para el usuario.
     * @param newContrasena Nueva contraseña a establecer.
     */
    void setContrasena(const std::string& newContrasena) { contrasena = newContrasena; }

    /**
     * @brief Establece una nueva dirección para el usuario.
     * @param newDireccion Nueva dirección a establecer.
     */
    void setDireccion(const std::string& newDireccion) { direccion = newDireccion; }

    /**
     * @brief Establece el coche alquilado por el usuario.
     * @param cochealquilado Puntero al coche a alquilar.
     */
    void setCoche(Coche* cochealquilado) {
        coche = cochealquilado;
    }

    /**
     * @brief Obtiene el coche alquilado por el usuario.
     * @return Puntero al coche alquilado.
     */
    Coche* getCoche() const { return coche; }
};

#endif //PR2_EEDD_USUARIO1_H