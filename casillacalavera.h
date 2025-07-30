#pragma once
#include "casilla.h"

class Jugador;
class Juego;

class CasillaCalavera : public Casilla {
public:
    explicit CasillaCalavera(int posicion);
    void aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
