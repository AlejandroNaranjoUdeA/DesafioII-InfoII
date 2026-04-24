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
    Equipo** clasificados;
    int numClasificados;
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
    void simularFaseDeGrupos();
    void mostrarTablas();

    void clasificarEquipos();
    void mostrarClasificados();

    void simularEliminatorias();
    Equipo* jugarPartidoEliminacion(Equipo* e1, Equipo* e2);

    void cargarEquiposDesdeCSV();
    void guardarDatosJugadores();

};

#endif // TORNEO_H
