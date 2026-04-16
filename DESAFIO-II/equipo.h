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
    Equipo();
    ~Equipo(); //destructor

    // Métodos
    void crearJugadores();
    void mostrarJugadores();
    string getPais();
};

#endif // EQUIPO_H
