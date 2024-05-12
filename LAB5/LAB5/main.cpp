////ЗАДАНИЕ 5.2
//
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//struct Patient {
//    int duration;
//    string ticket;
//};
//
//struct Window {
//    int timeLeft;
//    queue<Patient> patients;
//};
//int main() {
//    int numWindows;
//    cout << ">>> Введите кол-во окон" << "\n" << "<<< ";
//    cin >> numWindows;
//
//    vector<Window> windows(numWindows);
//    int ticketNumber = 1;
//    string command;
//
//    while (true) {
//        cout << "<<< ";
//        cin >> command;
//
//        if (command == "ENQUEUE") {
//            int duration;
//            if (!(cin >> duration)) {
//                cout << "Некорректный ввод. Пожалуйста, введите число." << endl;
//                cin.clear(); // Очищаем состояние потока
//                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
//                continue;
//            }
//            string ticket = "T" + to_string(ticketNumber++);
//            Patient patient = {duration, ticket};
//
//            // Найти окно с наименьшим временем до освобождения
//            int minTime = windows[0].timeLeft;
//            int minIndex = 0;
//            for (int i = 1; i < numWindows; ++i) {
//                if (windows[i].timeLeft < minTime) {
//                    minTime = windows[i].timeLeft;
//                    minIndex = i;
//                }
//            }
//
//            // Добавить пациента в окно
//            windows[minIndex].patients.push(patient);
//            windows[minIndex].timeLeft += duration;
//
//            cout << ">>> " << ticket << endl;
//        } else if (command == "DISTRIBUTE") {
//            for (int i = 0; i < numWindows; ++i) {
//                cout << ">>> Окно " << (i + 1) << " (" << windows[i].timeLeft << " минут): ";
//                while (!windows[i].patients.empty()) {
//                    cout << windows[i].patients.front().ticket;
//                    windows[i].patients.pop();
//                    if (!windows[i].patients.empty()) {
//                        cout << ", ";
//                    }
//                }
//                cout << endl;
//            }
//            break;
//        } else {
//            cout << "Неизвестная команда. Попробуйте еще раз." << endl;
//        }
//    }
//
//    return 0;
//}




////ЗАДАНИЕ 5.1
//
//
//#include <iostream>
//#include <map>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//struct Cell {
//    string product_name;
//    int quantity;
//};
//
//class Warehouse {
//private:
//    map<string, Cell> cells;
//
//public:
//    void add_product(const string& product_name, int quantity, const string& cell_address) {
//        if (cells.find(cell_address) == cells.end()) {
//            cells[cell_address] = {product_name, quantity};
//        } else {
//            int current_quantity = cells[cell_address].quantity;
//            if (current_quantity + quantity <= 10) {
//                cells[cell_address].quantity += quantity;
//            } else {
//                cout << "Недостаточно места для добавления товара в ячейку" << endl;
//            }
//        }
//    }
//
//    void remove_product(const string& product_name, int quantity, const string& cell_address) {
//        if (cells.find(cell_address) != cells.end()) {
//            int current_quantity = cells[cell_address].quantity;
//            if (current_quantity >= quantity) {
//                cells[cell_address].quantity -= quantity;
//                if (cells[cell_address].quantity == 0) {
//                    cells.erase(cell_address);
//                }
//            } else {
//                cout << "Недостаточно товара в ячейке для удаления" << endl;
//            }
//        }
//    }
//
//    void info() {
//        int total_cells = cells.size();
//        int total_products = 0;
//        vector<string> empty_cells;
//
//        for (const auto& [address, cell] : cells) {
//            total_products += cell.quantity;
//            cout << "Ячейка " << address << ": " << cell.product_name << " - " << cell.quantity << " ед." << endl;
//        }
//
//        cout << "Склад загружен на " << total_products * 10 << "%" << endl;
//        cout << "Содержание пустых ячеек:" << endl;
//        for (char zone : {'A', 'B', 'C'}) {
//            for (int shelf = 1; shelf <= 17; ++shelf) {
//                for (int section = 1; section <= 3; ++section) {
//                    for (int shelf_level = 1; shelf_level <= 9; ++shelf_level) {
//                        string address = string(1, zone) + to_string(shelf) + to_string(section) + to_string(shelf_level);
//                        if (cells.find(address) == cells.end()) {
//                            empty_cells.push_back(address);
//                        }
//                    }
//                }
//            }
//        }
//
//        for (const auto& address : empty_cells) {
//            cout << address << endl;
//        }
//    }
//};
//
//int main() {
//    Warehouse warehouse;
//    string command;
//    while (true) {
//        cout << "Введите команду (ADD, REMOVE, INFO, EXIT): ";
//        cin >> command;
//        if (command == "ADD") {
//            string product_name, cell_address;
//            int quantity;
//            cout << "Введите наименование товара, количество и адрес ячейки: ";
//            cin >> product_name >> quantity >> cell_address;
//            warehouse.add_product(product_name, quantity, cell_address);
//        } else if (command == "REMOVE") {
//            string product_name, cell_address;
//            int quantity;
//            cout << "Введите наименование товара, количество и адрес ячейки: ";
//            cin >> product_name >> quantity >> cell_address;
//            warehouse.remove_product(product_name, quantity, cell_address);
//        } else if (command == "INFO") {
//            warehouse.info();
//        } else if (command == "EXIT") {
//            break;
//        } else {
//            cout << "Неверная команда. Попробуйте снова." << endl;
//        }
//    }
//    return 0;
//}








////ЗАДАНИЕ 5.3
//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//// Структура для представления самолета
//struct Plane {
//    string name;
//    vector<string> route; // Маршрут самолета через города
//};
//
//// Контейнер для хранения самолетов
//vector<Plane> planes;
//
//// Функция для создания нового самолета и его маршрута
//void createPlane(const string& name, const vector<string>& route) {
//    Plane newPlane;
//    newPlane.name = name;
//    newPlane.route = route;
//    planes.push_back(newPlane);
//}
//
//// Функция для вывода всех самолетов, пролетающих через данный город
//void planesForTown(const string& town) {
//    cout << "Planes passing through " << town << ":\n";
//    for (const auto& plane : planes) {
//        if (find(plane.route.begin(), plane.route.end(), town) != plane.route.end()) {
//            cout << plane.name << endl;
//        }
//    }
//}
//
//// Функция для вывода всех городов, через которые летает данный самолет
//void townsForPlane(const string& planeName) {
//    cout << "Towns for plane " << planeName << ":\n";
//    for (const auto& plane : planes) {
//        if (plane.name == planeName) {
//            for (const auto& town : plane.route) {
//                cout << town << endl;
//            }
//            break;
//        }
//    }
//}
//
//// Функция для вывода всех самолетов и их маршрутов
//void displayPlanes() {
//    cout << "Planes and their routes:\n";
//    for (const auto& plane : planes) {
//        cout << "Plane: " << plane.name << ", Route: ";
//        for (const auto& town : plane.route) {
//            cout << town << " ";
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//    string command;
//    while (true) {
//        cout << "Enter command (CREATE_PLANE, PLANES_FOR_TOWN, TOWNS_FOR_PLANE, PLANES, or QUIT): ";
//        cin >> command;
//        
//        if (command == "CREATE_PLANE") {
//            string planeName;
//            cin >> planeName;
//            vector<string> route;
//            string town;
//            while (cin >> town && town != "END") {
//                route.push_back(town);
//            }
//            createPlane(planeName, route);
//        } else if (command == "PLANES_FOR_TOWN") {
//            string town;
//            cin >> town;
//            planesForTown(town);
//        } else if (command == "TOWNS_FOR_PLANE") {
//            string planeName;
//            cin >> planeName;
//            townsForPlane(planeName);
//        } else if (command == "PLANES") {
//            displayPlanes();
//        } else if (command == "QUIT") {
//            break;
//        } else {
//            cout << "Invalid command\n";
//        }
//    }
//
//    return 0;
//}


//// Задание 5.4
//#include <iostream>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//class Schedule {
//private:
//    map<int, vector<string>> timetable; // Расписание: ключ - номер дня, значение - список занятий
//
//public:
//    void setDiscipline(int day, const vector<string>& classes) {
//        timetable[day] = classes;
//    }
//
//    void viewDay(int day) {
//        if (timetable.find(day) == timetable.end()) {
//            cout << "In " << day << " day We are free!" << endl;
//            return;
//        }
//        cout << "In " << day << " day " << timetable[day].size() << " classes in university: ";
//        for (const auto& cls : timetable[day]) {
//            cout << cls << ", ";
//        }
//        cout << endl;
//    }
//
//    void nextMonth() {
//        // Переносим занятия на предпоследний день текущего месяца
//        int lastDayOfMonth = 30; // Для упрощения считаем, что в месяце всегда 30 дней
//        timetable[lastDayOfMonth - 1] = timetable[lastDayOfMonth];
//        timetable.erase(lastDayOfMonth);
//    }
//};
//
//int main() {
//    Schedule schedule;
//    int N;
//    cin >> N; // Число операций
//
//    for (int i = 0; i < N; ++i) {
//        string operation;
//        cin >> operation;
//
//        if (operation == "CLASS") {
//            int day;
//            cin >> day;
//            string cls;
//            getline(cin >> ws, cls); // Считываем всю строку после числа дня
//            schedule.setDiscipline(day, {cls});
//        } else if (operation == "NEXT") {
//            schedule.nextMonth();
//        } else if (operation == "VIEW") {
//            int day;
//            cin >> day;
//            schedule.viewDay(day);
//        }
//    }
//
//    return 0;
//}
//
//#include <iostream>
//#include <map>
//#include <vector>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//// Структура для представления ячейки на складе
//struct Cell {
//    string productName;
//    int quantity;
//};
//
//// Класс, представляющий склад
//class Warehouse {
//private:
//    // Хранилище для ячеек склада
//    map<string, Cell> cells;
//
//public:
//    // Метод для добавления товара в ячейку
//    void addProduct(const string& productName, int quantity, const string& address) {
//        if (cells.find(address) != cells.end()) {
//            Cell& cell = cells[address];
//            if (cell.quantity + quantity <= 10) {
//                cell.productName = productName;
//                cell.quantity += quantity;
//                cout << "Товар \"" << productName << "\" успешно добавлен в ячейку " << address << endl;
//            } else {
//                cout << "Невозможно добавить больше товара в ячейку " << address << ". Превышено максимальное количество." << endl;
//            }
//        } else {
//            cells[address] = {productName, quantity};
//            cout << "Товар \"" << productName << "\" успешно добавлен в новую ячейку " << address << endl;
//        }
//    }
//
//    // Метод для удаления товара из ячейки
//    void removeProduct(const string& productName, int quantity, const string& address) {
//        if (cells.find(address) != cells.end()) {
//            Cell& cell = cells[address];
//            if (cell.productName == productName && cell.quantity >= quantity) {
//                cell.quantity -= quantity;
//                cout << "Успешно удалено " << quantity << " шт. товара \"" << productName << "\" из ячейки " << address << endl;
//            } else {
//                cout << "В ячейке " << address << " нет достаточного количества указанного товара \"" << productName << "\"" << endl;
//            }
//        } else {
//            cout << "Ячейка " << address << " пуста" << endl;
//        }
//    }
//
//    // Метод для получения информации о состоянии склада
//    void getInfo() {
//        int totalCells = 0;
//        int totalOccupiedCells = 0;
//        map<char, pair<int, int>> zoneOccupancy;
//
//        // Подсчет общего количества ячеек и заполнение информации о загруженности зон
//        for (char zone = 'A'; zone <= 'C'; ++zone) {
//            int zoneCells = 0;
//            int zoneOccupied = 0;
//            for (int shelf = 1; shelf <= 20; ++shelf) {
//                for (int section = 1; section <= 5; ++section) {
//                    for (int shelfLevel = 1; shelfLevel <= 10; ++shelfLevel) {
//                        string address = "";
//                        address += zone;
//                        address += to_string(shelf);
//                        address += to_string(section);
//                        address += to_string(shelfLevel);
//                        totalCells++;
//                        if (cells.find(address) != cells.end() && cells[address].quantity > 0) {
//                            zoneOccupied++;
//                            zoneCells++;
//                            totalOccupiedCells++;
//                        }
//                    }
//                }
//            }
//            zoneOccupancy[zone] = make_pair(zoneOccupied, zoneCells);
//        }
//
//        cout << "Загруженность зон:" << endl;
//        for (const auto& pair : zoneOccupancy) {
//            int totalZoneCells = pair.second.second;
//            int occupiedZoneCells = pair.second.first;
//            if (totalZoneCells > 0) {
//                cout << "Зона " << pair.first << ": " << (occupiedZoneCells * 100 / totalZoneCells) << "%" << endl;
//            } else {
//                cout << "Зона " << pair.first << ": 0%" << endl;
//            }
//        }
//
//
//        // Вывод списка пустых ячеек
//        cout << "Пустые ячейки:" << endl;
//        for (char zone = 'A'; zone <= 'C'; ++zone) {
//            for (int shelf = 1; shelf <= 20; ++shelf) {
//                for (int section = 1; section <= 5; ++section) {
//                    for (int shelfLevel = 1; shelfLevel <= 10; ++shelfLevel) {
//                        string address = "";
//                        address += zone;
//                        address += to_string(shelf);
//                        address += to_string(section);
//                        address += to_string(shelfLevel);
//                        if (cells.find(address) == cells.end()) {
//                            cout << address << endl;
//                        }
//                    }
//                }
//            }
//        }
//
//        // Вывод общей загруженности склада
//        if (totalCells > 0) {
//            cout << "Общая загруженность склада: " << (totalOccupiedCells * 100 / totalCells) << "%" << endl;
//        } else {
//            cout << "Склад пуст." << endl;
//        }
//    }
//};
//
//int main() {
//    Warehouse warehouse;
//    string command;
//
//    // Вывод инструкций
//    cout << "Доступные команды:" << endl;
//    cout << "ADD <наименование товара> <количество> <адрес ячейки>" << endl;
//    cout << "REMOVE <наименование товара> <количество> <адрес ячейки>" << endl;
//    cout << "INFO" << endl;
//    cout << "EXIT" << endl;
//
//    // Взаимодействие с пользователем
//    while (true) {
//        cout << "> ";
//        getline(cin, command);
//
//        if (command.find("ADD") == 0) {
//            string productName, address;
//            int quantity;
//            stringstream ss(command.substr(4));
//            ss >> productName >> quantity >> address;
//            warehouse.addProduct(productName, quantity, address);
//        } else if (command.find("REMOVE") == 0) {
//            string productName, address;
//            int quantity;
//            stringstream ss(command.substr(7));
//            ss >> productName >> quantity >> address;
//            warehouse.removeProduct(productName, quantity, address);
//        } else if (command == "INFO") {
//            warehouse.getInfo();
//        } else if (command == "EXIT") {
//            break;
//        } else {
//            cout << "Неверная команда. Попробуйте снова." << endl;
//        }
//    }
//
//    return 0;
//}
