#include "torneo.h"

Torneo::Torneo() {

    numEquipos= 48;
    equipos= new Equipo[numEquipos];

    numGrupos= 12;
    grupos= new Grupo[numGrupos];

    clasificados= new Equipo*[32];
    numClasificados= 0;

}

Torneo::~Torneo(){
    delete[] equipos;
    delete[] grupos;

}

void Torneo::crearEquipos(){
    for(int i=0; i<numEquipos; i++){
        equipos[i].setPais("Pais" + to_string(i+1));
        //equipos[i]= Equipo();
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

void Torneo::simularFaseDeGrupos(){
    cout << "===== FASE DE GRUPOS =====" << endl;
    for(int i=0; i<numGrupos; i++){
        grupos[i].simularPartidos();
        cout << "==========================" << endl;
    }

}

void Torneo::mostrarTablas(){
    for(int i=0; i<numGrupos; i++){
        grupos[i].mostrarTabla(); //esta funcion falta por implementar
        cout << "====================" << endl;
    }

}

void Torneo::clasificarEquipos(){

    Equipo* terceros[12];

    //recorremos los grupos:
    for(int i=0; i<numGrupos; i++){
        grupos[i].ordenarTabla();

        //el top 2 clasifican directo:
        clasificados[numClasificados++]= grupos[i].getEquipo(0); //top 1
        clasificados[numClasificados++]= grupos[i].getEquipo(1); //top 2

        //mejores terceros:
        terceros[i]= grupos[i].getEquipo(2);

    }

    //necesitamos ordenar los terceros:
    for(int i=0; i<11; i++){
        for(int j=0; j<11-i; j++){

            bool cambiar= false;

            if(terceros[j]->getPuntos()<terceros[j+1]->getPuntos()){
                cambiar= true;
            }
            else if(terceros[j]->getPuntos()==terceros[j+1]->getPuntos()){
                if(terceros[j]->getDiferenciaGoles()<terceros[j+1]->getDiferenciaGoles()){
                    cambiar= true;
                }
                else if(terceros[j]->getDiferenciaGoles()==terceros[j+1]->getDiferenciaGoles()){
                    if(terceros[j]->getGolesFavor()<terceros[j+1]->getGolesFavor()){
                        cambiar= true;
                    }
                }
            }

            if(cambiar){
                Equipo *temp= terceros[j];
                terceros[j]= terceros[j+1];
                terceros[j+1]= temp;
            }
        }

    }

    //tomamos los mejores 8:

    for(int i=0; i<8; i++){
        clasificados[numClasificados++]= terceros[i];
    }

}

void Torneo::mostrarClasificados(){

    cout << "===== CLASIFICADOS =====" << endl;

    for(int i=0; i<numClasificados; i++){
        cout << i+1 << ". " << clasificados[i]->getPais() << endl;
    }

}



