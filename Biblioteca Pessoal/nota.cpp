#include "nota.h"
#include "ui_nota.h"

nota::nota(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nota)
{

    ui->setupUi(this);


}

nota::~nota()
{
    delete ui;
}

void nota::on_buttonBox_accepted()
{

   estrela = ui->anota->text().toDouble();

}


void nota::inserirB(mooncake m)
{
    temp = m;
}

void nota::preencherTudo(mooncake copia)
{
   temp = copia;
   for(int i = 0; i < copia.size(); i++){
       ui -> tudo -> addItem(copia.space[i].getLivro());
   }
}

void nota::setNota(mooncake &lapis)
{


    int Index;
    Index= ui->tudo->currentIndex();
    lapis.space[Index].setNotas(ui->anota->text().toDouble());

}


