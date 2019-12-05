#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;


}

void Dialog::carregarVetor(mooncake copia)
{
   subspace = copia;
}
void Dialog::inicializar_Biblio(mooncake a){

    ui->abencoado->setText(a.space[0].getPessoa());
    ui->mostrarTit->setText(a.space[0].getLivro());
    ui->mostrarAutor->setText(a.space[0].getAutor());
    ui->mostrarGen->setText(a.space[0].getGenero());
    ui->mostrarPag->setText(QString::number(a.space[0].getPaginas()));
    ui->mostrarNota->setText(QString::number(a.space[0].getNotas()));
    ui->todos->setText(QString::number(a.size()));


}

void Dialog::on_anterior_clicked()
{   if(!(pagina==0)) pagina--;
    ui->mostrarTit->setText(subspace.space[pagina].getLivro());
    ui->mostrarAutor->setText(subspace.space[pagina].getAutor());
    ui->mostrarGen->setText(subspace.space[pagina].getGenero());
    ui->mostrarPag->setText(QString::number(subspace.space[pagina].getPaginas()));
    ui->mostrarNota->setText(QString::number(subspace.space[pagina].getNotas()));
}

void Dialog::on_proximo_clicked()
{
   if(!(pagina==subspace.size()-1)) pagina++;
        ui->mostrarTit->setText(subspace.space[pagina].getLivro());
        ui->mostrarAutor->setText(subspace.space[pagina].getAutor());
        ui->mostrarGen->setText(subspace.space[pagina].getGenero());
        ui->mostrarPag->setText(QString::number(subspace.space[pagina].getPaginas()));
        ui->mostrarNota->setText(QString::number(subspace.space[pagina].getNotas()));
}



QString Dialog::getProprietario() const
{
    return proprietario;
}

void Dialog::setProprietario(const QString &value)
{
    proprietario = value;
    ui->abencoado->setText(proprietario);
}

