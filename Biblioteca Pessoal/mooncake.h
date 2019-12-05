#ifndef MOONCAKE_H
#define MOONCAKE_H
#include <QString>
#include <QFile>
#include <algorithm>
#include <QStringList>
#include <QVector>
#include "cadastro.h"
#include "algorithm"
#include <QDebug>



class mooncake : public Cadastro
{
public:
    mooncake();

    Cadastro operator[](int indice);
    void salvarDados(QString file);
    void carregarDados(QString file);
    void ordenarporTitulo();
    void ordenarporGenero();
    void ordenarporNota();
    void ordenarporAutor();
    void inserirLivro(Cadastro b);
    bool naoRepeticao(Cadastro oi);

    void apagarTudo(QString oh,mooncake &nao);

    void editar(QString txt, QString titulo,QString autor, QString genero,QString paginas,mooncake &outro);
    int size();

    QVector<Cadastro> space;
};

#endif // MOONCAKE_H
