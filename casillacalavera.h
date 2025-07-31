#pragma once
#include "casilla.h"

class Jugador;
class Juego;

class CasillaCalavera : public Casilla {
public:
    explicit CasillaCalavera(int posicion);
    QString aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
