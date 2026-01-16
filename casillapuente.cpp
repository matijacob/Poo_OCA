#include "casillapuente.h"
#include "jugador.h"

CasillaPuente::CasillaPuente(int pos, int destino)
    : Casilla(pos, "Puente"), destino(destino) {}

QString CasillaPuente::aplicarEfecto(Jugador &jugador, Juego&) {
    jugador.setPosicion(destino);
    return QString(" %1 cruzó el PUENTE y va a la casilla %2!")
        .arg(jugador.getNombre())
        .arg(destino);
}
