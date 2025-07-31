#pragma once
#include "casilla.h"

class CasillaNormal : public Casilla {
public:
    explicit CasillaNormal(int posicion);
    QString aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
