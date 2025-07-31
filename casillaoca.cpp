#include "casillaoca.h"
#include "jugador.h"
#include "juego.h"

CasillaOca::CasillaOca(int posicion, int destino)
    : Casilla(posicion, "Oca"), destino(destino) {}

QString CasillaOca::aplicarEfecto(Jugador& jugador, Juego& juego) {
    jugador.setPosicion(destino);
    juego.otorgarTurnoExtra(jugador);
    return QString("El %1 cayó en una Oca. Avanza a la casilla %2 y obtiene un turno extra.")
        .arg(jugador.getNombre())
        .arg(destino);
}
