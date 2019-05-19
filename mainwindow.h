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

private slots:
    void on_loginBtn_clicked();

private:
    Ui::MainWindow *ui;
    Menu *menu;
    Login *login;
};

#endif // MAINWINDOW_H
