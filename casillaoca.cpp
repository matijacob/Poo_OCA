#include "casillaoca.h"
#include "jugador.h"
#include "juego.h"
#include <QDebug>

CasillaOca::CasillaOca(int posicion, int destino)
    : Casilla(posicion, "Oca"), destino(destino) {}

void CasillaOca::aplicarEfecto(Jugador& jugador, Juego& juego) {
    qDebug() << "El jugador" << jugador.getNombre()
    << "cayó en una Oca. Avanza a la casilla"
    << destino << "y obtiene un turno extra.";

    jugador.setPosicion(destino);
    juego.otorgarTurnoExtra(jugador);
}
