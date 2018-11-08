#ifndef ALUNO_H
#define ALUNO_H
#include "QString"
#include "QDateTime"

class Aluno
{
public:
    Aluno();
    Aluno(const QString& matricula, const QString& name, const QString& endereco, const QString& email,
          const QDateTime& data_nascimento, const QString& cpf, const QString& telefone, const QByteArray & imagem);
    int id;
    QString matricula;
    QString nome;
    QString endereco;
    QString email;
    QString cpf;
    QString telefone;
    QDateTime data_nascimento;
    QByteArray imagem;
};

#endif // ALUNO_H
