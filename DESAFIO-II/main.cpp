#include <iostream>
#include <ctime>
#include "equipo.h"
#include "partido.h"
#include "grupo.h"
#include "torneo.h"

using namespace std;

int main()
{
    srand(time(0));

    Torneo mundial;

    mundial.cargarEquiposDesdeCSV();
    mundial.crearGrupos();
    mundial.asignarEquiposAGrupos();

    mundial.mostrarGrupos();

    mundial.simularFaseDeGrupos();
    mundial.mostrarTablas();

    mundial.clasificarEquipos();
    mundial.mostrarClasificados();

    mundial.simularEliminatorias();
    mundial.guardarDatosJugadores();

    return 0;
}
