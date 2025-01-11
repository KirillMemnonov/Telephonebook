#include "DatabaseStorage.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseStorage::DatabaseStorage(const QString& dbPath) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        qWarning() << "Ошибка открытия базы данных:" << db.lastError().text();
    } else {
        qDebug() << "База данных открыта!";
        createTable();
    }
}

DatabaseStorage::~DatabaseStorage() {
    db.close();
}

// Создаем таблицу контактов
void DatabaseStorage::createTable() {
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS contacts ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "firstName TEXT, "
               "lastName TEXT, "
               "middleName TEXT, "
               "address TEXT, "
               "birthDate TEXT, "
               "email TEXT, "
               "phoneNumbers TEXT)");
}

// Сохраняем список контактов в базу
void DatabaseStorage::saveToDatabase(const PhoneBook& phoneBook) const {
    QSqlQuery query;
    query.exec("DELETE FROM contacts"); // Очистка перед перезаписью

    for (const auto& contact : phoneBook.getContacts()) {
        addContact(contact);
    }
}

// Загружаем контакты из базы
void DatabaseStorage::loadFromDatabase(PhoneBook& phoneBook) const {
    QSqlQuery query("SELECT firstName, lastName, middleName, address, birthDate, email, phoneNumbers FROM contacts");

    while (query.next()) {
        Contact contact(
            query.value(0).toString().toStdString(),
            query.value(1).toString().toStdString(),
            query.value(2).toString().toStdString(),
            query.value(3).toString().toStdString(),
            query.value(4).toString().toStdString(),
            query.value(5).toString().toStdString(),
            { query.value(6).toString().toStdString() }
        );
        phoneBook.addContact(contact);
    }
}

// Добавляем один контакт в базу
void DatabaseStorage::addContact(const Contact& contact) const {
    QSqlQuery query;
    query.prepare("INSERT INTO contacts (firstName, lastName, middleName, address, birthDate, email, phoneNumbers) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(QString::fromStdString(contact.getFirstName()));
    query.addBindValue(QString::fromStdString(contact.getLastName()));
    query.addBindValue(QString::fromStdString(contact.getMiddleName()));
    query.addBindValue(QString::fromStdString(contact.getAddress()));
    query.addBindValue(QString::fromStdString(contact.getBirthDate()));
    query.addBindValue(QString::fromStdString(contact.getEmail()));
    query.addBindValue(QString::fromStdString(contact.getPhoneNumbersAsString()));

    if (!query.exec()) {
        qWarning() << "Ошибка добавления контакта:" << query.lastError().text();
    }
}

// Удаляем контакт по ID
void DatabaseStorage::removeContact(int id) const {
    QSqlQuery query;
    query.prepare("DELETE FROM contacts WHERE id = ?");
    query.addBindValue(id);
    if (!query.exec()) {
        qWarning() << "Ошибка удаления контакта:" << query.lastError().text();
    }
}
