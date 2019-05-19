#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginBtn_clicked()
{
    QString userName = ui->loginEditText->text();
    QString password = ui->passwordEditText->text();
    Login* loginWindow = new Login(userName, password);
    if((!loginWindow->isDataCorrect(userName)) || (!(loginWindow->isDataCorrect(password)))){
        QMessageBox::information(this, "Login", "Incorrect");
    }

    delete loginWindow;
}
