#pragma once

#include <QMainWindow>
#include <QVector>
#include <QLabel>
#include "juego.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void lanzarDado();


private:
    Ui::MainWindow *ui;
    QVector<QLabel*> casillas;
    Juego *juego;

    void crearTablero();
    void actualizarFichas(const std::vector<int> &posiciones);
    void mostrarMensaje(const QString &mensaje);
};
