#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), juego(new Juego(2))
{
    ui->setupUi(this);
    crearTablero();

    connect(ui->btnLanzarDado, &QPushButton::clicked,
            this, &MainWindow::lanzarDado);


    std::vector<int> posiciones;
    for (const auto &jugador : juego->getJugadores())
        posiciones.push_back(jugador.getPosicion());
    actualizarFichas(posiciones);
}

MainWindow::~MainWindow() {
    delete juego;
    delete ui;
}

void MainWindow::crearTablero() {
    QGridLayout *grid = ui->gridTablero;
    int filas = 7;
    int columnas = 9;

    for (int i = 0; i < 63; ++i) {
        QLabel *label = new QLabel(QString::number(i + 1), this);
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("border: 1px solid black; min-width: 60px; min-height: 60px;");
        casillas.append(label);

        int fila = i / columnas;
        int columna = i % columnas;
        grid->addWidget(label, fila, columna);
    }
}

void MainWindow::actualizarFichas(const std::vector<int> &posiciones) {
    QStringList colores = {"red", "blue", "green", "orange"};

    for (int i = 0; i < casillas.size(); ++i) {
        casillas[i]->setText(QString::number(i + 1));
    }

    for (int j = 0; j < (int)posiciones.size(); ++j) {
        int pos = posiciones[j] - 1;
        if (pos >= 0 && pos < casillas.size()) {
            QString color = colores[j % colores.size()];
            QString texto = QString("%1 <span style='color:%2;'>[J%3]</span>")
                                .arg(casillas[pos]->text(), color, QString::number(j + 1));
            casillas[pos]->setText(texto);
        }
    }
}

void MainWindow::mostrarMensaje(const QString &mensaje) {
    if (ui->lblMensaje)
        ui->lblMensaje->setText(mensaje);
}
void MainWindow::lanzarDado() {
    juego->jugarTurno();

    std::vector<int> posiciones;
    for (const auto &jugador : juego->getJugadores())
        posiciones.push_back(jugador.getPosicion());

    actualizarFichas(posiciones);

    mostrarMensaje(juego->getUltimoMensaje());
    ui->lblTurno->setText(QString("Turno del jugador %1").arg(juego->getTurnoActual() + 1));
}
