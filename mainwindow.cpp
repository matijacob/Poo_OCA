#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , juego(new Juego(2)) // Por ahora, juego de 2 jugadores
{
    ui->setupUi(this);
    actualizarEstado();
    actualizarListaJugadores();
}

MainWindow::~MainWindow() {
    delete ui;
    delete juego;
}

void MainWindow::actualizarEstado() {
    QString turno = QString::fromStdString(juego->getJugadores()[juego->getTurnoActual()].getNombre());
    ui->lblEstadoJuego->setText("Turno de " + turno);
}

void MainWindow::mostrarMensaje(QString mensaje) {
    QMessageBox::information(this, "Mensaje", mensaje);
}

void MainWindow::actualizarListaJugadores() {
    ui->listaJugadores->clear();
    for (const auto& jugador : juego->getJugadores()) {
        QString item = QString::fromStdString(jugador.getNombre()) +
                       " en casilla " + QString::number(jugador.getPosicion());
        ui->listaJugadores->addItem(item);
    }
}

void MainWindow::on_btnLanzarDado_clicked() {
    juego->jugarTurno();
    actualizarEstado();
    actualizarListaJugadores();

    if (juego->estaTerminado()) {
        mostrarMensaje("¡Ganó " + QString::fromStdString(juego->getJugadores()[juego->getTurnoActual()].getNombre()) + "!");
        ui->btnLanzarDado->setEnabled(false);
    }
}

void MainWindow::on_btnNuevoJuego_clicked() {
    delete juego;
    juego = new Juego(2);
    actualizarEstado();
    actualizarListaJugadores();
    ui->btnLanzarDado->setEnabled(true);
}

void MainWindow::on_listaJugadores_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{

}


void MainWindow::on_lblEstadoJuego_linkActivated(const QString &link)
{

}


void MainWindow::on_QListWidgetItem_cellActivated(int row, int column)
{

}

