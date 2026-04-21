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

    mundial.crearEquipos();
    mundial.crearGrupos();
    mundial.asignarEquiposAGrupos();

    mundial.mostrarGrupos();

    mundial.simularFaseDeGrupos();
    mundial.mostrarTablas();


    return 0;
}
