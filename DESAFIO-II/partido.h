#ifndef PARTIDO_H
#define PARTIDO_H

#include<iostream>
#include "equipo.h"

using namespace std;

class Partido
{
private:
    Equipo *equipo1;
    Equipo *equipo2;

    int goles1;
    int goles2;

public:
    Partido(Equipo *e1, Equipo *e2);

    // Métodos
    void simular();
    void mostrarResultado();
};

#endif // PARTIDO_H
