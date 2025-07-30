#pragma once
#include "casilla.h"

class Jugador;
class Juego;

class CasillaPosada : public Casilla {
private:
    int turnosBloqueo;

public:
    explicit CasillaPosada(int posicion);
    void aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
