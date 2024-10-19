//
// Created by Francisco Javier González Rodríguez fjgr0029@red.ujaen.es
// Created by Juan Ávila de la Haba jah00012@red.ujaen.es
//

#include <iostream>

#ifndef PR3_DEFINITIVO_COCHE_H
#define PR3_DEFINITIVO_COCHE_H

#include <string>

/**
 * @class Coche
 * @brief Clase que representa un coche.
 *
 * La clase Coche encapsula los atributos y comportamientos relacionados con
 * un coche, incluyendo su identificación, marca, modelo y estado de alquiler.
 */
class Coche {
private:
    std::string id_matricula; ///< ID de matrícula del coche.
    std::string marca;        ///< Marca del coche.
    std::string modelo;       ///< Modelo del coche.
    bool alquilado;           ///< Estado de alquiler del coche (true si está alquilado, false en caso contrario).

public:
    /**
     * @brief Constructor por defecto de la clase Coche.
     *
     * Este constructor inicializa un objeto Coche con valores predeterminados
     * para sus atributos.
     */
    Coche();

    /**
     * @brief Constructor parametrizado de la clase Coche.
     *
     * Este constructor inicializa un objeto Coche con los valores proporcionados
     * para id_matricula, marca y modelo.
     *
     * @param id Cadena que representa el ID de la matrícula del coche.
     * @param marca Cadena que representa la marca del coche.
     * @param modelo Cadena que representa el modelo del coche.
     */
    Coche(std::string id, std::string marca, std::string modelo);

    /**
     * @brief Destructor de la clase Coche.
     *
     * Este destructor se invoca cuando se destruye un objeto Coche.
     */
    ~Coche();

    /**
     * @brief Obtiene el ID de la matrícula del coche.
     *
     * @return Cadena que representa el ID de la matrícula.
     */
    std::string getId();

    /**
     * @brief Establece el ID de la matrícula del coche.
     *
     * @param id Cadena que representa el nuevo ID de la matrícula.
     */
    void setId(std::string id);

    /**
     * @brief Obtiene la marca del coche.
     *
     * @return Cadena que representa la marca del coche.
     */
    std::string getMarca();

    /**
     * @brief Establece la marca del coche.
     *
     * @param marca Cadena que representa la nueva marca del coche.
     */
    void setMarca(std::string marca);

    /**
     * @brief Obtiene el modelo del coche.
     *
     * @return Cadena que representa el modelo del coche.
     */
    std::string getModelo();

    /**
     * @brief Establece el modelo del coche.
     *
     * @param modelo Cadena que representa el nuevo modelo del coche.
     */
    void setModelo(std::string modelo);

    /**
     * @brief Obtiene el estado de alquiler del coche.
     *
     * @return Verdadero si el coche está alquilado, falso en caso contrario.
     */
    bool getAlquilado();

    /**
     * @brief Establece el estado de alquiler del coche.
     *
     * @param estado Valor booleano que indica si el coche está alquilado o no.
     */
    void setAlquilado(bool estado);

    /**
     * @brief Operador de comparación menor que.
     *
     * Compara dos coches en función de su ID de matrícula.
     *
     * @param otro Otro objeto Coche a comparar.
     * @return Verdadero si el ID de matrícula del coche actual es menor que el del otro coche.
     */
    bool operator<(const Coche& otro);

    /**
     * @brief Operador de comparación mayor que.
     *
     * Compara dos coches en función de su ID de matrícula.
     *
     * @param otro Otro objeto Coche a comparar.
     * @return Verdadero si el ID de matrícula del coche actual es mayor que el del otro coche.
     */
    bool operator>(const Coche& otro);

    /**
     * @brief Operador de igualdad.
     *
     * Compara dos coches para verificar si son iguales en función de su ID de matrícula.
     *
     * @param otro Otro objeto Coche a comparar.
     * @return Verdadero si los IDs de matrícula de ambos coches son iguales.
     */
    bool operator==(const Coche& otro);
};

#endif // PR3_DEFINITIVO_COCHE_H