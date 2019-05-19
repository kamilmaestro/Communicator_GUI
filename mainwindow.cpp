#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(600, 250);
    this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginBtn_clicked()
{
    QString userName = ui->loginEditText->text();
    QString password = ui->passwordEditText->text();
    login = new Login(userName, password);
    if((!login->isDataCorrect(userName)) || (!(login->isDataCorrect(password)))){
        QMessageBox::warning(this, "Login", "Incorrect data");
    }else{
        QMessageBox::information(this, "Login", "You are now logged in");
        hide();
        menu = new Menu(this);
        menu->show();
    }
    delete login;
}
