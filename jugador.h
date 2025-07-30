#pragma once
#include <QString>

class Jugador {
    QString nombre;
    int posicion;
    int turnosPerdidos;
    bool atrapado;

public:
    explicit Jugador(const QString& nombre);

    QString getNombre() const;
    int getPosicion() const;
    void setPosicion(int pos);

    void avanzar(int cantidad);
    void retroceder(int cantidad);

    void perderTurnos(int cantidad);
    void reducirTurno();

    bool puedeJugar() const;

    void setAtrapado(bool estado);
    bool estaAtrapado() const;
};
