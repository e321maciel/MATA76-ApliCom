#include "localizar.h"
#include "ui_localizar.h"

Localizar::Localizar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Localizar)
{
    ui->setupUi(this);
}

Localizar::~Localizar()
{
    delete ui;
}
