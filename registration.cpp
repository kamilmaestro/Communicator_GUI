#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}


void Registration::on_confirmBtn_accepted()
{
    QMessageBox::information(this, "ok", "ok");
}

void Registration::on_confirmBtn_rejected()
{
    QMessageBox::information(this, "nope", "rejected");
}
