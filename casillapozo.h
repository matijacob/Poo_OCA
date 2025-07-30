#pragma once
#include "casilla.h"

class Jugador;
class Juego;

class CasillaPozo : public Casilla {
private:
    bool hayJugadorAtrapado;
    Jugador* jugadorAtrapado;

public:
    explicit CasillaPozo(int posicion);

    void aplicarEfecto(Jugador& jugador, Juego& juego) override;

    bool estaJugadorAtrapado() const { return hayJugadorAtrapado; }
    Jugador* obtenerJugadorAtrapado() const { return jugadorAtrapado; }
    void liberarJugador() { hayJugadorAtrapado = false; jugadorAtrapado = nullptr; }
};
