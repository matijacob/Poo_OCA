#include "jugador.h"

Jugador::Jugador(const QString &nombre)
    : nombre(nombre), posicion(0), turnosPerdidos(0), atrapado(false) {}

QString Jugador::getNombre() const {
    return nombre;
}

int Jugador::getPosicion() const {
    return posicion;
}

void Jugador::setPosicion(int pos) {
    posicion = pos;
}

void Jugador::avanzar(int cantidad) {
    posicion += cantidad;
}

void Jugador::retroceder(int cantidad) {
    posicion -= cantidad;
    if (posicion < 0) posicion = 0;
}

void Jugador::perderTurnos(int cantidad) {
    turnosPerdidos += cantidad;
}

void Jugador::reducirTurno() {
    if (turnosPerdidos > 0) turnosPerdidos--;
}

bool Jugador::puedeJugar() const {
    return !atrapado && turnosPerdidos == 0;
}

void Jugador::setAtrapado(bool estado) {
    atrapado = estado;
}

bool Jugador::estaAtrapado() const {
    return atrapado;
}
