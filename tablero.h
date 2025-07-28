#include <vector>
#include "Casilla.h"
using namespace std;
class Tablero {
    vector<Casilla*> casillas;
public:
    Tablero();
    ~Tablero();
    Casilla* getCasilla(int numero);
};
