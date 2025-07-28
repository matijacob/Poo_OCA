#pragma once
#include <vector>
#include "Jugador.h"
#include "Casilla.h"
using namespace std;
class Juego {
private:
    vector<Jugador> jugadores;
    vector<Casilla*> tablero;
    int turnoActual;
    bool terminado;

public:
    Juego(int cantidadJugadores);
    ~Juego();

    void jugarTurno();
    bool estaTerminado() const;
    void mostrarEstado() const;
    vector<Casilla*>& getTablero() const;
    Casilla* getCasilla(int indice) const;
    vector<Jugador>& getJugadores();
    int getTurnoActual() const;
};
