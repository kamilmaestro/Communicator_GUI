#ifndef FORGOTTEN_PASSWORD_H
#define FORGOTTEN_PASSWORD_H

#include <QDialog>

namespace Ui {
class Forgotten_password;
}

class Forgotten_password : public QDialog
{
    Q_OBJECT

public:
    explicit Forgotten_password(QWidget *parent = nullptr);
    ~Forgotten_password();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Forgotten_password *ui;
};

#endif // FORGOTTEN_PASSWORD_H
