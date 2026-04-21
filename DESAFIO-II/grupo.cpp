#include "grupo.h"

Grupo::Grupo() {

    nombre= '?';
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
        cout << equipos[i]->getPais() << endl;
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

void Grupo::ordenarTabla(){
    for(int i=0; i<numEquipos-1; i++){
        for(int j=0; j<numEquipos-i-1; j++){
            bool cambiar= false;
            if (equipos[j]->getPuntos() < equipos[j+1]->getPuntos()) {
                cambiar = true;
            }
            else if (equipos[j]->getPuntos() == equipos[j+1]->getPuntos()) {

                if (equipos[j]->getDiferenciaGoles() < equipos[j+1]->getDiferenciaGoles()) {
                    cambiar = true;
                }
                else if (equipos[j]->getDiferenciaGoles() == equipos[j+1]->getDiferenciaGoles()) {

                    if (equipos[j]->getGolesFavor() < equipos[j+1]->getGolesFavor()) {
                        cambiar = true;
                    }
                }
            }

            if (cambiar) {
                Equipo* temp = equipos[j];
                equipos[j] = equipos[j+1];
                equipos[j+1] = temp;
            }
        }
    }

}

void Grupo::mostrarTabla() {

    ordenarTabla(); // 🔥 importante

    cout << "Tabla Grupo " << nombre << endl;

    for (int i = 0; i < numEquipos; i++) {
        cout << i+1 << ". "
             << equipos[i]->getPais() << " | "
             << "Pts: " << equipos[i]->getPuntos() << " | "
             << "GF: " << equipos[i]->getGolesFavor() << " | "
             << "DG: " << equipos[i]->getDiferenciaGoles()
             << endl;
    }
}
