#ifndef DBMANAGER_H
#define DBMANAGER_H
#include "QString"
#include "QDateTime"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "aluno.h"


class DbManager
{
public:
    DbManager(const QString& path);
    bool addAluno(const Aluno& aluno);
    Aluno busca_aluno(const QString& matricula);
    QString listarAlunos();
    QSqlDatabase m_db;
private:

};

#endif // DBMANAGER_H
