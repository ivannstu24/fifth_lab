#include "CommandParser.hpp"

CommandType CommandParser::parseCommand(const std::string& commandStr) {
    if (commandStr == "CREATE_PLANE") {
        return CommandType::CREATE_PLANE;
    } else if (commandStr == "PLANES_FOR_TOWN") {
        return CommandType::PLANES_FOR_TOWN;
    } else if (commandStr == "TOWNS_FOR_PLANE") {
        return CommandType::TOWNS_FOR_PLANE;
    } else if (commandStr == "PLANES") {
        return CommandType::PLANES;
    } else if (commandStr == "QUIT") {
        return CommandType::QUIT;
    } else {
        throw std::invalid_argument("Invalid command");
    }
}

