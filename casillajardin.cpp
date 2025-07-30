#include "casillajardin.h"
#include "jugador.h"
#include "juego.h"
#include <QDebug>

CasillaJardin::CasillaJardin(int posicionMeta)
    : Casilla(posicionMeta, "Jardín (Meta)") {}

void CasillaJardin::aplicarEfecto(Jugador& jugador, Juego&) {
    if (jugador.getPosicion() == getPosicion()) {
        qDebug() << jugador.getNombre()
        << "ha llegado exactamente a la META y gana el juego!";
    } else if (jugador.getPosicion() > getPosicion()) {
        int exceso = jugador.getPosicion() - getPosicion();
        int nuevaPos = getPosicion() - exceso;
        jugador.setPosicion(nuevaPos);
        qDebug() << jugador.getNombre()
                 << "se pasó de la meta y retrocede a la casilla"
                 << nuevaPos;
    }
}
