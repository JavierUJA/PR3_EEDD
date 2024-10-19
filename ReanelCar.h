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

/**
 * @class ReanelCar
 * @brief Clase que gestiona el sistema de alquiler de coches.
 *
 * Esta clase permite cargar coches y usuarios desde archivos, buscar coches y usuarios,
 * y gestionar el alquiler de coches a usuarios.
 */
class ReanelCar {
private:
    VDinamico<Coche*> coches; ///< Vector dinámico que almacena los coches disponibles.
    ListaDEnlazada<Usuario> usuarios; ///< Lista de usuarios registrados.
    VDinamico<Coche*> alquileres; ///< Vector dinámico que almacena los coches alquilados.

public:
    /**
     * @brief Carga los coches desde un archivo.
     * @param filename Nombre del archivo de coches.
     */
    void cargarCoches(const std::string& filename);

    /**
     * @brief Carga los usuarios desde un archivo.
     * @param filename Nombre del archivo de usuarios.
     */
    void cargarUsuarios(const std::string& filename);

    /**
     * @brief Busca un usuario por su NIF.
     * @param nif NIF del usuario a buscar.
     * @return Puntero al usuario encontrado, o nullptr si no existe.
     */
    Usuario* buscarUsrNif(const std::string& nif);

    /**
     * @brief Busca usuarios por parte de su nombre.
     * @param substring Subcadena a buscar en los nombres de los usuarios.
     * @return Lista de usuarios que contienen la subcadena en su nombre.
     */
    ListaDEnlazada<Usuario> buscarUsrNomb(const std::string& substring);

    /**
     * @brief Busca un coche por su matrícula.
     * @param matricula Matrícula del coche a buscar.
     * @return Puntero al coche encontrado, o nullptr si no existe.
     */
    Coche* buscarCochMat(const std::string& matricula);

    /**
     * @brief Busca coches por su modelo.
     * @param modelo Modelo del coche a buscar.
     * @return Vector dinámico de punteros a coches que coinciden con el modelo.
     */
    VDinamico<Coche*> buscarCochModelo(const std::string& modelo);

    /**
     * @brief Busca coches por su modelo utilizando búsqueda binaria.
     * @param modelo Modelo del coche a buscar.
     * @return Vector dinámico de punteros a coches que coinciden con el modelo.
     */
    VDinamico<Coche*> buscarCochModeloBinario(const std::string& modelo);

    /**
     * @brief Obtiene la lista de usuarios registrados.
     * @return Lista de usuarios.
     */
    ListaDEnlazada<Usuario> getUsuarios();

    /**
     * @brief Establece la lista de usuarios.
     * @param users Lista de usuarios a establecer.
     */
    void setUsuarios(ListaDEnlazada<Usuario> users);

    /**
     * @brief Alquila un coche a un usuario.
     * @param usuario Usuario que alquila el coche.
     * @param coche Coche a alquilar.
     * @return true si el alquiler se realiza con éxito, false en caso contrario.
     */
    bool alquilar(Usuario &usuario, Coche &coche);

    /**
     * @brief Verifica si un usuario tiene un coche alquilado.
     * @param dni DNI del usuario a verificar.
     * @return true si el usuario tiene un coche alquilado, false en caso contrario.
     */
    bool usuarioConCoche(const std::string& dni);

    /**
     * @brief Destructor de la clase ReanelCar.
     */
    ~ReanelCar();
};

#endif // PR3_DEFINITIVO_REANELCAR_H