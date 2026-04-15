#include <iostream>
#include <ctime>
#include "equipo.h"
#include "partido.h"
#include "grupo.h"

using namespace std;

int main()
{
    srand(time(0)); // aleatoriedad

    Equipo e1("Colombia", 10);
    Equipo e2("Brasil", 1);
    Equipo e3("Argentina", 2);
    Equipo e4("Francia", 3);

    e1.crearJugadores();
    e2.crearJugadores();
    e3.crearJugadores();
    e4.crearJugadores();

    Grupo grupoA('A');

    grupoA.agregarEquipo(&e1);
    grupoA.agregarEquipo(&e2);
    grupoA.agregarEquipo(&e3);
    grupoA.agregarEquipo(&e4);

    grupoA.mostrarEquipos();
    grupoA.simularPartidos();


    return 0;
}
