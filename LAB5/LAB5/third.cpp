//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//// Перечисление для типов команд
//enum class CommandType {
//    CREATE_PLANE,        // Создать самолет
//    PLANES_FOR_TOWN,     // Список самолетов для данного города
//    TOWNS_FOR_PLANE,     // Список городов для данного самолета
//    PLANES,              // Список всех самолетов и их маршрутов
//    QUIT                 // Завершить программу
//};
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
//    string commandStr;
//    while (true) {
//        cout << "Enter command (CREATE_PLANE, PLANES_FOR_TOWN, TOWNS_FOR_PLANE, PLANES, or QUIT): ";
//        cin >> commandStr;
//        
//        CommandType command;
//        // Преобразование строки в соответствующий тип команды
//        if (commandStr == "CREATE_PLANE") {
//            command = CommandType::CREATE_PLANE;
//        } else if (commandStr == "PLANES_FOR_TOWN") {
//            command = CommandType::PLANES_FOR_TOWN;
//        } else if (commandStr == "TOWNS_FOR_PLANE") {
//            command = CommandType::TOWNS_FOR_PLANE;
//        } else if (commandStr == "PLANES") {
//            command = CommandType::PLANES;
//        } else if (commandStr == "QUIT") {
//            command = CommandType::QUIT;
//        } else {
//            cout << "Invalid command\n";
//            continue;
//        }
//
//        switch (command) {
//            case CommandType::CREATE_PLANE: {
//                string planeName;
//                cin >> planeName;
//                vector<string> route;
//                string town;
//                // Ввод маршрута самолета, пока не встретится "END"
//                while (cin >> town && town != "END") {
//                    route.push_back(town);
//                }
//                createPlane(planeName, route);
//                break;
//            }
//            case CommandType::PLANES_FOR_TOWN: {
//                string town;
//                cin >> town;
//                planesForTown(town);
//                break;
//            }
//            case CommandType::TOWNS_FOR_PLANE: {
//                string planeName;
//                cin >> planeName;
//                townsForPlane(planeName);
//                break;
//            }
//            case CommandType::PLANES: {
//                displayPlanes();
//                break;
//            }
//            case CommandType::QUIT: {
//                return 0;
//            }
//        }
//    }
//
//    return 0;
//}
