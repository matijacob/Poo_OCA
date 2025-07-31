#include "casillacarcel.h"
#include "jugador.h"

CasillaCarcel::CasillaCarcel(int pos)
    : Casilla(pos, "Cárcel"), turnosCastigo(3) {}

QString CasillaCarcel::aplicarEfecto(Jugador& jugador, Juego&) {
    jugador.perderTurnos(turnosCastigo);
    return QString("%1 fue a la Cárcel. Pierde %2 turnos.")
        .arg(jugador.getNombre(), QString::number(turnosCastigo));
}
