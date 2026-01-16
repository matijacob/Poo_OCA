#include "casillapozo.h"
#include "jugador.h"

CasillaPozo::CasillaPozo(int posicion)
    : Casilla(posicion, "Pozo"), hayJugadorAtrapado(false), jugadorAtrapado(nullptr) {}

QString CasillaPozo::aplicarEfecto(Jugador& jugador, Juego&) {
    if (!hayJugadorAtrapado) {
        hayJugadorAtrapado = true;
        jugadorAtrapado = &jugador;
        jugador.setAtrapado(true);
        return QString("%1 cayó en el Pozo y queda atrapado hasta que otro jugador caiga.")
            .arg(jugador.getNombre());
    } else {
        QString mensaje = QString("%1 cayó en el Pozo y libera a %2.")
                              .arg(jugador.getNombre(), jugadorAtrapado->getNombre());

        jugadorAtrapado->setAtrapado(false);
        jugadorAtrapado = &jugador;
        jugador.setAtrapado(true);
        return mensaje;
    }
}
