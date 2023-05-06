#include "registerclient2window.h"
#include "registerclientwindow.h"
#include "ui_registerclient2window.h"

RegisterClient2Window::RegisterClient2Window(GUIAuthManager &authmanager, GUIClientManager &clientmanager, ILogger &logger, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterClient2Window)
{
    ui->setupUi(this);
    this->clientManager = clientmanager;
    this->authManager = authmanager;
    this->logger = &logger;
}

RegisterClient2Window::~RegisterClient2Window()
{
    delete ui;
}

void RegisterClient2Window::on_enter_clicked()
{
    std::string birthdate = this->ui->dateEdit->date().toString("yyyy.MM.dd").toStdString();
    std::cout << birthdate;
    /*QMessageBox messageBox;
    std::string login = this->ui->loginEdit->toPlainText().toStdString();
    std::string password = this->ui->passwdEdit->text().toStdString();
    std::string password_rep = this->ui->passwd2Edit->text().toStdString();
    if ((login.empty()) || (password.empty()) || (password_rep.empty()))
    {
        messageBox.critical(0, "Error", "Все поля должны быть заполнены!");
        messageBox.setFixedSize(500,200);
    }
    else
    {
        try
        {
            int u_id = this->authManager.getUserID(login);
            if (u_id != NONE)
            {
                messageBox.critical(0, "Error", "Данный логин занят! Введите другой!");
                messageBox.setFixedSize(500,200);
            }
        }
        catch (const std::exception &e)
        {
            if (password != password_rep)
            {
                messageBox.critical(0, "Error", "Пароли не совпадают!");
                messageBox.setFixedSize(500,200);
            }
            this->logger->log(INFO, "Register new user");
        }
    }*/

    //ClientInfo inf;
    //this->clientManager.addClient(inf, login, password);
}

void RegisterClient2Window::on_back_clicked()
{
    this->close();
    RegisterClientWindow *w = new RegisterClientWindow(this->authManager, this->clientManager, *this->logger);
    w->show();
}
