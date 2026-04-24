#ifndef EQUIPO_H
#define EQUIPO_H

#include <iostream>
#include "jugador.h"

using namespace std;

class Equipo {
private:
    string pais;
    int ranking;

    Jugador* jugadores;
    int numJugadores;

    // estadísticas
    int puntos;
    int golesFavor;
    int golesContra;
    int partidosJugados;

public:
    // constructores
    Equipo();
    ~Equipo();

    // gestión de jugadores
    void crearJugadores();
    void mostrarJugadores();

    // setters
    void setPais(string p);
    void setRanking(int r);

    // getters
    string getPais();

    // estadísticas
    void sumarPuntos(int p);
    void agregarGoles(int gf, int gc);
    void sumarPartido();

    int getPuntos();
    int getGolesFavor();
    int getDiferenciaGoles();

    float getPromedioGolesFavor();
    float getPromedioGolesContra();

    int golesHistoricos;
    int golesContraHistoricos;

    void setGolesHistoricos(int g);
    void setGolesContraHistoricos(int g);

    Jugador* getJugador(int i);
};

#endif // EQUIPO_H
