#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
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

    auto dataBase = database::connect();
    QSqlQuery query{dataBase};

    user = new User(userName, password);


    auto id = database::getId(userName, password);
    if(id == 0) {
        QMessageBox::warning(this, "Login", "Incorrect data");
        return;
    }


    QMessageBox::information(this, "Login", "You are now logged in");
    hide();
    menu = new Menu(this, id);
    menu->show();

    delete user;

}

void MainWindow::on_actionAbout_triggered()
{
    QString title = "Communicator";
    QString text = "This is an application that offers real-time text transmission.";
    handleMsg(title, text);
}

void MainWindow::on_actionLogin_triggered()
{
    QString title = "Rules";
    QString text = "Only letters from the English Alphabet are allowed."
                                 " Your data should be longer than 4 signs but the maximum is 25";
    handleMsg(title, text);
}

void MainWindow::handleMsg(QString title, QString text){
    QMessageBox::information(this, title, text);
}

void MainWindow::on_registerBtn_clicked()
{
    registration = new Registration(this);
    registration->show();
}
