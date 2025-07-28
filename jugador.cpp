#include "Jugador.h"
using namespace std;
Jugador::Jugador(const string& nombre) : nombre(nombre), posicion(0), turnosPerdidos(0) {}

string Jugador::getNombre() const {
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
    return turnosPerdidos == 0;
}
