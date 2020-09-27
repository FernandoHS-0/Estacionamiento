#ifndef LUGARES_H
#define LUGARES_H

#include <QDialog>

namespace Ui {
class Lugares;
}

class Lugares : public QDialog
{
    Q_OBJECT

public:
    explicit Lugares(QWidget *parent = nullptr);
    ~Lugares();

private:
    Ui::Lugares *ui;
};

#endif // LUGARES_H
