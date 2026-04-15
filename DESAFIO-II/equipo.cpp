#include "equipo.h"

Equipo::Equipo(string p, int r) {
    pais= p;
    ranking= r;

    numJugadores= 26;
    jugadores= new Jugador[numJugadores]; //reservamos memoria dinamica para los jugadores

}

Equipo::~Equipo(){
    delete[] jugadores;

}

void Equipo::crearJugadores(){
    for(int i=0; i<numJugadores; i++){
        jugadores[i]= Jugador("nombre" + to_string(i + 1),"apellido" + to_string(i + 1), i + 1);
    }

}

void Equipo::mostrarJugadores(){
    cout << "Equipo: " << pais << endl;

    for(int i=0; i<numJugadores; i++){
        jugadores[i].mostrar();
    }

}
