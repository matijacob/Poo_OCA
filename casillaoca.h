#pragma once
#include "casilla.h"

class Jugador;
class Juego;

class CasillaOca : public Casilla {
private:
    int destino;

public:
    explicit CasillaOca(int posicion, int destino);
    QString aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
