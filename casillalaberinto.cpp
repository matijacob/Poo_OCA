#include "casillalaberinto.h"
#include "jugador.h"
#include "juego.h"
#include <QDebug>

CasillaLaberinto::CasillaLaberinto(int posicion, int destino)
    : Casilla(posicion, "Laberinto"), destino(destino) {}

void CasillaLaberinto::aplicarEfecto(Jugador& jugador, Juego& juego) {
    qDebug() << jugador.getNombre()
    << "ha caído en el Laberinto y retrocede a la casilla"
    << destino;

    jugador.setPosicion(destino);
    juego.getCasilla(destino)->aplicarEfecto(jugador, juego);
}
