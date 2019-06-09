#include "menu.h"
#include "ui_menu.h"
#include "database.h"

#include <QMessageBox>
#include <QDebug>
#include <chrono>

#define TIME_SLEEP 10

Menu::Menu(QWidget *parent, int id_) :
    QDialog(parent),
    ui(new Ui::Menu),
    id(id_)
{
    ui->setupUi(this);

}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_sendButton_clicked()
{
    ui->msg->clear();
    auto msg = ui->msg_send->text();
    if(msg.isEmpty() || msg.isNull()) {
        QMessageBox::warning(this, "Error", "Empty message");
        return;
    }

    auto recvLogin = ui->userName->text();
    auto recv = database::getId(recvLogin);
    if(recv == 0) {
        QMessageBox::warning(this, "Warning", "User does not exist :(");
        return;
    }
    auto sender = id;

    auto dataBase = database::connect();

    QSqlQuery query{dataBase};
    query.prepare("INSERT INTO communicator.messages (id_sender, id_receiver, content_msg) VALUES (?, ?, ?)");
    query.addBindValue(sender);
    query.addBindValue(recv);
    query.addBindValue(msg);
    auto ok =  query.exec();

    if(!ok) {
        qDebug() << query.lastError().text();
    }

    query = database::getMessages(sender, recv);
    allignMessages(query);
}

void Menu::on_getMsg_clicked()
{
    ui->msg->clear();
    auto recvLogin = ui->userName->text();
    auto recv = database::getId(recvLogin);

    if(recv == 0) {
        QMessageBox::warning(this, "Warning", "User does not exist :(");
        return;
    }
    auto sender = id;
    auto query = database::getMessages(sender, recv);

    ui->msg->clear();
    allignMessages(query);
  //  std::thread t{&Menu::refreshMessages, sender, recv};
  //  t.join();
}

void Menu::allignMessages(QSqlQuery &query) {
    while(query.next()) {
        auto temp = query.value(1).toInt();
        if(temp == id)
            ui->msg->setAlignment(Qt::AlignRight);
        else
            ui->msg->setAlignment(Qt::AlignLeft);

        ui->msg->append(query.value(0).toString().append('\n'));
        ui->msg_send->clear();
    }
}

 void Menu::refreshMessages(int id1, int id2) {
    qDebug() << "start";
    while(true) {
        auto query = database::getMessages(id1, id2);
        allignMessages(query);
        std::this_thread::sleep_for(std::chrono::seconds(TIME_SLEEP));
        qDebug() << "incentive";
    }

}
