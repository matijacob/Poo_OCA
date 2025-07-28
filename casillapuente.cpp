#include "CasillaPuente.h"
#include "Jugador.h"
#include <iostream>

CasillaPuente::CasillaPuente(int destino) : destino(destino) {}

void CasillaPuente::aplicarEfecto(Jugador& jugador, Juego& juego) {
    cout << jugador.getNombre() << " cruzó el puente hacia la casilla " << destino << "." << endl;
    jugador.setPosicion(destino);
   juego.getTablero()[destino]->aplicarEfecto(jugador, juego);
}
