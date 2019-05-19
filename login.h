#ifndef LOGIN_H
#define LOGIN_H

#include "iostream"
#include "algorithm"
#include <QString>

class Login
{
public:
    Login(QString userName, QString password);
    Login(QString userName, QString password, bool isCorrect);
    ~Login() = default;
    bool isDataCorrect(QString data);
    void checkContent(char letter);
private:
    QString userName;
    QString password;
};

#endif // LOGIN_H
