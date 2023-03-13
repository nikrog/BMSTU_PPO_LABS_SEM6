#ifndef PPO_CONSTANTS_H
#define PPO_CONSTANTS_H

#define NONE -1
#define EMPTY std::string("")
#define DEF_TIME 0
#define MIN_PASSWORD_LEN 5
#define MIN_LOGIN_LEN 1

typedef int date_t;

const std::string USER_NOT_FOUND_ERROR = "\nПользователь не найден!";
const std::string USER_ADD_ERROR = "\nОшибка при добавлении пользователя!";
const std::string USER_DELETE_ERROR = "\nОшибка при удалении пользователя!";
const std::string USER_UPDATE_ERROR = "\nОшибка при обновлении данных пользователя!";
const std::string MANAGER_NOT_FOUND_ERROR = "\nМенеджер не найден!";
const std::string MANAGER_ADD_ERROR = "\nОшибка при добавлении мнеджера!";
const std::string MANAGER_DELETE_ERROR = "\nОшибка при удалении менеджера!";
const std::string MANAGER_UPDATE_ERROR = "\nОшибка при обновлении данных менеджера!";

#endif //PPO_CONSTANTS_H
