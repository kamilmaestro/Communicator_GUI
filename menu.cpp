#include "menu.h"
#include "ui_menu.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

   auto dataBase = QSqlDatabase::addDatabase("QPSQL", "MY_DATA_BASE");

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

void Menu::on_sendButton_clicked()
{
    auto msg = ui->msg_send->text();
    auto recvLogin = ui->userName->text();
    //auto recv = db->getId(recvLogin);
    auto recv =2; //QString{"2"};
    //auto sender = user->getId();
    auto sender =  1;//QString{"1"};
  /*
    auto dataBase = QSqlDatabase::addDatabase("QPSQL");

     dataBase.setDatabaseName("2019_gebica_rafal");
     dataBase.setHostName("195.150.230.210");
     dataBase.setConnectOptions("sslmode=prefer");
     dataBase.setPort(5434);
     dataBase.setUserName("2019_gebica_rafal");
     dataBase.setPassword("30752");

     bool ok = dataBase.open();

     if(!ok)
         qDebug() << dataBase.lastError().text();*/

    if(QSqlDatabase::contains("MY_DATA_BASE")) {
        auto dataBase = QSqlDatabase::database("MY_DATA_BASE");
        //id1 - mine, id2 - receiver, msg - messages
        QSqlQuery query{dataBase};

        //query.prepare("INSERT INTO communicator.messages VALUES ('" + sender + "', '" + recv + "', '" + msg + "');");
        query.prepare("INSERT INTO communicator.messages (id_sender, id_receiver, content_msg) VALUES (?, ?, ?)");
        query.addBindValue(sender);
        query.addBindValue(recv);
        query.addBindValue(msg);
        auto ok =  query.exec();
        if(!ok) {
            qDebug() << query.lastError().text();
        }
        QString content{};

        query.prepare("SELECT content_msg FROM communicator.messages WHERE id_sender = ? AND id_receiver = ?");
        query.addBindValue(sender);
        query.addBindValue(recv);
        ok = query.exec();

        if(!ok)
            qDebug() << query.lastError().text();

        while(query.next()) {
            content.append(query.value(0).toString()).append('\n');
        }
        ui->msg->setText(content);
        ui->msg->clear();
    }

}
