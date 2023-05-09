#ifndef MANAGERWINDOW_H
#define MANAGERWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QMessageBox>
#include <fstream>
#include "../auth_manager/GuiAuthManager.h"
#include "../managers_manager/GuiManagersManager.h"
#include "../client_manager/GuiClientManager.h"
#include "../product_manager/GuiProductManager.h"
#include "../bank_manager/GuiBankManager.h"
#include "../request_manager/GuiRequestManager.h"
#include "../../business_logic/rules/ILogger.h"

namespace Ui {
class ManagerWindow;
}

class ManagerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManagerWindow(GUIAuthManager &authmanager, GUIManagersManager &managermanager,
                           GUIClientManager &clientmanager, GUIProductManager &productmanager,
                           GUIBankManager &bankmanager, GUIRequestManager &requestmanager, ILogger &logger, int manager_id, QWidget *parent = nullptr);
    ~ManagerWindow();

private slots:
    void on_search_clicked();
    void on_exit_clicked();
    void on_cl_history_clicked();
    void on_approve_clicked();
    void on_reject_clicked();
    void on_update_password_clicked();
    void on_delete_manager_clicked();

private:
    Ui::ManagerWindow *ui;
    GUIAuthManager authManager;
    GUIManagersManager managerManager;
    GUIClientManager clientManager;
    GUIProductManager productManager;
    GUIBankManager bankManager;
    GUIRequestManager requestManager;
    ILogger *logger;
    int manager_id;
};

#endif // MANAGERWINDOW_H
