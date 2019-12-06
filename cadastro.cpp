#include "cadastro.h"

Cadastro::Cadastro()
{

}

QString Cadastro::getPessoa()
{
    return pessoa;
}

void Cadastro::setPessoa(const QString &value)
{
    if(value.size()>3)
          pessoa = value;

}

QString Cadastro::getIndicador() const
{
    return indicador;
}

void Cadastro::setIndicador(const QString &value)
{
    indicador = value;
}

QString Cadastro::getLivro() const
{
    return livro;
}

void Cadastro::setLivro(const QString &value)
{
    livro = value;

}

QString Cadastro::getAutor() const
{
    return autor;

}

void Cadastro::setAutor(const QString &value)
{
   autor= value;
}

QString Cadastro::getGenero() const
{
    return genero;
}

void Cadastro::setGenero(const QString &value)
{
    genero = value;
}

int Cadastro::getPaginas() const
{
    return paginas;
}

void Cadastro::setPaginas(int value)
{
    paginas = value;
}

double Cadastro::getNotas() const
{
    return notas;
}

void Cadastro::setNotas(double value)
{
    notas = value;
}

