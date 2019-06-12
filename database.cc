#include "database.h"
#include <QDebug>

QSqlDatabase& database::connect() {
    static QSqlDatabase dataBase; //due to remain after going out

    if(QSqlDatabase::contains("MY_DATA_BASE"))
        dataBase = QSqlDatabase::database("MY_DATA_BASE");
    else {
        dataBase = QSqlDatabase::addDatabase("QPSQL", "MY_DATA_BASE");

        try{
            dataBase.setDatabaseName("2019_gebica_rafal");
            dataBase.setHostName("195.150.230.210");
            dataBase.setConnectOptions("sslmode=prefer");
            dataBase.setPort(5434);
            dataBase.setUserName("2019_gebica_rafal");
            dataBase.setPassword("30752");
            bool ok = dataBase.open();

            if(!ok){
                qDebug() << "Can not connect to the database"; // TODO: std::optional here
                throw new std::exception;
            }
        }
        catch(const std::exception& e){
            qDebug() << e.what();
        }
    }

    return dataBase;
}

QSqlQuery &database::getMessages(int id1, int id2) {
    auto database = database::connect();
    //TODO: error handling

    static QSqlQuery query{database};
    try{
        query.prepare("SELECT content_msg, id_sender FROM communicator.messages WHERE (id_sender = ? AND id_receiver = ?) OR (id_sender = ? AND id_receiver = ?)");
        query.addBindValue(id1);
        query.addBindValue(id2);
        query.addBindValue(id2);
        query.addBindValue(id1);
        auto ok = query.exec();

        if(!ok){
            qDebug() << query.lastError().text();
            throw new std::exception();
        }
    }catch(const std::exception& e){
        qDebug() << e.what();
    }

    return query;
}

int database::getId(QString login) {
    auto data = connect();

    QSqlQuery query {data};
    try{
        query.prepare("SELECT id FROM communicator.users WHERE login = ?");
        query.addBindValue(login);

        auto ok = query.exec();
        if(!ok){
            qDebug() << query.lastError().text();
            throw new std::exception();
        }

        auto id{0};
        if(query.first()) {
            id = query.value(0).toInt();
        }
    }catch(const std::exception& e){
        qDebug() << e.what();
    }

    return id;
}

int database::getId(QString login, QString password) {
    auto data = connect();
    //TODO: error handling

    QSqlQuery query {data};
    try{
        query.prepare("SELECT id FROM communicator.users WHERE login = ? AND password = ?");
        query.addBindValue(login);
        query.addBindValue(password);

        auto ok = query.exec();
        if(!ok){
            qDebug() << query.lastError().text();
            throw new std::exception;
        }
    }catch(QSqlError error){
        qDebug() << error.databaseText();
    }

    auto id{0};
    if(query.first()) {
        id = query.value(0).toInt();
    }

    return id;
}

