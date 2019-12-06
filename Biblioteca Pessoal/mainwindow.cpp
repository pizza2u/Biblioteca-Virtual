#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabela->setColumnWidth(0,200);
    ui->tabela->setColumnWidth(1,200);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    close();
}

void MainWindow::on_pushButton_2_clicked()
{
    if(space.size() == 0) QMessageBox::warning(this, "Erro", "Biblioteca vazia!");
    else{
        Dialog form2;
        //form2 = new Dialog(this);
        form2.carregarVetor(space);
        form2.inicializar_Biblio(space);
        form2.setProprietario(ui->pessoa->text());
        form2.exec();
    }
}



void MainWindow::on_pushButton_3_clicked()
{
   QMessageBox::warning(this,"Ajuda","Consulte o manual: https://github.com/pizza2u/Biblioteca-Virtual/blob/master/README.md !");
}

void MainWindow::on_cadastrar_clicked()
{
    Cadastro cadastro;


    cadastro.setLivro(ui->nome->text());
    cadastro.setAutor(ui->autor->text());
    cadastro.setPaginas(ui->paginas->text().toInt());
    cadastro.setGenero(ui->genero->currentText());




        ui->nome->clear();
        ui->autor->clear();
        ui->paginas->clear();

       int quantidade_linhas = ui->tabela->rowCount();

        if(cadastro.getLivro() != "" and cadastro.getAutor() != "" and cadastro.getPaginas() != 0){
            if(!space.naoRepeticao(cadastro)){


            space.inserirLivro(cadastro);




               ui->tabela->insertRow(quantidade_linhas);
                inserirNaTabela(cadastro,quantidade_linhas);

 }else{
                QMessageBox::warning(this,"Erro","Nome repetido");
            }

        }

}
void MainWindow::inserirNaTabela(Cadastro a, int linha)

{

    ui->tabela->setItem(linha,0, new QTableWidgetItem(a.getLivro()));
    ui->tabela->setItem(linha,1, new QTableWidgetItem(a.getAutor()));
    ui->tabela->setItem(linha,2, new QTableWidgetItem(a.getGenero()));
    ui->tabela->setItem(linha,3, new QTableWidgetItem(QString::number(a.getPaginas())));

}



void MainWindow::limpar()
{
    int linhas= ui->tabela->rowCount();
    for(int i=0;i<linhas;i++);
        ui->tabela->removeRow(0);
}



void MainWindow::on_actionCarregar_triggered()
{
    QString temp;
    temp = QFileDialog::getOpenFileName(this,"Carregar","","*.csv");
    space.carregarDados(temp);

    for(int i=0;i<space.size();i++){

    ui->tabela->insertRow(i);
    inserirNaTabela(space[i],i);
}

    }

void MainWindow::on_actionSalvar_triggered()
{
    QString temp;
    temp = QFileDialog::getSaveFileName(this,"Salvar","","*.csv");
    space.salvarDados(temp);
}



void MainWindow::on_inserir_clicked()
{
    nota form3;
    //form3 = new nota(this);
    form3.preencherTudo(space);
    form3.exec();


    form3.setNota(space);
}

void MainWindow::on_alfabetica_clicked()
{
    ui->tabela->clearContents();
    space.ordenarporTitulo();
    for(int i=0;i<space.size();i++){
        inserirNaTabela(space[i],i);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tabela->clearContents();
    space.ordenarporAutor();
    for(int i=0;i<space.size();i++){
        inserirNaTabela(space[i],i);
}
}




void MainWindow::on_excluir_clicked()
{    QMessageBox::StandardButton resp = QMessageBox::question(this, "Excluir Itens", "Você deseja excluir um item?");
     if(resp == QMessageBox::Yes){
             bool ok;

             QString txt = QInputDialog::getText(this, "Excluir Itens", "Digite o título do livro(igualmente a como foi cadastrado) para excluí-lo", QLineEdit::Normal,"",&ok);

             bool apagou = false;

             for(int i = 0; i < space.size(); i++){

                   if(space.space[i].getLivro() == txt){
                       space.apagarTudo(txt, space);
                       apagou = true;
                       break;
                   }


             }





             if(apagou){
                 ui->tabela->setRowCount(0);


                 for(int i=0;i<space.size();i++){
                        ui->tabela->insertRow(i);
                     inserirNaTabela(space[i],i);
                 }

            }

}
}

void MainWindow::on_editar_clicked()
{
    QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Itens", "Você deseja editar um item?");
    if(resp == QMessageBox::Yes){
            bool ok;
            QString txt = QInputDialog::getText(this, "Editar Itens", "Digite o título do livro que quer editar!", QLineEdit::Normal,"",&ok);
            QMessageBox::warning(this, "Alerta", "Caso não queira mudar alguma característica apenas deixe o espaço vazio e aperte ok!");
            QString titulo = QInputDialog::getText(this, "Editar Itens", "Insira o novo Título", QLineEdit::Normal,"",&ok);
            QString autor = QInputDialog::getText(this, "Editar Itens", " Insira o novo nome do AUTOR", QLineEdit::Normal,"",&ok);
            QString genero = QInputDialog::getText(this, "Editar Itens", "Insira o novo gênero?", QLineEdit::Normal,"",&ok);
            QString paginas = QInputDialog::getText(this, "Editar Itens", "Insira a novo quantidade de páginas?", QLineEdit::Normal,"",&ok);

            space.editar(txt,titulo,autor,genero,paginas,space);

            qDebug()<<genero;
            space.ordenarporTitulo();

            for(int i=0;i<space.size();i++)inserirNaTabela(space[i],i);
    }
}

void MainWindow::on_finish_clicked()
{
    QMessageBox::StandardButton resp = QMessageBox::question(this, "Terminei!!", "Agora clique na parte superior esquerda, lá no cantinnho onde está escrito THE END (finalizamos essa história hahaha 😉), e salve sua biblioteca apertando SALVAR!");
}

void MainWindow::on_gen_clicked()
{
    ui->tabela->clearContents();
    space.ordenarporGenero();
    for(int i=0;i<space.size();i++){
        inserirNaTabela(space[i],i);

}

}
