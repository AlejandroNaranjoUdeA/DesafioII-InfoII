#include "equipo.h"

// constructor
Equipo::Equipo() {
    pais = "";
    ranking = 0;

    numJugadores = 26;
    jugadores = new Jugador[numJugadores];

    puntos = 0;
    golesFavor = 0;
    golesContra = 0;
    partidosJugados = 0;

    golesFavor = golesHistoricos;
    golesContra = golesContraHistoricos;
}

// destructor
Equipo::~Equipo() {
    delete[] jugadores;
}

// crear jugadores
void Equipo::crearJugadores() {
    for (int i = 0; i < numJugadores; i++) {
        jugadores[i] = Jugador(
            "nombre" + to_string(i + 1),
            "apellido" + to_string(i + 1),
            i + 1
            );
    }
}

// mostrar jugadores
void Equipo::mostrarJugadores() {
    cout << "Equipo: " << pais << endl;

    for (int i = 0; i < numJugadores; i++) {
        jugadores[i].mostrar();
    }
}

// setters
void Equipo::setPais(string p) {
    pais = p;
}

void Equipo::setRanking(int r) {
    ranking = r;
}

// getter
string Equipo::getPais() {
    return pais;
}

// estadísticas
void Equipo::sumarPuntos(int p) {
    puntos += p;
}

void Equipo::agregarGoles(int gf, int gc) {
    golesFavor += gf;
    golesContra += gc;
}

void Equipo::sumarPartido() {
    partidosJugados++;
}

int Equipo::getPuntos() {
    return puntos;
}

int Equipo::getGolesFavor() {
    return golesFavor;
}

int Equipo::getDiferenciaGoles() {
    return golesFavor - golesContra;
}

// promedios
float Equipo::getPromedioGolesFavor() {
    if (partidosJugados == 0) return 1.2; // valor inicial
    return (float)golesFavor / partidosJugados;
}

float Equipo::getPromedioGolesContra() {
    if (partidosJugados == 0) return 1.2;
    return (float)golesContra / partidosJugados;
}

void Equipo::setGolesHistoricos(int g){
    golesHistoricos = g;
}

void Equipo::setGolesContraHistoricos(int g){
    golesContraHistoricos = g;
}
