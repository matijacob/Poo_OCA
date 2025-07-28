class Jugador;
class Juego; // Declaración adelantada para evitar dependencia circular

class Casilla {
public:
    virtual void aplicarEfecto(Jugador& jugador, Juego& juego) = 0;
    virtual ~Casilla() {}
};
