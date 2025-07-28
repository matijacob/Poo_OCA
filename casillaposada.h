#include "Casilla.h"
#include "Jugador.h"
#include "Juego.h"

class CasillaPosada : public Casilla {
public:
    void aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
