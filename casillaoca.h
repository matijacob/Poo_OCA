#include "Casilla.h"
#include "Jugador.h"
#include "Juego.h"

class CasillaOca : public Casilla {
private:
    int destino;
public:
    CasillaOca(int destino);
   void aplicarEfecto(Jugador& jugador, Juego& juego) override;
};
