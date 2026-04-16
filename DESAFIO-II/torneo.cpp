#include "torneo.h"

Torneo::Torneo() {

    numEquipos= 48;
    equipos= new Equipo[numEquipos];

    numGrupos= 12;
    grupos= new Grupo[numGrupos];

}

Torneo::~Torneo(){
    delete[] equipos;
    delete[] grupos;

}

void Torneo::crearEquipos(){
    for(int i=0; i<numEquipos; i++){
        equipos[i]= Equipo();
        equipos[i].crearJugadores();
    }

}

void Torneo::crearGrupos(){
    for(int i=0; i<numGrupos; i++){
        grupos[i]= Grupo();
    }

}

void Torneo::asignarEquiposAGrupos(){
    int index= 0;

    for(int i=0; i<numGrupos; i++){
        for(int j=0; j<4 ; j++){
            grupos[i].agregarEquipo(&equipos[index]);
            index++;
        }
    }

}

void Torneo::mostrarGrupos() {
    for (int i = 0; i < numGrupos; i++) {
        grupos[i].mostrarEquipos();
        cout << "====================" << endl;
    }

}



