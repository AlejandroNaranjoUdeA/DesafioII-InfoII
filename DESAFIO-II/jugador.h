#ifndef JUGADOR_H
#define JUGADOR_H

#include<iostream>
#include<string>
using namespace std;

class Jugador
{
private:
    string nombre;
    string apellido;
    int numero;

    int goles;
    int minutos;
    int amarillas;
    int rojas;
    int faltas;
    int asistencias;
    int partidosJugados;
public:
    Jugador();
    Jugador(string nom, string ape, int num);
    // Métodos
    void mostrar();

    // Getters
    int getGoles();
    int getNumero();

    // Setters
    void sumarGol();
};

#endif // JUGADOR_H
