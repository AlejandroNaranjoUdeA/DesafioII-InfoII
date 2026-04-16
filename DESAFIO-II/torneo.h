#ifndef TORNEO_H
#define TORNEO_H

#include <iostream>
#include "equipo.h"
#include "grupo.h"

using namespace std;

class Torneo
{
private:
    Equipo* equipos;
    int numEquipos;

    Grupo* grupos;
    int numGrupos;

public:
    //constructor:
    Torneo();
    //destructor:
    ~Torneo();

    //metodos:
    void crearGrupos();
    void crearEquipos();
    void asignarEquiposAGrupos();
    void mostrarGrupos();

};

#endif // TORNEO_H
