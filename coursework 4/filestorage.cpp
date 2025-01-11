#include "FileStorage.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

FileStorage::FileStorage(const QString& filePath) : filePath(filePath) {}

// Сохранение контактов в файл
void FileStorage::saveToFile(const PhoneBook& phoneBook) const {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Ошибка при открытии файла для записи:" << filePath;
        return;
    }

    QTextStream out(&file);

    for (const auto& contact : phoneBook.getContacts()) {
        out << QString::fromStdString(contact.toString()) << "\n";
    }

    file.close();
}

// Загрузка контактов из файла
void FileStorage::loadFromFile(PhoneBook& phoneBook) const {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Ошибка при открытии файла для чтения:" << filePath;
        return;
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (!line.isEmpty()) {
            phoneBook.addContact(Contact::fromString(line.toStdString()));
        }
    }

    file.close();
}
