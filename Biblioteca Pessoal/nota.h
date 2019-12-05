#ifndef NOTA_H
#define NOTA_H

#include "mooncake.h"
#include "cadastro.h"
#include <QDialog>
#include <QVector>
#include <QString>
#include "variavel.h"
#include <QDebug>

namespace Ui {
class nota;
}

class nota : public QDialog
{

    Q_OBJECT

public:
    explicit nota(QWidget *parent = nullptr);
    ~nota();

     double estrela;
     mooncake temp;



     int size();

     void program();
     void inserirB(mooncake m);
      void preencherTudo(mooncake lapis);

    void setNota(mooncake &lapis);


private slots:
    void on_buttonBox_accepted();


private:
    Ui::nota *ui;



};





#endif // NOTA_H
