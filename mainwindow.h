#include <QMainWindow>
#include "juego.h"
#include <QListWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnLanzarDado_clicked();
    void on_btnNuevoJuego_clicked();

    void on_listaJugadores_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_lblEstadoJuego_linkActivated(const QString &link);

    void on_QListWidgetItem_cellActivated(int row, int column);

private:
    Ui::MainWindow *ui;
    Juego* juego;

    void actualizarEstado();
    void mostrarMensaje(QString mensaje);
    void actualizarListaJugadores();
};
