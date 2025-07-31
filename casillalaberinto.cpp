#include "casillalaberinto.h"
#include "jugador.h"
#include "juego.h"

CasillaLaberinto::CasillaLaberinto(int posicion, int destino)
    : Casilla(posicion, "Laberinto"), destino(destino) {}

QString CasillaLaberinto::aplicarEfecto(Jugador& jugador, Juego& juego) {
    jugador.setPosicion(destino);
    QString mensaje = QString("%1 ha caído en el Laberinto y retrocede a la casilla %2.")
                          .arg(jugador.getNombre())
                          .arg(destino);

    mensaje += "\n" + juego.getCasilla(destino)->aplicarEfecto(jugador, juego);

    return mensaje;
}
