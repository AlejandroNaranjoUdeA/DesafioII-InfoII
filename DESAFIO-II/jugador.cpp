#include "jugador.h"

//constructor por defecto:
Jugador::Jugador() {
    nombre= "";
    apellido= "";
    numero= 0;

    goles= 0;
    minutos= 0;
    amarillas= 0;
    rojas= 0;
    faltas= 0;
    asistencias= 0;
    partidosJugados= 0;

}

//constructor con parametros:
Jugador::Jugador(string nom, string ape, int num){
    nombre= nom;
    apellido= ape;
    numero= num;

    goles= 0;
    minutos= 0;
    amarillas= 0;
    rojas= 0;
    faltas= 0;
    asistencias= 0;
    partidosJugados= 0;

}

void Jugador::mostrar(){
    cout<<nombre<<" "<<apellido<<" #"<<numero<<endl;

}

int Jugador::getGoles(){
    return goles;

}

int Jugador::getNumero(){
    return numero;

}

void Jugador::sumarGol(){
    goles++;

}
