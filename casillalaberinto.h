#include "Casilla.h"
#include "Juego.h"
#include "Jugador.h"

class CasillaLaberinto : public Casilla {
    int retrocederA;
public:
    CasillaLaberinto(int destino);
    void aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
