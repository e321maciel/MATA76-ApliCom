#ifndef LOCALIZAR_H
#define LOCALIZAR_H

#include <QDialog>

namespace Ui {
class Localizar;
}

class Localizar : public QDialog
{
    Q_OBJECT

public:
    explicit Localizar(QWidget *parent = nullptr);
    ~Localizar();

private:
    Ui::Localizar *ui;
};

#endif // LOCALIZAR_H
