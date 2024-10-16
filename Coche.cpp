//
// Created by Francisco Javier González Rodríguez fjgr0029@red.ujaen.es
// Created by Juan Ávila de la Haba jah00012@red.ujaen.es
//

#include "Coche.h"

Coche::Coche(): id_matricula(" "),
                marca(" "),
                modelo(" ")
{

}

Coche::Coche(std::string id, std::string marca, std::string modelo): id_matricula(id),
                                                                     marca(marca),
                                                                     modelo(modelo)
{

}

Coche::~Coche()
{

}

void Coche::setId(std::string id) {
    this->id_matricula = id;
}

void Coche::setMarca(std::string marca) {
    this->marca = marca;
}

void Coche::setModelo(std::string modelo) {
    this->modelo = modelo;
}


std::string Coche::getId() {
    return id_matricula;
}

std::string Coche::getMarca() {
    return marca;
}

std::string Coche::getModelo() {
    return modelo;
}

bool Coche::getAlquilado(){
    return alquilado;
}
void Coche::setAlquilado(bool estado){
    this->alquilado = estado;
}

bool Coche::operator<(const Coche& otro){
    return id_matricula < otro.id_matricula;
}

bool Coche::operator>(const Coche& otro){
    return otro.id_matricula < this->id_matricula;
}

bool Coche::operator==(const Coche& otro) {
    return this->id_matricula == otro.id_matricula;
}