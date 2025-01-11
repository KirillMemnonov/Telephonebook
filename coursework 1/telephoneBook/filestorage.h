#ifndef FILESTORAGE_H
#define FILESTORAGE_H

#include "PhoneBook.h"
#include <fstream>

class FileStorage {
private:
    std::string filePath;

public:
    FileStorage(const std::string& filePath);
    void saveToFile(const PhoneBook& phoneBook) const;
    void loadFromFile(PhoneBook& phoneBook) const;
};

#endif // FILESTORAGE_H
