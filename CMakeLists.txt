cmake_minimum_required(VERSION 3.26)
project(PR3_definitivo)

set(CMAKE_CXX_STANDARD 17)

add_executable(PR3_definitivo main.cpp
        Coche.cpp
        Coche.h
        Iterador.h
        ListaDEnlazada.h
        Nodo.h
        ReanelCar.h
        Usuario.h
        VDinamico.h
        main2.cpp
        ReanelCar.cpp)
