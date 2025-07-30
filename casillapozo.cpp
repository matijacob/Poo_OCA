#include "casillapozo.h"
#include "jugador.h"
#include <QDebug>

CasillaPozo::CasillaPozo(int posicion)
    : Casilla(posicion, "Pozo"), hayJugadorAtrapado(false), jugadorAtrapado(nullptr) {}

void CasillaPozo::aplicarEfecto(Jugador& jugador, Juego&) {
    if (!hayJugadorAtrapado) {
        qDebug() << jugador.getNombre()
        << "cayó en el Pozo y queda atrapado hasta que otro jugador caiga.";
        hayJugadorAtrapado = true;
        jugadorAtrapado = &jugador;
        jugador.setAtrapado(true);
    } else {
        qDebug() << jugador.getNombre()
        << "cayó en el Pozo y libera a"
        << jugadorAtrapado->getNombre() << ".";
        jugadorAtrapado->setAtrapado(false);
        hayJugadorAtrapado = true;
        jugadorAtrapado = &jugador;
        jugador.setAtrapado(true);
    }
}
