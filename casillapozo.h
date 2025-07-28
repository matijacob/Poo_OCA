#include "Casilla.h"
#include "Juego.h"
#include "Jugador.h"

class CasillaPozo : public Casilla {
    int turnosPerdidos;
public:
    CasillaPozo(int turnos);
    void aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
