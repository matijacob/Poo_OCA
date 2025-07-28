#include "Juego.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "casillaoca.h"
#include "../asd/casillanormal.h"
using namespace std;
Juego::Juego(int cantidadJugadores)
    : turnoActual(0), terminado(false) {

    for (int i = 0; i < cantidadJugadores; ++i) {
        jugadores.emplace_back("Jugador " + std::to_string(i + 1));
    }

    for (int i = 0; i < 63; ++i) {
        tablero.push_back(new CasillaNormal());
    }

    tablero[5] = new CasillaOca(9);
}

Juego::~Juego() {
    for (Casilla* casilla : tablero) {
        delete casilla;
    }
}
vector<Jugador>& Juego::getJugadores() {
    return jugadores;
}

int Juego::getTurnoActual() const {
    return turnoActual;
}

void Juego::jugarTurno() {
    if (terminado) return;

    Jugador& jugador = jugadores[turnoActual];
    cout << "Turno de " << jugador.getNombre() << endl;

    if (!jugador.puedeJugar()) {
        cout << jugador.getNombre() << " pierde este turno." << endl;
        jugador.reducirTurno();
    } else {
        int dado = rand() % 6 + 1;
        cout << "Dado: " << dado << endl;

        int nuevaPos = jugador.getPosicion() + dado;
        if (nuevaPos > 62) {
            int retroceso = nuevaPos - 62;
            nuevaPos = 62 - retroceso;
        }

        jugador.setPosicion(nuevaPos);
        tablero[nuevaPos]->aplicarEfecto(jugador, *this);

        if (jugador.getPosicion() == 62) {
            cout << jugador.getNombre() << " ha ganado el juego!" << endl;
            terminado = true;
            return;
        }
    }

    turnoActual = (turnoActual + 1) % jugadores.size();
}

bool Juego::estaTerminado() const {
    return terminado;
}

void Juego::mostrarEstado() const {
    for (const auto& jugador : jugadores) {
        cout << jugador.getNombre() << " está en la casilla " << jugador.getPosicion() << endl;
    }
}

Casilla* Juego::getCasilla(int indice) const {
    return tablero[indice];
}
