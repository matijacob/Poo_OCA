#include "casillacarcel.h"
#include "jugador.h"
#include <QDebug>

CasillaCarcel::CasillaCarcel(int pos)
    : Casilla(pos, "Cárcel"), turnosCastigo(3) {}

void CasillaCarcel::aplicarEfecto(Jugador& jugador, Juego&) {
    qDebug() << jugador.getNombre()
    << "fue a la Cárcel. Pierde" << turnosCastigo << "turnos.";
    jugador.perderTurnos(turnosCastigo);
}
