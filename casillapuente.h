#include "Casilla.h"
#include "Juego.h"
#include "Jugador.h"

class CasillaPuente : public Casilla {
    int destino;
public:
    CasillaPuente(int destino);
    void aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
