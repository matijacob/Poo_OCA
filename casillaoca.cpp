#include "CasillaOca.h"
#include "Jugador.h"
#include "Juego.h"
#include <iostream>
using namespace std;
CasillaOca::CasillaOca(int destino) : destino(destino) {}

void CasillaOca::aplicarEfecto(Jugador& jugador, Juego& juego) {
    cout << jugador.getNombre() << " cayó en una Oca! Avanza a la casilla " << destino + 1 << "\n";
    jugador.setPosicion(destino);
}
