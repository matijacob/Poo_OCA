#include "casillaposada.h"
#include "jugador.h"

CasillaPosada::CasillaPosada(int posicion)
    : Casilla(posicion, "Posada"), turnosBloqueo(1) {}

QString CasillaPosada::aplicarEfecto(Jugador& jugador, Juego&) {
    jugador.perderTurnos(turnosBloqueo);
    return QString("El %1 se detiene en la Posada y pierde %2 turno(s).")
        .arg(jugador.getNombre(), QString::number(turnosBloqueo));
}
