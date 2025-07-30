#pragma once
#include "casilla.h"

class Jugador;
class Juego;

class CasillaCarcel : public Casilla {
private:
    int turnosCastigo;

public:
    explicit CasillaCarcel(int posicion);
    void aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
