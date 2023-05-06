#include "registerclientwindow.h"
#include "ui_registerclientwindow.h"

RegisterClientWindow::RegisterClientWindow(GUIAuthManager &authmanager, GUIClientManager &clientmanager, ILogger &logger, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterClientWindow)
{
    ui->setupUi(this);
    this->clientManager = clientmanager;
    this->authManager = authmanager;
    this->logger = &logger;
}

RegisterClientWindow::~RegisterClientWindow()
{
    delete ui;
}

void RegisterClientWindow::on_enter_clicked()
{
    QMessageBox messageBox;
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
            else
            {
                this->logger->log(INFO, "Register new user attempt");
                this->close();
                RegisterClient2Window *w = new RegisterClient2Window(this->authManager, this->clientManager, *this->logger);
                w->show();
            }
        }
    }
}
