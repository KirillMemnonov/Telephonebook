#ifndef FILESTORAGE_H
#define FILESTORAGE_H

#include "PhoneBook.h"
#include <QString>

class FileStorage {
public:
    explicit FileStorage(const QString& filePath);

    void saveToFile(const PhoneBook& phoneBook) const;
    void loadFromFile(PhoneBook& phoneBook) const;

private:
    QString filePath;
};

#endif // FILESTORAGE_H
