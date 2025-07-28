#include "CasillaCarcel.h"
#include "Jugador.h"
#include <iostream>
#include "Juego.h"
using namespace std;
void CasillaCarcel::aplicarEfecto(Jugador& jugador, Juego& juego) {
    cout << jugador.getNombre() << " fue a la Cárcel. Pierde 2 turnos." << endl;
    jugador.perderTurnos(2);
}
