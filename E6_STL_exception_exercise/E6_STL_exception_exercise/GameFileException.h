#ifndef GAMEFILEEXCEPTION_H
#define GAMEFILEEXCEPTION_H

#include <string>
#include <exception>

class GameFileException : public std::runtime_error{
public:
    GameFileException(std::string whatMsg, std::string fileName, bool f=false);
    void printError() const;

    std::string getFileName() const {
        return fileName;
    }

    bool getFatal() const {
        return fatal;
    }

private:
    std::string fileName;
    bool fatal;
};


#endif //GAMEFILEEXCEPTION_H
