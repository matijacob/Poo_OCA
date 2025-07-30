#pragma once
#include "casilla.h"
#include <QString>

class CasillaNormal : public Casilla {
public:
    CasillaNormal(int posicion, const QString &nombre);
    void aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
