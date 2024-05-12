////ЗАДАНИЕ 5.2
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//// Структура для представления пациента
//struct Patient {
//    int duration; // Время обслуживания
//    string ticket; // Номер талона
//};
//
//// Структура для представления окна (кассы)
//struct Window {
//    int timeLeft; // Оставшееся время до окончания обслуживания текущего пациента
//    queue<Patient> patients; // Очередь пациентов, ожидающих обслуживание
//};
//
//int main() {
//    int numWindows;
//    cout << ">>> Введите кол-во окон" << "\n" << "<<< ";
//    cin >> numWindows;
//
//    // Создание вектора окон
//    vector<Window> windows(numWindows);
//    int ticketNumber = 1;
//    string command;
//
//    // Бесконечный цикл для обработки команд
//    while (true) {
//        cout << "<<< ";
//        cin >> command;
//
//        if (command == "ENQUEUE") { // Команда добавления пациента в очередь
//            int duration;
//            if (!(cin >> duration)) { // Проверка на корректность ввода
//                cout << "Некорректный ввод. Пожалуйста, введите число." << endl;
//                cin.clear(); // Очищаем состояние потока
//                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
//                continue;
//            }
//            string ticket = "T" + to_string(ticketNumber++);
//            Patient patient = {duration, ticket};
//
//            // Нахождение окна с наименьшим оставшимся временем обслуживания
//            int minTime = windows[0].timeLeft;
//            int minIndex = 0;
//            for (int i = 1; i < numWindows; ++i) {
//                if (windows[i].timeLeft < minTime) {
//                    minTime = windows[i].timeLeft;
//                    minIndex = i;
//                }
//            }
//
//            // Добавление пациента в очередь выбранного окна и обновление времени обслуживания
//            windows[minIndex].patients.push(patient);
//            windows[minIndex].timeLeft += duration;
//
//            cout << ">>> " << ticket << endl; // Вывод номера талона пациента
//        } else if (command == "DISTRIBUTE") { // Команда распределения пациентов
//            // Вывод состояния каждого окна с пациентами в очереди
//            for (int i = 0; i < numWindows; ++i) {
//                cout << ">>> Окно " << (i + 1) << " (" << windows[i].timeLeft << " минут): ";
//                while (!windows[i].patients.empty()) {
//                    cout << windows[i].patients.front().ticket; // Вывод номера талона пациента
//                    windows[i].patients.pop(); // Удаление пациента из очереди
//                    if (!windows[i].patients.empty()) {
//                        cout << ", ";
//                    }
//                }
//                cout << endl;
//            }
//            break; // Выход из цикла
//        } else {
//            cout << "Неизвестная команда. Попробуйте еще раз." << endl; // В случае некорректной команды
//        }
//    }
//
//    return 0;
//}
