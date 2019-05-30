#ifndef MENU_H
#define MENU_H

#include <QDialog>
class QSqlDatabase;

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private:
    Ui::Menu *ui;
 //   QSqlDatabase *dataBase = nullptr;
};

#endif // MENU_H
