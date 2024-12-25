cmake_minimum_required(VERSION 3.29)
project(gestionTournoi)

set(CMAKE_CXX_STANDARD 20)

add_executable(gestionTournoi main.cpp
        Arbitre.h
        Arbitre.cpp
        Equipe.h
        Equipe.cpp
        Terrain.cpp
        Billet.cpp
        Match.cpp
        Spectateur.cpp
        Zone.cpp)
