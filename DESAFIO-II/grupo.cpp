#include "grupo.h"

Grupo::Grupo(char n) {

    nombre= n;
    numEquipos= 0;

}

void Grupo::agregarEquipo(Equipo *e){
    if (numEquipos < 4) {
        equipos[numEquipos] = e;
        numEquipos++;
    }

}

void Grupo::mostrarEquipos(){
    cout << "Grupo " << nombre << ":" << endl;

    for(int i=0; i<numEquipos; i++){
        equipos[i]->mostrarJugadores(); //por ahora muestra toda la informacion
        cout << "-------------------" << endl;
    }

}

void Grupo::simularPartidos(){
    cout << "Partidos del Grupo " << nombre << endl;

    //todos contra todos (son 6 partidos)
    for(int i=0; i<numEquipos; i++){
        for(int j=i+1; j<numEquipos; j++){
            Partido p((equipos[i]), equipos[j]);
            p.simular();
            p.mostrarResultado();
            cout << "-------------------" << endl;
        }
    }
}
