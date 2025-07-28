#include "CasillaLaberinto.h"
#include "Jugador.h"
#include <iostream>
#include "Juego.h"
using namespace std;
CasillaLaberinto::CasillaLaberinto(int destino) : retrocederA(destino) {}

void CasillaLaberinto::aplicarEfecto(Jugador& jugador, Juego& juego) {
    cout << jugador.getNombre() << " entra al Laberinto. Vuelve a la casilla " << retrocederA << "." << endl;
    jugador.setPosicion(retrocederA);
}
