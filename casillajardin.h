#pragma once
#include "casilla.h"

class Jugador;
class Juego;

class CasillaJardin : public Casilla {
public:
    explicit CasillaJardin(int posicionMeta);
    QString aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
