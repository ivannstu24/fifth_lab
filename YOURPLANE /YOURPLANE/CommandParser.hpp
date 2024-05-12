#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <string>

enum class CommandType {
    CREATE_PLANE,
    PLANES_FOR_TOWN,
    TOWNS_FOR_PLANE,
    PLANES,
    QUIT
};

class CommandParser {
public:
    static CommandType parseCommand(const std::string& commandStr);
};

#endif /* COMMANDPARSER_H */
