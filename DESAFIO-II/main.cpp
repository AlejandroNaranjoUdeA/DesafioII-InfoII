#include <iostream>
#include <ctime>
#include "equipo.h"
#include "partido.h"

using namespace std;

int main()
{
    srand(time(0)); // aleatoriedad

    Equipo Colombia("Colombia", 10);
    Equipo Brasil("Brasil", 1);

    Colombia.crearJugadores();
    Brasil.crearJugadores();

    Partido p(&Colombia, &Brasil);

    p.simular();
    p.mostrarResultado();

    return 0;
}
