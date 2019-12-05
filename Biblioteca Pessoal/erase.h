#ifndef ERASE_H
#define ERASE_H
#include <QMessageBox>
#include "cadastro.h"
#include <algorithm>
#include <QFile>
#include <QFileDialog>
#include <QVector>
#include <QStringList>

#include <QDialog>

namespace Ui {
class erase;
}

class erase : public QDialog
{
    Q_OBJECT

public:
    explicit erase(QWidget *parent = nullptr);
    ~erase();


private:
    Ui::erase *ui;
    QVector<Cadastro>pexcluir;
};

#endif // ERASE_H
