//
// Created by fjavi on 13/10/2024.
//

#include "ReanelCar.h"

void ReanelCar::cargarCoches(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo de coches: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::istringstream ss(line);
        std::string matricula, marca, modelo;

        std::getline(ss, matricula, ',');
        std::getline(ss, marca, ',');
        std::getline(ss, modelo, ',');

        if (matricula.empty() || marca.empty() || modelo.empty()) {
            std::cerr << "Error: Fila con formato incorrecto: " << line << std::endl;
            continue;
        }

        coches.insertar(new Coche(matricula, marca, modelo));
    }

    file.close();
    std::cout << "Coches cargados correctamente." << std::endl;
}

void ReanelCar::cargarUsuarios(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo de usuarios: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::istringstream ss(line);
        std::string dni, contrasena, nombre, direccion;

        std::getline(ss, dni, ',');
        std::getline(ss, contrasena, ',');
        std::getline(ss, nombre, ',');
        std::getline(ss, direccion, ',');

        if (dni.empty() || contrasena.empty() || nombre.empty() || direccion.empty()) {
            std::cerr << "Error: Fila con formato incorrecto: " << line << std::endl;
            continue; // Saltar filas mal formateadas
        }

        Usuario nuevoUsuario(dni, contrasena, nombre, direccion);
        usuarios.insertarFin(nuevoUsuario);
    }

    file.close();

    std::cout << "Usuarios cargados correctamente." << std::endl;
}

Usuario* ReanelCar::buscarUsrNif(const std::string& nif) {
    Iterador<Usuario> it = usuarios.iterador();
    while (it.haySiguiente()) {
        Usuario& user = it.dato();
        it.siguiente(); //:::::::::::::::::::::AQUI:::::::::::::::::::::::::
        if (user.getDNI() == nif) {
            return &user;
        }
    }
    return nullptr;
}


/**
 * @brief Buscar usuarios por parte de su nombre
 * @param substring
 * @return
 */
ListaDEnlazada<Usuario> ReanelCar::buscarUsrNomb(const std::string& substring) {
    ListaDEnlazada<Usuario> resultados;
    Iterador<Usuario> it = usuarios.iterador();
    while (it.haySiguiente()) {
        Usuario& user = it.dato();
        it.siguiente(); //:::::::::::::::::::::AQUI:::::::::::::::::::::::::
        if (user.getNombre().find(substring) == 0) {
            resultados.insertarFin(user);
        }
    }

    /*Iterador<Usuario> itU = resultados.iterador();
    while(itU.haySiguiente()){
        Usuario& usu = itU.dato();
        std::cout << usu.getNombre() << ", ";
        itU.siguiente();
    }*/

    return resultados;
}


/**
 * @brief Buscar coche por matrícula
 * @param matricula
 * @return
 */
Coche* ReanelCar::buscarCochMat(const std::string& matricula) {
    for (int i = 0; i < coches.tamlog(); i++) {
        if (coches[i]->getId() == matricula) {
            return coches[i];
        }
    }
    return nullptr;
}


/**
 *
 * @brief Buscar coches por modelos
 * @param modelo Modelo que queremos buscar
 * @return Un vector dinámico con los coches cuyo modelo son los dados
 *
 */
VDinamico<Coche*> ReanelCar::buscarCochModelo(const std::string &modelo) {
    VDinamico<Coche*> cochesEncontrados;

    for (int i = 0; i < coches.tamlog(); ++i) {
        Coche* coche = coches[i];
        if (coche->getModelo() == modelo && coche->getAlquilado() == false) {
            cochesEncontrados.insertar(coche);
        }
    }

    /*for(int i = 0; i < cochesEncontrados.tamlog(); i++){
        std::cout << cochesEncontrados.operator[](i)->getId() << ", ";
    }*/

    return cochesEncontrados;
}


/**
 * @brief Alquila el coche que pasemos como parámetro al usuario que pasemos también
 * @param usuario
 * @param coche
 * @return
 */
bool ReanelCar::alquilar(Usuario &usuario, Coche &coche) {
    if (coche.getAlquilado()) {
        std::cout << "El coche " << coche.getId() << " ya está alquilado." << std::endl;
        return false;
    }
    usuario.setCoche(&coche);
    coche.setAlquilado(true);

    std::cout << "Coche " << coche.getId() << " alquilado a " << usuario.getNombre() << "." << std::endl;
    return true;
}



VDinamico<Coche*> ReanelCar::buscarCochModeloBinario(const std::string& modelo) {
    coches.ordenar();
    int indice = coches.busquedabinaria(modelo);
    VDinamico<Coche*> cochesEncontrados;

    if (indice != -1) {
        int izquierda = indice;
        while (izquierda >= 0 && coches[izquierda]->getModelo() == modelo) {
            cochesEncontrados.insertar(coches[izquierda]);
            izquierda--;
        }

        int derecha = indice + 1;
        while (derecha < coches.tamlog() && coches[derecha]->getModelo() == modelo) {
            cochesEncontrados.insertar(coches[derecha]);
            derecha++;
        }
    }

    return cochesEncontrados;
}


ListaDEnlazada<Usuario> ReanelCar::getUsuarios(){
    ListaDEnlazada<Usuario> user;

    Iterador<Usuario> it = usuarios.iterador();
    while(it.haySiguiente()){
        user.insertarFin(it.dato());
        it.siguiente();
    }
    return user;
}


void ReanelCar::setUsuarios(ListaDEnlazada<Usuario> users){
    this->usuarios = users;

}
bool ReanelCar::usuarioConCoche(const std::string& dni){
    // Iteramos sobre la lista de usuarios
    Iterador<Usuario> it = usuarios.iterador();
    while (it.haySiguiente()) {
        const Usuario& usuario = it.dato();
        if (usuario.getDNI() == dni) {
            // Si el usuario tiene un coche alquilado, retornamos true
            if (usuario.getCoche()) { // Asegúrate de tener un método que verifique si el usuario tiene coche
                return true;
            }
            break;
        }
        it.siguiente();
    }
    return false; // No se encontró un coche alquilado para el usuario
}

ReanelCar::~ReanelCar() {
    for (int i = 0; i < coches.tamlog(); ++i) {
        delete coches[i];
        coches[i] = nullptr;
    }
    for (int i = 0; i < alquileres.tamlog(); ++i) {
        delete alquileres[i];
        alquileres[i] = nullptr;
    }
}
