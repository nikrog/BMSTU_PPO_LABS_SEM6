#ifndef PPO_PRINTER_H
#define PPO_PRINTER_H

#include <iostream>
#include <string>

const std::string MENU_ENTRIES = "\n\n\
0.  Выйти из программы.\n\
1.  Выйти из аккаунта.\n\
2.  Войти в аккаунт.\n\
Введите команду: ";

const std::string NOT_COMMAND = "Такой команды не существует!\nВведите заново!\n\n";
const std::string NOT_ROLE = "Эту команду невозможно выполнить в текущем статусе!\n\n";

class AppPrinter {
public:
     AppPrinter() = default;
     ~AppPrinter() = default;
     void print_menu();
     void print_not_a_command();
     void print_not_role();
};


#endif //PPO_PRINTER_H
