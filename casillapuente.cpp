#include "casillapuente.h"
#include "jugador.h"
#include <QDebug>

CasillaPuente::CasillaPuente(int pos, int destino)
    : Casilla(pos, "Puente"), destino(destino) {}

void CasillaPuente::aplicarEfecto(Jugador &jugador, Juego&) {
    qDebug() << "Jugador" << jugador.getNombre()
    << "cruzó el PUENTE y va a la casilla"
    << destino << "!";
    jugador.setPosicion(destino);
}
