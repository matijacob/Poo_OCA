#include "casillanormal.h"
#include "jugador.h"

CasillaNormal::CasillaNormal(int posicion)
    : Casilla(posicion, "Normal") {}

QString CasillaNormal::aplicarEfecto(Jugador&, Juego&) {
    return QString();
}
