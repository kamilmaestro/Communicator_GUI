#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menu.h"
#include "login.h"
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
private slots:
    void on_loginBtn_clicked();

    void on_actionAbout_triggered();

    void on_actionLogin_triggered();

private:
    Ui::MainWindow *ui;
    Menu *menu;
    Login *login;
    const int WINDOW_HEIGHT = 250;
    const int WINDOW_WIDTH = 600;
};

#endif // MAINWINDOW_H
