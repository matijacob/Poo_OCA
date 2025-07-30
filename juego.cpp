#include "juego.h"
#include <cstdlib>
#include <ctime>
#include <QDebug>
#include "casilla.h"

Juego::Juego(int cantidadJugadores)
    : turnoActual(0), terminado(false), turnoExtra(false) {

    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < cantidadJugadores; ++i) {
        jugadores.emplace_back(QString("Jugador %1").arg(i + 1));
    }
}

std::vector<Jugador>& Juego::getJugadores() {
    return jugadores;
}

int Juego::getTurnoActual() const {
    return turnoActual;
}

void Juego::otorgarTurnoExtra(Jugador& jugador) {
    qDebug() << "El jugador" << jugador.getNombre()
    << "tiene un turno extra por caer en una Oca.";
    turnoExtra = true;
}

void Juego::jugarTurno() {
    if (terminado) return;

    Jugador& jugador = jugadores[turnoActual];
    qDebug() << "Turno de" << jugador.getNombre();

    if (!jugador.puedeJugar()) {
        qDebug() << jugador.getNombre() << "pierde este turno.";
        jugador.reducirTurno();
    } else {
        int dado = rand() % 6 + 1;
        qDebug() << "Dado:" << dado;

        int nuevaPos = jugador.getPosicion() + dado;
        if (nuevaPos > 63) {
            int retroceso = nuevaPos - 63;
            nuevaPos = 63 - retroceso;
        }

        jugador.setPosicion(nuevaPos);


        Casilla* casilla = tablero.getCasilla(nuevaPos);
        if (casilla) casilla->aplicarEfecto(jugador, *this);

        if (jugador.getPosicion() == 63) {
            qDebug() << jugador.getNombre() << "ha ganado el juego!";
            terminado = true;
            return;
        }
    }


    if (!turnoExtra)
        turnoActual = (turnoActual + 1) % jugadores.size();
    else
        turnoExtra = false;
}

bool Juego::estaTerminado() const {
    return terminado;
}

void Juego::mostrarEstado() const {
    for (const auto& jugador : jugadores) {
        qDebug() << jugador.getNombre() << "está en la casilla" << jugador.getPosicion();
    }
}

Casilla* Juego::getCasilla(int indice) const {
    return tablero.getCasilla(indice);
}
