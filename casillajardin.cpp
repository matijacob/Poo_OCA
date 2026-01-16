#include "casillajardin.h"
#include "jugador.h"
#include "juego.h"

CasillaJardin::CasillaJardin(int posicionMeta)
    : Casilla(posicionMeta, "Jardín (Meta)") {}

QString CasillaJardin::aplicarEfecto(Jugador& jugador, Juego&) {
    if (jugador.getPosicion() == getPosicion()) {
        return jugador.getNombre() + " ha llegado exactamente a la META y gana el juego!";
    }
    else if (jugador.getPosicion() > getPosicion()) {
        int exceso = jugador.getPosicion() - getPosicion();
        int nuevaPos = getPosicion() - exceso;
        jugador.setPosicion(nuevaPos);
        return jugador.getNombre() + " se pasó de la meta y retrocede a la casilla "
               + QString::number(nuevaPos);
    }
    return QString();
}
