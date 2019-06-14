#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = 0);
    ~Registration();

private:

    void on_confirmBtn_accepted();

    void on_confirmBtn_rejected();

private:
    Ui::Registration *ui;
};

#endif // REGISTRATION_H
