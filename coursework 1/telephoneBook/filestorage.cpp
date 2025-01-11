#include "FileStorage.h"
#include <iostream>
#include <locale>

FileStorage::FileStorage(const std::string& filePath) : filePath(filePath) {

}

void FileStorage::saveToFile(const PhoneBook& phoneBook) const {
    std::ofstream file(filePath, std::ios::out | std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << filePath << std::endl;
        return;
    }
    file.imbue(std::locale("en_US.UTF-8")); // Установка локали UTF-8 для записи в файл
    for (const auto& contact : phoneBook.getContacts()) {
        file << contact.toString() << std::endl;
    }
    file.close();
}

void FileStorage::loadFromFile(PhoneBook& phoneBook) const {
    std::ifstream file(filePath, std::ios::in | std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error opening file for reading: " << filePath << std::endl;
        return;
    }
    file.imbue(std::locale("en_US.UTF-8")); // Установка локали UTF-8 для чтения из файла
    std::string line;
    while (std::getline(file, line)) {
        phoneBook.addContact(Contact::fromString(line));
    }
    file.close();
}