#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>

class Database {
public:
    Database();
    Database(const Database& o) = delete;

    void insert(int sender, int recv, QString msg);
    QString getMessages(int myId, int secId);
    //int getId(QString login); for Kamil with love <3
private:
    constexpr static auto databaseName_ = "MY_DATA_BASE";
};

#endif // DATABASE_H

