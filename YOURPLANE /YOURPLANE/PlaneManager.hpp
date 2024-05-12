#ifndef PLANEMANAGER_H
#define PLANEMANAGER_H

#include "Plane.hpp"
#include <vector>

class PlaneManager {
public:
    static void createPlane(const std::string& name, const std::vector<std::string>& route);
    static void planesForTown(const std::string& town);
    static void townsForPlane(const std::string& planeName);
    static void displayPlanes();
};

#endif /* PLANEMANAGER_H */

