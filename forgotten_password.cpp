#include "forgotten_password.h"
#include "ui_forgotten_password.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

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

    auto dataBase = QSqlDatabase::addDatabase("QPSQL");

   // dataBase.setDatabaseName("/Users/rafalgebica/Desktop/asdf/jeden.sqlite");
    dataBase.setDatabaseName("2019_gebica_rafal");
    dataBase.setHostName("195.150.230.210");
    dataBase.setConnectOptions("sslmode=prefer");
    dataBase.setPort(5434);
    dataBase.setUserName("2019_gebica_rafal");
    dataBase.setPassword("30752");
    bool ok = dataBase.open();

    if(!ok)
        qDebug() << dataBase.lastError().text();

    QSqlQuery query {dataBase};
    query.prepare("select id from communicator.users where name = '"+name+"' and surname = '"+surname+"' and login = '"+login+"');");
    query.exec();
    QString str{};
    if(query.first())
         str = query.value(0).toString();
    qDebug() << str;
    ui->id->setText(str);
}

