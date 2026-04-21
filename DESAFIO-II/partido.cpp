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

    float alpha = 0.6;
    float beta = 0.4;
    float mu = 1.35;

    float gfA = equipo1->getPromedioGolesFavor();
    float gcA = equipo1->getPromedioGolesContra();

    float gfB = equipo2->getPromedioGolesFavor();
    float gcB = equipo2->getPromedioGolesContra();

    float lambdaA = mu * (alpha * gfA + beta * gcB);
    float lambdaB = mu * (alpha * gfB + beta * gcA);

    goles1 = (int)(lambdaA + rand()%2);
    goles2 = (int)(lambdaB + rand()%2);

    // 🔥 ACTUALIZAR ESTADÍSTICAS
    equipo1->agregarGoles(goles1, goles2);
    equipo2->agregarGoles(goles2, goles1);

    // 🔥 ESTA ES LA PARTE QUE PREGUNTASTE
    equipo1->sumarPartido();
    equipo2->sumarPartido();

    // puntos
    if (goles1 > goles2) {
        equipo1->sumarPuntos(3);
    } else if (goles2 > goles1) {
        equipo2->sumarPuntos(3);
    } else {
        equipo1->sumarPuntos(1);
        equipo2->sumarPuntos(1);
    }

}

void Partido::mostrarResultado(){
    cout << "Resultado del partido: " << endl;
    cout << goles1 << " - " << goles2 << endl;

}
