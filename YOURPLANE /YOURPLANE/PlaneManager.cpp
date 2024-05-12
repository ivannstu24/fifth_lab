#include "PlaneManager.hpp"
#include <iostream>
#include <algorithm>

std::vector<Plane> planes; // Глобальный вектор planes для хранения объектов класса Plane.

void PlaneManager::createPlane(const std::string& name, const std::vector<std::string>& route) { // Реализация метода createPlane класса PlaneManager.
    Plane newPlane; // Создаем новый объект класса Plane.
    newPlane.name = name; // Присваиваем новому самолету переданное имя.
    newPlane.route = route; // Присваиваем новому самолету переданный маршрут.
    planes.push_back(newPlane); // Добавляем новый самолет в вектор planes.
}

void PlaneManager::planesForTown(const std::string& town) { // Реализация метода planesForTown класса PlaneManager.
    std::cout << "Planes passing through " << town << ":\n"; // Выводим сообщение о самолетах, проходящих через указанный город.
    for (const auto& plane : planes) { // Проходим по всем самолетам в векторе planes.
        if (std::find(plane.route.begin(), plane.route.end(), town) != plane.route.end()) { // Проверяем, проходит ли данный самолет через указанный город.
            std::cout << plane.name << std::endl; // Выводим имя самолета.
        }
    }
}

void PlaneManager::townsForPlane(const std::string& planeName) { // Реализация метода townsForPlane класса PlaneManager.
    std::cout << "Towns for plane " << planeName << ":\n"; // Выводим сообщение о городах для указанного самолета.
    for (const auto& plane : planes) { // Проходим по всем самолетам в векторе planes.
        if (plane.name == planeName) { // Если имя текущего самолета совпадает с указанным именем.
            for (const auto& town : plane.route) { // Проходим по всем городам в маршруте самолета.
                std::cout << town << std::endl; // Выводим название города.
            }
            break; // Прерываем цикл, так как найден нужный самолет.
        }
    }
}

void PlaneManager::displayPlanes() { // Реализация метода displayPlanes класса PlaneManager.
    std::cout << "Planes and their routes:\n"; // Выводим сообщение о самолетах и их маршрутах.
    for (const auto& plane : planes) { // Проходим по всем самолетам в векторе planes.
        std::cout << "Plane: " << plane.name << ", Route: "; // Выводим имя текущего самолета.
        for (const auto& town : plane.route) { // Проходим по всем городам в маршруте текущего самолета.
            std::cout << town << " "; // Выводим название города.
        }
        std::cout << std::endl; // Переходим на новую строку.
    }
}

