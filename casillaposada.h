#pragma once
#include "casilla.h"

class Jugador;
class Juego;

class CasillaPosada : public Casilla {
private:
    int turnosBloqueo;

public:
    explicit CasillaPosada(int posicion);
    QString aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
