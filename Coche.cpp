//
// Created by Francisco Javier González Rodríguez fjgr0029@red.ujaen.es
// Created by Juan Ávila de la Haba jah00012@red.ujaen.es
//

#include "Coche.h"

/**
 * @brief Constructor por defecto de la clase Coche.
 *
 * Este constructor inicializa un objeto Coche con valores predeterminados
 * para sus atributos: id_matricula, marca y modelo como cadenas vacías.
 */
Coche::Coche(): id_matricula(" "),
                marca(" "),
                modelo(" ")
{
}

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
Coche::Coche(std::string id, std::string marca, std::string modelo): id_matricula(id),
                                                                     marca(marca),
                                                                     modelo(modelo)
{
}

/**
 * @brief Destructor de la clase Coche.
 *
 * Este destructor se invoca cuando se destruye un objeto Coche. Actualmente,
 * no realiza ninguna acción adicional, ya que no se utilizan recursos dinámicos.
 */
Coche::~Coche()
{
}

/**
 * @brief Establece el ID de la matrícula del coche.
 *
 * @param id Cadena que representa el nuevo ID de la matrícula.
 */
void Coche::setId(std::string id) {
    this->id_matricula = id;
}

/**
 * @brief Establece la marca del coche.
 *
 * @param marca Cadena que representa la nueva marca del coche.
 */
void Coche::setMarca(std::string marca) {
    this->marca = marca;
}

/**
 * @brief Establece el modelo del coche.
 *
 * @param modelo Cadena que representa el nuevo modelo del coche.
 */
void Coche::setModelo(std::string modelo) {
    this->modelo = modelo;
}

/**
 * @brief Obtiene el ID de la matrícula del coche.
 *
 * @return Cadena que representa el ID de la matrícula.
 */
std::string Coche::getId() {
    return id_matricula;
}

/**
 * @brief Obtiene la marca del coche.
 *
 * @return Cadena que representa la marca del coche.
 */
std::string Coche::getMarca() {
    return marca;
}

/**
 * @brief Obtiene el modelo del coche.
 *
 * @return Cadena que representa el modelo del coche.
 */
std::string Coche::getModelo() {
    return modelo;
}

/**
 * @brief Obtiene el estado de alquiler del coche.
 *
 * @return Verdadero si el coche está alquilado, falso en caso contrario.
 */
bool Coche::getAlquilado(){
    return alquilado;
}

/**
 * @brief Establece el estado de alquiler del coche.
 *
 * @param estado Valor booleano que indica si el coche está alquilado o no.
 */
void Coche::setAlquilado(bool estado){
    this->alquilado = estado;
}

/**
 * @brief Operador de comparación menor que.
 *
 * Compara dos coches en función de su ID de matrícula.
 *
 * @param otro Otro objeto Coche a comparar.
 * @return Verdadero si el ID de matrícula del coche actual es menor que el del otro coche.
 */
bool Coche::operator<(const Coche& otro){
    return id_matricula < otro.id_matricula;
}

/**
 * @brief Operador de comparación mayor que.
 *
 * Compara dos coches en función de su ID de matrícula.
 *
 * @param otro Otro objeto Coche a comparar.
 * @return Verdadero si el ID de matrícula del coche actual es mayor que el del otro coche.
 */
bool Coche::operator>(const Coche& otro){
    return otro.id_matricula < this->id_matricula;
}

/**
 * @brief Operador de igualdad.
 *
 * Compara dos coches para verificar si son iguales en función de su ID de matrícula.
 *
 * @param otro Otro objeto Coche a comparar.
 * @return Verdadero si los IDs de matrícula de ambos coches son iguales.
 */
bool Coche::operator==(const Coche& otro) {
    return this->id_matricula == otro.id_matricula;
}
