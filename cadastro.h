#ifndef CADASTRO_H
#define CADASTRO_H
#include <QString>



class Cadastro
{
public:
    Cadastro();
    QString getPessoa();
    void setPessoa(const QString &value);
    QString getIndicador() const;
    void setIndicador(const QString &value);
    QString getLivro() const;
    void setLivro(const QString &value);
    QString getAutor() const;
    void setAutor(const QString &value);
    QString getGenero() const;
    void setGenero(const QString &value);
    int getPaginas() const;
    void setPaginas(int value);

    double getNotas() const;
    void setNotas(double value);
    int size();

private:
    QString pessoa;
    QString indicador;
    QString livro;
    QString autor;
    double notas;
    QString genero;
    int paginas;
};

#endif // CADASTRO_H
