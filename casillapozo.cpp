#include "CasillaPozo.h"
#include "Jugador.h"
#include <iostream>

CasillaPozo::CasillaPozo(int turnos) : turnosPerdidos(turnos) {}

void CasillaPozo::aplicarEfecto(Jugador& jugador, Juego& juego) {
    cout << jugador.getNombre() << " cayó en el Pozo. Pierde " << turnosPerdidos << " turnos." << endl;
    jugador.perderTurnos(turnosPerdidos);
}
