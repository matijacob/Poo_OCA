#include "Casilla.h"
#include "Juego.h"
#include "Jugador.h"

class CasillaCarcel : public Casilla {
public:
    void aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
