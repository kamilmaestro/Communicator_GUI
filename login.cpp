#include "login.h"

Login::Login(QString userName, QString password)
{
    this->userName = userName;
    this->password = password;
}

Login::Login(QString userName, QString password, bool isCorrect)
{
    this->userName = userName;
    this->password = password;
}

bool Login::isDataCorrect(QString data)
{
    if(data.size() < MIN_LETTERS || data.size() > MAX_LETTERS)
        return false;

    for(int i = 0; i < data.size(); i++){
        if(!((data[i] <= 'z' && data[i] >= 'a') || (data[i] <= 'Z' && data[i] >= 'A')))
            return false;
    }
    return true;
}
