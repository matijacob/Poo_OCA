#pragma once
#include "casilla.h"

class Jugador;
class Juego;

class CasillaPuente : public Casilla {
private:
    int destino;

public:
    CasillaPuente(int posicion, int destino);
    QString aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
