//#include <iostream>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//class Schedule {
//private:
//    // Используем map для хранения расписания: ключ - номер дня, значение - список занятий
//    map<int, vector<string>> timetable;
//
//public:
//    // Метод для добавления занятий на определённый день
//    void setDiscipline(int day, const vector<string>& classes) {
//        // Проверяем, есть ли уже такие занятия на этот день
//        for (const auto& cls : classes) {
//            if (find(timetable[day].begin(), timetable[day].end(), cls) == timetable[day].end()) {
//                // Если таких занятий ещё нет, добавляем их в расписание
//                timetable[day].push_back(cls);
//            }
//        }
//    }
//
//    // Метод для просмотра занятий на определённый день
//    void viewDay(int day) {
//        if (timetable.find(day) == timetable.end()) {
//            // Если на этот день нет занятий, выводим сообщение об этом
//            cout << "In " << day << " day We are free!" << endl;
//            return;
//        }
//        // Выводим информацию о занятиях на указанный день
//        cout << "In " << day << " day " << timetable[day].size() << " classes in university: ";
//        for (const auto& cls : timetable[day]) {
//            cout << cls << " ";
//        }
//        cout << endl;
//    }
//
//    // Метод для переноса занятий на предпоследний день месяца
//    void nextMonth() {
//        // Переносим занятия на предпоследний день текущего месяца
//        int lastDayOfMonth = 30; // Для упрощения считаем, что в месяце всегда 30 дней
//        if (timetable.find(lastDayOfMonth) != timetable.end()) {
//            // Если есть занятия в последний день месяца, переносим их на предпоследний
//            timetable[lastDayOfMonth - 1].insert(timetable[lastDayOfMonth - 1].end(),
//                                                 timetable[lastDayOfMonth].begin(), timetable[lastDayOfMonth].end());
//            timetable.erase(lastDayOfMonth); // Удаляем записи о занятиях в последний день месяца
//        }
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
//            // Если операция "CLASS", добавляем занятие на указанный день
//            int day;
//            cin >> day;
//            cin.ignore(); // Игнорируем символ новой строки после числа дня
//            string cls;
//            getline(cin, cls); // Считываем всю строку после числа дня
//            schedule.setDiscipline(day, {cls});
//        }
//        else if (operation == "NEXT") {
//            // Если операция "NEXT", переносим занятия на предпоследний день месяца
//            schedule.nextMonth();
//        } else if (operation == "VIEW") {
//            // Если операция "VIEW", выводим занятия на указанный день
//            int day;
//            cin >> day;
//            schedule.viewDay(day);
//        }
//    }
//
//    return 0;
//}
