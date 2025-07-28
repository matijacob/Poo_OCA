#pragma once
#include "Casilla.h"
#include "Juego.h"
#include "Jugador.h"

class CasillaCalavera : public Casilla {
public:
    void aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
