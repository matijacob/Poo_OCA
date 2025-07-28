#include "Tablero.h"
#include "CasillaNormal.h"
#include "CasillaOca.h"
#include "CasillaPozo.h"
#include "CasillaPuente.h"
#include "CasillaCalavera.h"

Tablero::Tablero() {
    // Inicializa 63 casillas
    for (int i = 0; i <= 63; ++i) {
        casillas.push_back(new CasillaNormal());
    }

    // Ejemplo de posiciones de casillas especiales
    casillas[6] = new CasillaPuente(12);
    casillas[12] = new CasillaPuente(6);

    casillas[19] = new CasillaPozo(3);
    casillas[31] = new CasillaCalavera();

    // Agregar algunas ocas (pueden tener posiciones como en el juego real)
    casillas[5] = new CasillaOca(9);
    casillas[9] = new CasillaOca(14);
    casillas[14] = new CasillaOca(18);
}

Tablero::~Tablero() {
    for (auto casilla : casillas) {
        delete casilla;
    }
}
