#ifndef REGISTERCLIENT2WINDOW_H
#define REGISTERCLIENT2WINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "../auth_manager/GuiAuthManager.h"
#include "../managers_manager/GuiManagersManager.h"
#include "../client_manager/GuiClientManager.h"
#include "../product_manager/GuiProductManager.h"
#include "../bank_manager/GuiBankManager.h"
#include "../request_manager/GuiRequestManager.h"
#include "../../business_logic/rules/ILogger.h"

namespace Ui {
class RegisterClient2Window;
}

class RegisterClient2Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterClient2Window(GUIAuthManager &authmanager, GUIClientManager &clientmanager, ILogger &logger, QWidget *parent = nullptr);
    ~RegisterClient2Window();

private slots:
    void on_enter_clicked();
    void on_back_clicked();

private:
    Ui::RegisterClient2Window *ui;
    GUIAuthManager authManager;
    GUIClientManager clientManager;
    ILogger *logger;
};
#endif // REGISTERCLIENT2WINDOW_H
