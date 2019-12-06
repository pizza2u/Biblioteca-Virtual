#ifndef DIALOG_H
#define DIALOG_H
#include "mooncake.h"

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
     int pagina=0;
     void carregarVetor(mooncake copia);
      void inicializar_Biblio(mooncake a);
      QString getProprietario() const;
      void setProprietario(const QString &value);

private slots:
      void on_anterior_clicked();

      void on_proximo_clicked();

private:
    Ui::Dialog *ui;
    mooncake subspace;
    QString proprietario;

};

#endif // DIALOG_H
