#include "partido.h"

//nos sirven para la simulacion:
#include <cstdlib> // rand
#include <ctime>

Partido::Partido(Equipo *e1, Equipo *e2) {

    equipo1= e1;
    equipo2= e2;

    goles1= 0;
    goles2= 0;

}

void Partido::simular(){
    //goles aleatorios (0-4):
    goles1 = rand() % 5;
    goles2 = rand() % 5;

}

void Partido::mostrarResultado(){
    cout << "Resultado del partido: " << endl;
    cout << goles1 << " - " << goles2 << endl;

}
