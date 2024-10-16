//
// Created by Francisco Javier González Rodríguez fjgr0029@red.ujaen.es
// Created by Juan Ávila de la Haba jah00012@red.ujaen.es
//

#include <iostream>

#ifndef PR3_DEFINITIVO_COCHE_H
#define PR3_DEFINITIVO_COCHE_H


class Coche {
private:
    std::string id_matricula=" ";
    std::string marca=" ";
    std::string modelo=" ";
    bool alquilado = false;
public:
    Coche();
    Coche(std::string id, std::string marca, std::string modelo);
    ~Coche();
    std::string getId();
    void setId(std::string id);
    std::string getMarca();
    void setMarca(std::string marca);
    std::string getModelo();
    void setModelo(std::string modelo);
    bool getAlquilado();
    void setAlquilado(bool estado);
    bool operator<(const Coche& otro);
    bool operator>(const Coche& otro);
    bool operator==(const Coche& otro);
};


#endif //UNTITLED_COCHE_H