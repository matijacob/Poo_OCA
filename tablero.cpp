#include "tablero.h"
#include "casillanormal.h"
#include "casillaoca.h"
#include "casillapuente.h"
#include "casillapozo.h"
#include "casillacalavera.h"
#include "casillaposada.h"
#include "casillalaberinto.h"
#include "casillacarcel.h"
#include "casillajardin.h"

Tablero::Tablero() {

    for (int i = 0; i <= 63; ++i) {
        casillas.push_back(new CasillaNormal(i, "Casilla Normal"));
    }


    delete casillas[6];  casillas[6]  = new CasillaPuente(6, 12);


    delete casillas[9];  casillas[9]  = new CasillaOca(9, 18);
    delete casillas[18]; casillas[18] = new CasillaOca(18, 27);
    delete casillas[27]; casillas[27] = new CasillaOca(27, 36);
    delete casillas[36]; casillas[36] = new CasillaOca(36, 45);
    delete casillas[45]; casillas[45] = new CasillaOca(45, 54);
    delete casillas[54]; casillas[54] = new CasillaOca(54, 63);

    delete casillas[19]; casillas[19] = new CasillaPosada(19);


    delete casillas[31]; casillas[31] = new CasillaPozo(31);


    delete casillas[42]; casillas[42] = new CasillaLaberinto(42, 30);


    delete casillas[56]; casillas[56] = new CasillaCarcel(56);

    delete casillas[58]; casillas[58] = new CasillaCalavera(58);

    delete casillas[63]; casillas[63] = new CasillaJardin(63);
}

Tablero::~Tablero() {
    for (auto casilla : casillas) {
        delete casilla;
    }
}

Casilla* Tablero::getCasilla(int numero) const {
    if (numero >= 0 && numero < static_cast<int>(casillas.size())) {
        return casillas[numero];
    }
    return nullptr;
}
