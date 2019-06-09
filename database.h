#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace database {
QSqlDatabase &connect();
QSqlQuery &getMessages(int id1, int id2);
int getId(QString login); //TODO: std::optional
int getId(QString login, QString password);
}

#endif // DATABASE_H

