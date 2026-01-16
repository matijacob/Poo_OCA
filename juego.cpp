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
    qDebug() << "El " << jugador.getNombre()
    << "tiene un turno extra por caer en una Oca.";
    turnoExtra = true;
}

void Juego::jugarTurno() {
    if (terminado) return;

    Jugador &jugador = jugadores[turnoActual];
    ultimoMensaje.clear();

    if (!jugador.puedeJugar()) {
        jugador.reducirTurno();
        ultimoMensaje = QString("Jugador %1 pierde este turno.")
                            .arg(turnoActual + 1);
    } else {
        int dado = rand() % 6 + 1;
        ultimoDado = dado;

        int nuevaPos = jugador.getPosicion() + dado;
        if (nuevaPos > 63) {
            int retroceso = nuevaPos - 63;
            nuevaPos = 63 - retroceso;
        }

        jugador.setPosicion(nuevaPos);


        ultimoMensaje = QString("Jugador %1 sacó %2 y cayó en la casilla %3")
                            .arg(turnoActual + 1)
                            .arg(dado)
                            .arg(jugador.getPosicion());


        Casilla *casilla = tablero.getCasilla(nuevaPos);
        if (casilla) {
            QString efecto = casilla->aplicarEfecto(jugador, *this);
            if (!efecto.isEmpty()) {
                ultimoMensaje += "\n" + efecto;
            }
        }


        if (jugador.getPosicion() == 63) {
            terminado = true;
            ultimoMensaje += "\n¡Jugador " + QString::number(turnoActual + 1) + " ha ganado el juego!";
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
