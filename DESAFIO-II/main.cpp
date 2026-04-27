#include <iostream>
#include <ctime>
#include "equipo.h"
#include "partido.h"
#include "grupo.h"
#include "torneo.h"

using namespace std;

int main()
{
    srand(time(0));

    Torneo mundial;

    int opcion;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Cargar equipos desde CSV" << endl;
        cout << "2. Ordenar por ranking y crear bombos" << endl;
        cout << "3. Sortear grupos" << endl;
        cout << "4. Mostrar grupos" << endl;
        cout << "5. Simular fase de grupos" << endl;
        cout << "6. Mostrar tablas" << endl;
        cout << "7. Clasificar equipos" << endl;
        cout << "8. Eliminatorias" << endl;
        cout << "9. Mostrar goleadores" << endl;
        cout << "10. Guardar datos en archivo" << endl;
        cout << "0. Salir" << endl;

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){

        case 1:
            mundial.cargarEquiposDesdeCSV();
            break;

        case 2:
            //mundial.ordenarPorRanking();
            //mundial.crearBombos();
            break;

        case 3:
            mundial.crearGrupos();
            mundial.asignarEquiposAGrupos();
            break;

        case 4:
            mundial.mostrarGrupos();
            break;

        case 5:
            mundial.simularFaseDeGrupos();
            break;

        case 6:
            mundial.mostrarTablas();
            break;

        case 7:
            mundial.clasificarEquipos();
            break;

        case 8:
            mundial.simularEliminatorias();
            break;

        case 9:
            mundial.mostrarGoleadores();
            break;

        case 10:
            mundial.guardarDatosJugadores();
            break;

        case 0:
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;
        }

    } while(opcion != 0);

    return 0;
}
