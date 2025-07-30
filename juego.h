#pragma once
#include <vector>
#include "jugador.h"
#include "tablero.h"

class Juego {
private:
    std::vector<Jugador> jugadores;
    Tablero tablero;
    int turnoActual;
    bool terminado;
    bool turnoExtra;

public:
    explicit Juego(int cantidadJugadores);

    void jugarTurno();
    void otorgarTurnoExtra(Jugador& jugador);
    bool estaTerminado() const;
    void mostrarEstado() const;

    std::vector<Jugador>& getJugadores();
    int getTurnoActual() const;

    Casilla* getCasilla(int indice) const;
};
