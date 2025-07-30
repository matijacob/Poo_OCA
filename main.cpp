#include <QCoreApplication>
#include <QDebug>
#include "juego.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // Crear juego con 2 jugadores (puedes cambiar el número)
    Juego juego(2);

    qDebug() << "===== Juego de la Oca =====";

    // Ejecutar hasta que haya ganador
    while (!juego.estaTerminado()) {
        juego.jugarTurno();
        juego.mostrarEstado();
        qDebug() << "----------------------";
    }

    qDebug() << "Juego finalizado";

    return 0;
}
