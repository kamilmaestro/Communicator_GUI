#ifndef USER_H
#define USER_H

#include "iostream"
#include "algorithm"
#include <QString>

class User
{
public:
    User(QString userName, QString password);
    User(QString userName, QString password, bool isCorrect);
    ~User() = default;
    bool isDataCorrect(QString data);
    void checkContent(char letter);
private:
    const int MIN_LETTERS = 5;
    const int MAX_LETTERS = 25;
    QString userName;
    QString password;
};

#endif // USER_H
