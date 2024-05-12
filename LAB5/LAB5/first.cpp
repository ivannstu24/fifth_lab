#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Cell { // Определение класса Ячейка
public:
    string address; // Строка для хранения адреса ячейки
    map<string, int> products; // Карта для хранения товаров и их количества в ячейке

    Cell(string addr) : address(addr) {} // Конструктор принимает адрес в качестве параметра

    void addProduct(string productName, int quantity) { // Метод для добавления товара в ячейку
        if (products.find(productName) != products.end()) {
            // Проверяем, превышает ли добавляемое количество текущее количество товара
            if (products[productName] + quantity <= 10 && quantity > 0) {
                products[productName] += quantity;
                cout << "Добавлено " << quantity << " единиц товара " << productName << " в ячейку " << address << "." << endl; // Вывод сообщения
            }
            else if (quantity <= 0) {
                cout << "Нельзя добавить неположительное количество товара (" << productName << ") в ячейку " << address << "." << endl;
            }
            else {
                cout << "Превышено максимальное количество товара (" << productName << ") в ячейке " << address << "." << endl;
            }
        }
        else {
            // Если товара нет в ячейке, проверяем, не превысится ли общее количество товара в ячейке после добавления
            int totalQuantity = 0;
            for (const auto& entry : products) {
                totalQuantity += entry.second;
            }
            if (totalQuantity + quantity <= 10 && totalQuantity + quantity > 0) {
                products[productName] = quantity; // Добавляем товар
                cout << "Добавлено " << quantity << " единиц товара " << productName << " в ячейку " << address << "." << endl; // Вывод сообщения
            }
            else if (totalQuantity + quantity <= 0) {
                cout << "Нельзя добавить неположительное количество товара (" << productName << ") в ячейку " << address << "." << endl;
            }
            else {
                cout << "Превышено максимальное количество товара (" << productName << ") в ячейке " << address << "." << endl;
            }
        }
    }


    void removeProduct(string productName, int quantity) { // Метод для удаления товара из ячейки
        if (products.find(productName) != products.end() && products[productName] >= quantity && quantity >= 0) {
            products[productName] -= quantity;
            if (products[productName] == 0) {
                products.erase(productName);
            }
            cout << "Убрано " << quantity << " единиц товара " << productName << " из ячейки " << address << "." << endl; // Вывод сообщения
        }
        else {
            cout << "Невозможно убрать " << quantity << " единиц товара " << productName << " из ячейки " << address << "." << endl; // Вывод сообщения
        }
    }

    void showContents() { // Метод для отображения содержимого ячейки
        if (!products.empty()) {
            cout << "Содержимое ячейки " << address << ":" << endl;
            for (const auto& entry : products) {
                cout << "- " << entry.first << ": " << entry.second << " шт." << endl;
            }
        }
    }
};

class Warehouse { // Определение класса Склад
public:
    int zones; // Количество зон на складе
    int shelvesPerZone; // Количество полок на зоне
    int sectionsPerShelf; // Количество секций на полке
    int shelvesCapacity; // Вместимость каждой полки
    int totalCapacity; // Общая вместимость склада
    map<string, Cell*> cells; // Карта для хранения ячеек на складе

    Warehouse(int z, int spz, int sps, int sc) : zones(z), shelvesPerZone(spz), sectionsPerShelf(sps), shelvesCapacity(sc) { // Конструктор принимает параметры
        totalCapacity = zones * shelvesPerZone * sectionsPerShelf * shelvesCapacity; // Вычисление общей вместимости склада

        // Вложенные циклы для инициализации ячеек на складе
        for (int zone = 1; zone <= zones; ++zone) {
            for (int shelf = 1; shelf <= shelvesPerZone; ++shelf) {
                for (int section = 1; section <= sectionsPerShelf; ++section) {
                    for (int shelfPosition = 1; shelfPosition <= shelvesCapacity; ++shelfPosition) {

                        string address = "";
                        address += char('A' + zone - 1);
                        address += to_string(shelf);
                        address += to_string(section);
                        address += to_string(shelfPosition);
                            cells[address] = new Cell(address); // Создание новой ячейки и добавление ее в карту
                    }
                }
            }
        }
    }

    void addProduct(string productName, int quantity, string cellAddress) { // Метод для добавления товара в ячейку
        if (cells.find(cellAddress) == cells.end()) {
            cout << "Ячейка не существует." << endl; // Вывод сообщения, если ячейка не существует
            return;
        }
        cells[cellAddress]->addProduct(productName, quantity); // Вызов метода addProduct ячейки
    }

    void removeProduct(string productName, int quantity, string cellAddress) { // Метод для удаления товара из ячейки
        if (cells.find(cellAddress) == cells.end()) {
            cout << "Ячейка не существует." << endl; // Вывод сообщения, если ячейка не существует
            return;
        }
        cells[cellAddress]->removeProduct(productName, quantity); // Вызов метода removeProduct ячейки
    }

    void getInfo() { // Метод для получения информации о заполненных ячейках
        vector<Cell*> filledCells; // Вектор для хранения заполненных ячеек
        vector<string> emptyCells; // Вектор для хранения адресов пустых ячеек

        int totalFilledCapacity = 0; // Общая заполненная вместимость
        for (const auto& entry : cells) {
            Cell* cell = entry.second;
            if (!cell->products.empty()) {
                filledCells.push_back(cell); // Добавление заполненной ячейки
                totalFilledCapacity += cell->products.size(); // Обновление общей заполненной вместимости
            }
            else {
                emptyCells.push_back(cell->address); // Добавление адреса пустой ячейки
            }
        }

        double filledPercentage = (static_cast<double>(totalFilledCapacity) / totalCapacity) * 100.0; // Вычисление процента заполнения
        cout << "Склад заполнен на " << filledPercentage << "%." << endl; // Вывод процента заполнения
        cout << "Содержимое заполненных ячеек:" << endl;
        for (const auto& cell : filledCells) {
            cell->showContents(); // Отображение содержимого заполненных ячеек
        }
    }

    void showEmptyCells() { // Метод для отображения пустых ячеек
        cout << "Пустые ячейки:" << endl;
        for (const auto& entry : cells) {
            if (entry.second->products.empty()) {
                cout << entry.first << endl; // Вывод адреса пустой ячейки
            }
        }
    }
};


int main() {
    Warehouse warehouse(2, 19, 4, 8);

    cout << "Для добавления товара в ячейку используйте команду ADD <наименование товара> <количество> <адрес ячейки>." << endl;
    cout << "Пример: ADD Апельсины 8 А1739" << endl;
    cout << "Для удаления товара из ячейки используйте команду REMOVE <наименование товара> <количество> <адрес ячейки>." << endl;
    cout << "Пример: REMOVE Апельсины 3 А1739" << endl;
    cout << "Для получения информации о состоянии заполненных ячеек склада используйте команду INFO." << endl;
    cout << "Для получения списка пустых ячеек используйте команду EMPTY." << endl;
    cout << "Команда HELP - выводит инструкцию по вводу." << endl;
    cout << "Команда EXIT - завершает программу." << endl;

    string command; // Строка для хранения команды пользователя

    while (true) {
        cout << ">>> "; // Подсказка для ввода команды
        cin >> command; // Считывание команды пользователя из ввода

        if (command == "EXIT") { // Проверка, хочет ли пользователь выйти
            break; // Выход из цикла
        }
        else if (command == "HELP") { // Проверка, хочет ли пользователь получить помощь
            // Вывод инструкций для помощи
            cout << "Для добавления товара в ячейку используйте команду ADD <наименование товара> <количество> <адрес ячейки>." << endl;
            cout << "Пример: ADD Апельсины 8 А1739" << endl;
            cout << "Для удаления товара из ячейки используйте команду REMOVE <наименование товара> <количество> <адрес ячейки>." << endl;
            cout << "Пример: REMOVE Апельсины 3 А1739" << endl;
            cout << "Для получения информации о состоянии заполненных ячеек склада используйте команду INFO." << endl;
            cout << "Для получения списка пустых ячеек используйте команду EMPTY." << endl;
            cout << "Команда HELP - выводит инструкцию по вводу." << endl;
            cout << "Команда EXIT - завершает программу." << endl;
        }
        else if (command.find("ADD") == 0) { // Проверка, хочет ли пользователь добавить товар
            string productName;
            int quantity;
            string cellAddress;
            cin >> productName >> quantity >> cellAddress; // Считывание названия товара, количества и адреса ячейки
            warehouse.addProduct(productName, quantity, cellAddress); // Вызов метода addProduct склада
        }
        else if (command.find("REMOVE") == 0) { // Проверка, хочет ли пользователь удалить товар
            string productName;
            int quantity;
            string cellAddress;
            cin >> productName >> quantity >> cellAddress; // Считывание названия товара, количества и адреса ячейки
            warehouse.removeProduct(productName, quantity, cellAddress); // Вызов метода removeProduct склада
        }
        else if (command == "INFO") { // Проверка, хочет ли пользователь получить информацию
            warehouse.getInfo(); // Вызов метода getInfo склада
        }
        else if (command == "EMPTY") { // Проверка, хочет ли пользователь увидеть пустые ячейки
            warehouse.showEmptyCells(); // Вызов метода showEmptyCells склада
        }
        else {
            cout << "Неизвестная команда." << endl; // Вывод сообщения о неизвестной команде
        }
    }
    return 0;
}
