#include "CasillaCalavera.h"
#include "Jugador.h"
#include <iostream>
#include "Juego.h"
using namespace std;
void CasillaCalavera::aplicarEfecto(Jugador& jugador, Juego& juego) {
    cout << jugador.getNombre() << " cayó en la Calavera. Vuelve a la casilla 1." << endl;
    jugador.setPosicion(1);
}
