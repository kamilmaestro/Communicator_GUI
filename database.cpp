#include "database.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

Database::Database() {
    QSqlDatabase dataBase;
    if(QSqlDatabase::contains(databaseName_)) {
        dataBase = QSqlDatabase::database(databaseName_);
    } else {
         dataBase.addDatabase("QPSQL", databaseName_);

         dataBase.setDatabaseName("2019_gebica_rafal");
         dataBase.setHostName("195.150.230.210");
         dataBase.setConnectOptions("sslmode=prefer");
         dataBase.setPort(5434);
         dataBase.setUserName("2019_gebica_rafal");
         dataBase.setPassword("30752");
         bool ok = dataBase.open();

        //TODO: error when ok is false
    }
}

void Database::insert(int sender, int recv, QString msg) {
    QSqlQuery query{QSqlDatabase::database(databaseName_)};
    query.prepare("INSERT INTO communicator.messages (id_sender, id_receiver, content_msg) VALUES (?, ?, ?)");
    query.addBindValue(sender);
    query.addBindValue(recv);
    query.addBindValue(msg);
    auto ok =  query.exec();
    if(!ok) {
        qDebug() << query.lastError().text();
    }
}

QString Database::getMessages(int myId, int secId) {
    QSqlQuery query{QSqlDatabase::database(databaseName_)};
    QString content{};

    query.prepare("SELECT content_msg FROM communicator.messages WHERE id_sender = ? AND id_receiver = ?");
    query.addBindValue(myId);
    query.addBindValue(secId);
    auto ok = query.exec();

    if(!ok)
        qDebug() << query.lastError().text();

    while(query.next()) {
        content.append(query.value(1).toString());
    }
    return content;
}

