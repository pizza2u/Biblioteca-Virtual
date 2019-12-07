#include "mooncake.h"

mooncake::mooncake()
{

}

Cadastro mooncake::operator[](int indice)
{
    return space[indice];

}

void mooncake::salvarDados(QString file)
{
    QFile book(file);
    book.open(QIODevice::WriteOnly);
    for(auto cool : space){
        QString tecl = cool.getLivro() + "," + cool.getAutor() + "," + cool.getGenero() + "," + QString::number(cool.getPaginas()) + "," + QString::number(cool.getNotas()) + "\n";
           book.write(tecl.toLocal8Bit());
    }
    book.close();
}

void mooncake::carregarDados(QString file)
{
    QFile arquivo(file);
    arquivo.open(QIODevice::ReadOnly);
    QString linha;
    QStringList dados;
    while(!arquivo.atEnd()){
       Cadastro temp;
        linha = arquivo.readLine();
        dados = linha.split(";");
        temp.setLivro(dados[0]);
        temp.setAutor(dados[1]);
        temp.setGenero(dados[2]);
        temp.setPaginas(dados[3].toDouble());
        temp.setNotas(dados[4].toDouble());

       inserirLivro(temp);
    }
    arquivo.close();
}

void mooncake::ordenarporTitulo()
{
    std::sort(space.begin(),space.end(),[](Cadastro c , Cadastro g){
        return c.getLivro() < g.getLivro(); });
}

void mooncake::ordenarporGenero()
{
    std::sort(space.begin(),space.end(),[](Cadastro c , Cadastro g){
        return c.getGenero() < g.getGenero(); });
}

void mooncake::ordenarporAutor()
{
    std::sort(space.begin(),space.end(),[](Cadastro c , Cadastro g){
        return c.getAutor() < g.getAutor(); });
}

void mooncake::inserirLivro(Cadastro b)
{
    space.push_back(b);
}

bool mooncake::naoRepeticao(Cadastro oi)
{
    bool repeticao = false;

    for(int i=0; i< space.size();i++){

    if(oi.getLivro()==space[i].getLivro()){
        repeticao = true;
        break;
    }


    }

    return repeticao;
}

void mooncake::apagarTudo(QString oh, mooncake &nao)
{
    for(int i=0; i<space.size();i++){
       if(nao[i].getLivro()==oh){
          qDebug()<<nao[i].getLivro();
           space.erase(space.begin()+i);



       }
    }
}

void mooncake::editar(QString txt, QString titulo, QString autor, QString genero, QString paginas, mooncake &outro)
{


    for (int i=0; i<outro.size();i++){

       if(outro[i].getLivro() == txt){

          if(titulo!="") outro.space[i].setLivro(titulo);
          if(autor!="") outro.space[i].setAutor(autor);
          if(genero!="") outro.space[i].setGenero(genero);
          if(paginas!="") outro.space[i].setPaginas(paginas.toDouble());

     }
}



}

int mooncake::size()
{
    return space.size();
}
