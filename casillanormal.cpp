#include "casillanormal.h"
#include "jugador.h"
#include <QDebug>

CasillaNormal::CasillaNormal(int posicion, const QString &nombre)
    : Casilla(posicion, nombre) {}

void CasillaNormal::aplicarEfecto(Jugador& jugador, Juego&) {
    qDebug() << "El jugador" << jugador.getNombre()
    << "cayó en una casilla normal.";
}
