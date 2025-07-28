#pragma once

class Jugador;
class Juego;

class Casilla {
public:
    virtual ~Casilla();

    virtual void aplicarEfecto(Jugador& jugador, Juego& juego) = 0;
};

