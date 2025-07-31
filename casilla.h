#pragma once
#include <QString>

class Jugador;
class Juego;

class Casilla {
protected:
    int posicion;
    QString tipo;

public:
    Casilla(int posicion, const QString &tipo);
    virtual ~Casilla() = default;

    virtual QString aplicarEfecto(Jugador &jugador, Juego &juego) = 0;

    int getPosicion() const { return posicion; }
    QString getTipo() const { return tipo; }
};
