#include "CasillaPosada.h"
#include "Jugador.h"
#include <iostream>

void CasillaPosada::aplicarEfecto(Jugador& jugador, Juego& juego) {
    cout << jugador.getNombre() << " se detiene en la Posada. Pierde 1 turno." << endl;
    jugador.perderTurnos(1);
}
