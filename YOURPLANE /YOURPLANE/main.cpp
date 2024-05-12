#include "PlaneManager.hpp"
#include "CommandParser.hpp"
#include <iostream>
#include <stdexcept>

int main() { 
    std::string commandStr; // Объявляем переменную commandStr типа std::string для хранения введенной команды.
    while (true) { // Бесконечный цикл для ввода команд.
        std::cout << "Enter command (CREATE_PLANE, PLANES_FOR_TOWN, TOWNS_FOR_PLANE, PLANES, or QUIT): "; // Выводим приглашение для ввода команды.
        std::cin >> commandStr; // Считываем введенную команду.

        CommandType command; // Объявляем переменную command типа CommandType для хранения распарсенной команды.
        try { // Начало блока обработки исключений.
            command = CommandParser::parseCommand(commandStr); // Пытаемся распарсить введенную команду.
        } catch (const std::invalid_argument& e) { // Обработка исключения невалидной команды.
            std::cout << e.what() << std::endl; // Выводим сообщение об ошибке.
            continue; // Продолжаем цикл.
        }

        switch (command) { // Выполняем действия в зависимости от распарсенной команды.
            case CommandType::CREATE_PLANE: { // Команда создания самолета.
                std::string planeName; // Объявляем переменную planeName типа std::string для хранения имени самолета.
                std::cin >> planeName; // Считываем имя самолета.
                std::vector<std::string> route; // Создаем вектор route для хранения маршрута.
                std::string town; // Объявляем переменную town типа std::string для временного хранения названия города.
                while (std::cin >> town && town != "END") { // Цикл считывания городов маршрута до ввода "END".
                    route.push_back(town); // Добавляем название города в вектор route.
                }
                PlaneManager::createPlane(planeName, route); // Создаем самолет с указанным именем и маршрутом.
                break; // Завершаем case.
            }
            case CommandType::PLANES_FOR_TOWN: { // Команда получения списка самолетов для заданного города.
                std::string town; // Объявляем переменную town типа std::string для хранения названия города.
                std::cin >> town; // Считываем название города.
                PlaneManager::planesForTown(town); // Выводим список самолетов для заданного города.
                break; // Завершаем case.
            }
            case CommandType::TOWNS_FOR_PLANE: { // Команда получения маршрута для заданного самолета.
                std::string planeName; // Объявляем переменную planeName типа std::string для хранения имени самолета.
                std::cin >> planeName; // Считываем имя самолета.
                PlaneManager::townsForPlane(planeName); // Выводим маршрут для заданного самолета.
                break; // Завершаем case.
            }
            case CommandType::PLANES: { // Команда вывода списка всех самолетов.
                PlaneManager::displayPlanes(); // Выводим список всех самолетов.
                break; // Завершаем case.
            }
            case CommandType::QUIT: { // Команда выхода из программы.
                return 0; // Завершаем выполнение программы.
            }
        }
    }

    return 0; // Возвращаем 0, что означает успешное завершение программы.
}
