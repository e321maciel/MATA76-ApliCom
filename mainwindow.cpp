#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addaluno.h"
#include "aluno.h"
#include "dbmanager.h"
#include "QString"
#include "QDebug"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(add_aluno()));    
    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(busca_aluno_por_matricula()));

    DbManager *dbm = new DbManager("C:/Users/maciel/Documents/Ufba/AplicaComerciais/MATA76/academiaUfba/fitnessUfba.db");
    model = new QSqlQueryModel(this);
    model->setQuery(dbm->listarAlunos(),dbm->m_db);
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView->setModel(proxyModel);
    ui->tableView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_aluno()
{
    AddAluno *tela2 = new AddAluno();
    tela2->setWindowTitle("Adicionar Aluno");
    tela2->show();
}

void MainWindow::busca_aluno_por_matricula()
{
    DbManager *dbm = new DbManager("C:/Users/maciel/Documents/Ufba/AplicaComerciais/MATA76/academiaUfba/fitnessUfba.db");
    Aluno Pesquisa = dbm->busca_aluno(ui->lineEdit->text());

    if(Pesquisa.matricula!="")
    {
        AddAluno *tela2 = new AddAluno(NULL, &Pesquisa);
        tela2->setWindowTitle("Consultando aluno");
        tela2->show();    
    }

    dbm->m_db.close();
}

