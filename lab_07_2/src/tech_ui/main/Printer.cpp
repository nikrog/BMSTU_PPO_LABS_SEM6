#include "Printer.h"


void AppPrinter::print_menu() {
    std::cout << MENU_ENTRIES;
}

void AppPrinter::print_not_a_command()
{
    std::cout << NOT_COMMAND << std::endl;
}

void AppPrinter::print_not_role()
{
    std::cout << NOT_ROLE << std::endl;
}

void AppPrinter::print_unauth_success()
{
    std::cout << UNAUTH_SUCCESS << std::endl;
}