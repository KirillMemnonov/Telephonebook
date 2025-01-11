#ifndef DATABASESTORAGE_H
#define DATABASESTORAGE_H

#include <QSqlDatabase>
#include "PhoneBook.h"

class DatabaseStorage {
public:
    explicit DatabaseStorage(const QString& dbPath);
    ~DatabaseStorage();

    void saveToDatabase(const PhoneBook& phoneBook) const;
    void loadFromDatabase(PhoneBook& phoneBook) const;

private:
    QSqlDatabase db;
    void createTable();
    void addContact(const Contact& contact) const;
    void removeContact(int id) const;
};

#endif // DATABASESTORAGE_H
