#include "erase.h"
#include "ui_erase.h"

erase::erase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::erase)
{
    ui->setupUi(this);
}

erase::~erase()
{
    delete ui;
}

void erase::apagarTit(QString oh)
{

}

void erase::apagarAutor(QString oh)
{

}

void erase::apagarPag(QString oh)
{

}

void erase::apagarGenero(QString oh)
{

}

void erase::apagarNota(QString oh)
{

}
