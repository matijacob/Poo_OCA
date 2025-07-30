#pragma once
#include <vector>
#include "casilla.h"

class Tablero {
private:
    std::vector<Casilla*> casillas;

public:
    Tablero();
    ~Tablero();

    Casilla* getCasilla(int numero) const;
};
