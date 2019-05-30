#include "menu.h"
#include "ui_menu.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
   // dataBase{new QSqlDatabase}
{
    ui->setupUi(this);

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
    QSqlQuery query{dataBase};
    query.exec("SELECT * FROM communicator.users;");

    QString str{};
    if(query.first())
         str = query.value(1).toString();
    ui->userName->setText(str);
}

Menu::~Menu()
{
    delete ui;
}
