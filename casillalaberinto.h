#pragma once
#include "casilla.h"

class Jugador;
class Juego;

class CasillaLaberinto : public Casilla {
private:
    int destino;

public:
    explicit CasillaLaberinto(int posicion, int destino);

    void aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
