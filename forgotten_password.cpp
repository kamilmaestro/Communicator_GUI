#include "forgotten_password.h"
#include "ui_forgotten_password.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "database.h"

Forgotten_password::Forgotten_password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Forgotten_password)
{
    ui->setupUi(this);
}

Forgotten_password::~Forgotten_password()
{
    delete ui;
}

void Forgotten_password::on_pushButton_clicked()
{
    auto name = ui->name->text();
    auto surname = ui->surname->text();
    auto login = ui->login->text();
    auto email = ui->email->text();

    auto dataBase = database::connect();

    QSqlQuery query {dataBase};
    query.prepare("select id from communicator.users where name = '"+name+"' and surname = '"+surname+"' and login = '"+login+"');");
    query.exec();
    QString str{};
    if(query.first())
         str = query.value(0).toString();
    qDebug() << str;
    ui->id->setText(str);
}

