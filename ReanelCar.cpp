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
        it.siguiente();
        if (user.getDNI() == nif) {
            return &user;
        }
    }
    return nullptr;
}

/**
 * @brief Buscar usuarios por parte de su nombre
 * @param substring Subcadena a buscar en el nombre de los usuarios.
 * @return Lista de usuarios que contienen la subcadena en su nombre.
 */
ListaDEnlazada<Usuario> ReanelCar::buscarUsrNomb(const std::string& substring) {
    ListaDEnlazada<Usuario> resultados;
    Iterador<Usuario> it = usuarios.iterador();
    while (it.haySiguiente()) {
        Usuario& user = it.dato();
        it.siguiente();
        if (user.getNombre().find(substring) == 0) {
            resultados.insertarFin(user);
        }
    }

    return resultados;
}

/**
 * @brief Buscar coche por matrícula
 * @param matricula Matrícula del coche a buscar.
 * @return Puntero al coche encontrado, o nullptr si no existe.
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
 * @brief Buscar coches por modelo
 * @param modelo Modelo que queremos buscar.
 * @return Un vector dinámico con los coches cuyo modelo coincide.
 */
VDinamico<Coche*> ReanelCar::buscarCochModelo(const std::string &modelo) {
    VDinamico<Coche*> cochesEncontrados;

    for (int i = 0; i < coches.tamlog(); ++i) {
        Coche* coche = coches[i];
        if (coche->getModelo() == modelo && !coche->getAlquilado()) {
            cochesEncontrados.insertar(coche);
        }
    }

    return cochesEncontrados;
}

/**
 * @brief Alquila un coche al usuario especificado.
 * @param usuario Usuario que alquila el coche.
 * @param coche Coche a alquilar.
 * @return true si el alquiler se realiza con éxito, false si ya está alquilado.
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

/**
 * @brief Busca coches por modelo utilizando búsqueda binaria.
 * @param modelo Modelo que queremos buscar.
 * @return Un vector dinámico con los coches cuyo modelo coincide.
 */
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

/**
 * @brief Obtiene la lista de usuarios registrados.
 * @return Lista de usuarios.
 */
ListaDEnlazada<Usuario> ReanelCar::getUsuarios(){
    ListaDEnlazada<Usuario> user;

    Iterador<Usuario> it = usuarios.iterador();
    while(it.haySiguiente()){
        user.insertarFin(it.dato());
        it.siguiente();
    }
    return user;
}

/**
 * @brief Establece la lista de usuarios.
 * @param users Lista de usuarios a establecer.
 */
void ReanelCar::setUsuarios(ListaDEnlazada<Usuario> users){
    this->usuarios = users;
}

/**
 * @brief Verifica si un usuario tiene un coche alquilado.
 * @param dni DNI del usuario a verificar.
 * @return true si el usuario tiene un coche alquilado, false en caso contrario.
 */
bool ReanelCar::usuarioConCoche(const std::string& dni){
    Iterador<Usuario> it = usuarios.iterador();
    while (it.haySiguiente()) {
        const Usuario& usuario = it.dato();
        if (usuario.getDNI() == dni) {
            if (usuario.getCoche()) {
                return true;
            }
            break;
        }
        it.siguiente();
    }
    return false;
}

/**
 * @brief Destructor de la clase ReanelCar.
 */
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