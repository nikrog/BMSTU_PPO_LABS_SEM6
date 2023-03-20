#ifndef PPO_CONSTANTS_H
#define PPO_CONSTANTS_H

#define NONE -1
#define EMPTY std::string("")
#define DEF_TIME 0
#define MIN_PASSWORD_LEN 5
#define MIN_LOGIN_LEN 1
#define MIN_TIME 1
#define MAX_TIME 7300
#define MIN_SUM 0
#define MAX_SUM 1000000000

typedef int date_t;

const std::string USER_NOT_FOUND_ERROR = "\nПользователь не найден!";
const std::string USER_ADD_ERROR = "\nОшибка при добавлении пользователя!";
const std::string USER_DELETE_ERROR = "\nОшибка при удалении пользователя!";
const std::string USER_UPDATE_ERROR = "\nОшибка при обновлении данных пользователя!";
const std::string MANAGER_NOT_FOUND_ERROR = "\nМенеджер не найден!";
const std::string MANAGER_ADD_ERROR = "\nОшибка при добавлении мнеджера!";
const std::string MANAGER_DELETE_ERROR = "\nОшибка при удалении менеджера!";
const std::string MANAGER_UPDATE_ERROR = "\nОшибка при обновлении данных менеджера!";
const std::string BANK_NOT_FOUND_ERROR = "\nБанк не найден!";
const std::string BANK_ADD_ERROR = "\nОшибка при добавлении банка!";
const std::string BANK_DELETE_ERROR = "\nОшибка при удалении банка!";
const std::string BANK_UPDATE_ERROR = "\nОшибка при обновлении данных банка!";
const std::string CLIENT_NOT_FOUND_ERROR = "\nКлиент не найден!";
const std::string CLIENT_ADD_ERROR = "\nОшибка при добавлении клиента!";
const std::string CLIENT_DELETE_ERROR = "\nОшибка при удалении клиента!";
const std::string CLIENT_UPDATE_ERROR = "\nОшибка при обновлении данных клиента!";
const std::string PRODUCT_NOT_FOUND_ERROR = "\nБанковский продукт не найден!";
const std::string PRODUCT_ADD_ERROR = "\nОшибка при добавлении банковского продукта!";
const std::string PRODUCT_DELETE_ERROR = "\nОшибка при удалении банковского продукта!";
const std::string PRODUCT_UPDATE_ERROR = "\nОшибка при обновлении данных банковского продукта!";
const std::string PRODUCT_GET_ERROR = "\nОшибка при получении банковского продукта!";
const std::string REQUEST_NOT_FOUND_ERROR = "\nЗаявка не найдена!";
const std::string REQUEST_ADD_ERROR = "\nОшибка при добавлении заявки!";
const std::string REQUEST_DELETE_ERROR = "\nОшибка при удалении заявки!";
const std::string REQUEST_UPDATE_ERROR = "\nОшибка при обновлении данных заяки!";
const std::string REQUEST_GET_ERROR = "\nОшибка при получении заявки!";
const std::string REQUEST_MAKE_ERROR = "\nОшибка при попытке сделать заявку!";
const std::string REQUEST_CONFIRM_ERROR = "\nОшибка при одобрении заявки!";
const std::string REQUEST_REJECT_ERROR = "\nОшибка при отклонении заявки!";
const std::string PRODUCT_RATE_ERROR = "\nОшибка при оценке продукта!";

#endif //PPO_CONSTANTS_H
