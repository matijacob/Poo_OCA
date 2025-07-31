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
    int ultimoDado = 0;
    QString ultimoMensaje;
public:
    explicit Juego(int cantidadJugadores);

    void jugarTurno();
    void otorgarTurnoExtra(Jugador& jugador);
    bool estaTerminado() const;
    void mostrarEstado() const;

    std::vector<Jugador>& getJugadores();
    int getTurnoActual() const;
    int getUltimoDado() const { return ultimoDado; }
    Casilla* getCasilla(int indice) const;
    QString getUltimoMensaje() const { return ultimoMensaje; }
};
