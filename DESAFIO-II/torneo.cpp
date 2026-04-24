#include "torneo.h"
#include <fstream>
#include <sstream>

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

    string paises[48]= {

};




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

Equipo* Torneo::jugarPartidoEliminacion(Equipo* e1, Equipo* e2){

    Partido p(e1,e2);
    p.simular();
    p.mostrarResultado();

    //desempate:
    if(rand()%2==0){
        return e1;
    }
    else{
        return e2;
    }

}

void Torneo::simularEliminatorias(){

    cout << "===== ELIMINATORIAS =====" << endl;

    Equipo* rondaActual[32];

    //copiamos los clasificados:
    for(int i=0; i<32; i++){
        rondaActual[i]= clasificados[i];
    }

    int equiposRestantes= 32;

    while(equiposRestantes>1){

        cout << "---- RONDA DE " << equiposRestantes << " ----" << endl;

        Equipo* siguienteRonda[32];
        int index =0;

        for(int i=0; i<equiposRestantes; i+= 2){

            cout<<rondaActual[i]->getPais()<<" vs "<<rondaActual[i+1]->getPais()<<endl;

            Equipo *ganador= jugarPartidoEliminacion(rondaActual[i], rondaActual[i+1]);

            cout << "Ganador: " << ganador->getPais() << endl;
            cout << "-------------------" << endl;

            siguienteRonda[index++]= ganador;
        }

        //seguimos con otra ronda
        equiposRestantes /= 2;

        for(int i=0; i<equiposRestantes; i++){
            rondaActual[i]= siguienteRonda[i];
        }
    }

    cout << " CAMPEON: " << rondaActual[0]->getPais() << endl;

}

void Torneo::cargarEquiposDesdeCSV(){

    ifstream archivo("selecciones_clasificadas_mundial.csv");

    if(!archivo.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
        return;
    }

    string linea;

    //nos saltamos las 2 primeras lineas que son innecesarias:

    getline(archivo, linea);
    getline(archivo, linea);

    int i=0;

    while(getline(archivo, linea) && i<numEquipos){

        stringstream ss(linea);
        string campo;

        // columnas
        string rankingStr, pais, gfStr, gcStr;

        getline(ss, rankingStr, ';'); // 0
        getline(ss, pais, ';');       // 1

        // saltar columnas innecesarias (2,3,4)
        for (int j = 0; j < 3; j++) {
            getline(ss, campo, ';');
        }

        getline(ss, gfStr, ';'); // 5 goles a favor
        getline(ss, gcStr, ';'); // 6 goles en contra

        int ranking = stoi(rankingStr);
        int gf = stoi(gfStr);
        int gc = stoi(gcStr);

        equipos[i].setPais(pais);
        equipos[i].setRanking(ranking);

        // 🔥 guardar datos históricos
        equipos[i].setGolesHistoricos(gf);
        equipos[i].setGolesContraHistoricos(gc);

        equipos[i].crearJugadores();

        i++;
    }

    archivo.close();

}



