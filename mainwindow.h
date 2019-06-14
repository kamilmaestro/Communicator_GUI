#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menu.h"
#include "user.h"
#include "registration.h"
#include "qmessagebox.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void handleMsg(QString title, QString text);
private:
    void on_loginBtn_clicked();

    void on_actionAbout_triggered();

    void on_actionLogin_triggered();

    void on_registerBtn_clicked();

private:
    Ui::MainWindow *ui;
    Menu *menu;
    User *user;
    Registration *registration;
    const int WINDOW_HEIGHT = 250;
    const int WINDOW_WIDTH = 600;
};

#endif // MAINWINDOW_H
