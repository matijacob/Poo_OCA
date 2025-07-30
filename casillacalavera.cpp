#include "casillacalavera.h"
#include "jugador.h"
#include <QDebug>

CasillaCalavera::CasillaCalavera(int pos)
    : Casilla(pos, "Calavera") {}

void CasillaCalavera::aplicarEfecto(Jugador& jugador, Juego&) {
    qDebug() << jugador.getNombre()
    << "cayó en la Calavera. Vuelve a la casilla 1.";
    jugador.setPosicion(1);
}
