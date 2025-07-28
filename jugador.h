#pragma once
#include <string>
using namespace std;

class Jugador {
    string nombre;
    int posicion;
    int turnosPerdidos;
public:
    Jugador(const string& nombre);

    string getNombre() const;
    int getPosicion() const;
    void setPosicion(int pos);
    void avanzar(int cantidad);
    void retroceder(int cantidad);
    void perderTurnos(int cantidad);
    void reducirTurno();
    bool puedeJugar() const;
};
