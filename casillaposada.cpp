#include "casillaposada.h"
#include "jugador.h"
#include <QDebug>

CasillaPosada::CasillaPosada(int posicion)
    : Casilla(posicion, "Posada"), turnosBloqueo(1) {}

void CasillaPosada::aplicarEfecto(Jugador& jugador, Juego&) {
    qDebug() << "El jugador" << jugador.getNombre()
    << "se detiene en la Posada y pierde 1 turno.";
    jugador.perderTurnos(1);
}
