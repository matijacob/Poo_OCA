#include "Dado.h"
#include <cstdlib>
#include <ctime>

int Dado::tirar() {
    return 1 + rand() % 6;
}
