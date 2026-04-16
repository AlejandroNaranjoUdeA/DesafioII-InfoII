#ifndef GRUPO_H
#define GRUPO_H

#include <iostream>
#include "partido.h"
#include "equipo.h"

using namespace std;

class Grupo
{
private:
    char nombre; // A, B, C...
    Equipo* equipos[4]; // punteros a equipos
    int numEquipos;

public:
    Grupo();

    // Métodos
    void agregarEquipo(Equipo* e);
    void mostrarEquipos();
    void simularPartidos();
};

#endif // GRUPO_H
