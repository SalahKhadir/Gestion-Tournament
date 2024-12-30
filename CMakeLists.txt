cmake_minimum_required(VERSION 3.29)
project(gestionTournoi)

set(CMAKE_CXX_STANDARD 20)

add_executable(gestionTournoi
        main.cpp
        Arbitre.cpp
        Equipe.cpp
        Terrain.cpp
        Match.cpp
        Tournoi.cpp)
