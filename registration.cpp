#include "registration.h"
#include "ui_registration.h"
#include "database.h"

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
    auto name = ui->name->text();
    auto surname = ui->surname->text();
    auto login = ui->login->text();
    auto password = ui->password->text();
    auto dataBase = database::connect();

    QSqlQuery query {dataBase};
    query.prepare("INSERT INTO communicator.users (name, surname, login, password) VALUES ('"+name+"','"+surname+"','"+login+"','"+password+"');");
    query.exec();


    QMessageBox::information(this, "ok", "ok");
    close();
}

void Registration::on_confirmBtn_rejected()
{
    close();
}
