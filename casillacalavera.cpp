#include "casillacalavera.h"
#include "jugador.h"

CasillaCalavera::CasillaCalavera(int pos)
    : Casilla(pos, "Calavera") {}

QString CasillaCalavera::aplicarEfecto(Jugador& jugador, Juego&) {
    jugador.setPosicion(1);
    return QString("%1 cayó en la Calavera. Vuelve a la casilla 1.")
        .arg(jugador.getNombre());
}
