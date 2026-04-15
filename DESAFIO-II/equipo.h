#ifndef EQUIPO_H
#define EQUIPO_H

#include<iostream>
#include<string.h>
#include "jugador.h"

using namespace std;

class Equipo
{
private:
    string pais;
    int ranking;

    Jugador* jugadores;
    int numJugadores;

public:
    Equipo(string p, int r);
    ~Equipo(); //destructor

    // Métodos
    void crearJugadores();
    void mostrarJugadores();
};

#endif // EQUIPO_H
