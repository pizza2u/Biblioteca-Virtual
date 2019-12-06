#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include "dialog.h"
#include <QMainWindow>
#include "cadastro.h"
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include "nota.h"
#include <QVector>
#include <QInputDialog>
#include <QFile>
#include <erase.h>
#include <QDesktopServices>
#include <QUrl>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool procNome(QString n);


     mooncake space;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_cadastrar_clicked();

    void on_actionCarregar_triggered();

    void on_actionSalvar_triggered();


    void on_inserir_clicked();

    void on_alfabetica_clicked();

    void on_pushButton_4_clicked();



    void on_excluir_clicked();

    void on_editar_clicked();

    void on_finish_clicked();

    void on_gen_clicked();

protected:
    Ui::MainWindow *ui;
    Dialog *form2;
    erase *edu;
    //nota *form3;
    void inserirNaTabela(Cadastro a, int linha);

    void limpar();

    nota temp;

};
#endif // MAINWINDOW_H
