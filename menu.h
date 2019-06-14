#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include <thread>

class QSqlQuery;
namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr, int id_ = 0);
    ~Menu();

private:
    void on_sendButton_clicked();

    void on_getMsg_clicked();


    void allignMessages(QSqlQuery &query);
  [[ noreturn ]] void refreshMessages(int id1, int id2);
    Ui::Menu* ui;
    int id;
};

#endif // MENU_H
