#include <iostream>
#include <limits>
#include <locale>
#include <vector>
#include <regex>
#include <algorithm>
#include "PhoneBook.h"
#include "FileStorage.h"

// Функция для валидации имени, фамилии и отчества
bool validateName(const std::string& name) {
    std::regex nameRegex("^[a-zA-Zа-яА-ЯёЁ][a-zA-Zа-яА-ЯёЁ0-9 -]+[a-zA-Zа-яА-ЯёЁ]$");
    return std::regex_match(name, nameRegex);
}

// Функция для валидации номера телефона
bool validatePhoneNumber(const std::string& phoneNumber) {
    std::regex phoneRegex("^[+]?[78][ -]?[(]?[0-9]{3}[)]?[ -]?[0-9]{3}[- ]?[0-9]{2}[- ]?[0-9]{2}$");
    return std::regex_match(phoneNumber, phoneRegex);
}

// Функция для валидации даты рождения
bool validateBirthDate(const std::string& birthDate) {
    // Формат даты: ДД.ММ.ГГГГ
    std::regex dateRegex("^([0]?[1-9]|[12][0-9]|[3][01])\\.([0]?[1-9]|[1][0-2])\\.([0-9]{4})$");
    std::smatch match;
    if (!std::regex_match(birthDate, match, dateRegex)) {
        return false;
    }

    // Преобразование строки в числа
    int day = std::stoi(match[1].str());
    int month = std::stoi(match[2].str());
    int year = std::stoi(match[3].str());

    // Проверка даты
    struct tm date = { 0, 0, 0, day, month - 1, year - 1900 };
    return mktime(&date) != -1 && mktime(&date) < time(nullptr);
}

// Функция для валидации email
bool validateEmail(const std::string& email) {
    std::regex emailRegex("^[a-zA-Z0-9]+@[a-zA-Z0-9]+\\.[a-zA-Z]{2,}$");
    return std::regex_match(email, emailRegex);
}

// Функция для удаления незначимых пробелов
std::string trim(const std::string& str) {
    auto start = str.find_first_not_of(' ');
    auto end = str.find_last_not_of(' ');
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

int main(int argc, char* argv[]) {
    PhoneBook phoneBook;
    FileStorage storage("contacts.txt");

    storage.loadFromFile(phoneBook);

    int choice;
    do {
        std::cout << "1. Add contact" << std::endl;
        std::cout << "2. Delete contact" << std::endl;
        std::cout << "3. List contacts" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Choose action: ";

        if (!(std::cin >> choice)) {
            std::cerr << "Input error. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1: {
            std::string firstName, lastName, middleName, address, birthDate, email;
            std::vector<std::string> phoneNumbers;
            std::string phone;

            std::cout << "First name: ";
            std::getline(std::cin, firstName);
            std::getline(std::cin, firstName); // Skip remaining newline character
            firstName = trim(firstName);
            if (!validateName(firstName)) {
                std::cerr << "Invalid first name." << std::endl;
                break;
            }

            std::cout << "Last name: ";
            std::getline(std::cin, lastName);
            lastName = trim(lastName);
            if (!validateName(lastName)) {
                std::cerr << "Invalid last name." << std::endl;
                break;
            }

            std::cout << "Middle name: ";
            std::getline(std::cin, middleName);
            middleName = trim(middleName);
            if (!validateName(middleName)) {
                std::cerr << "Invalid middle name." << std::endl;
                break;
            }

            std::cout << "Address: ";
            std::getline(std::cin, address);
            address = trim(address);

            std::cout << "Birth date (DD.MM.YYYY): ";
            std::getline(std::cin, birthDate);
            birthDate = trim(birthDate);
            if (!validateBirthDate(birthDate)) {
                std::cerr << "Invalid birth date." << std::endl;
                break;
            }

            std::cout << "Email: ";
            std::getline(std::cin, email);
            email = trim(email);
            if (!validateEmail(email)) {
                std::cerr << "Invalid email." << std::endl;
                break;
            }

            std::cout << "Enter phone numbers (comma separated): ";
            while (std::getline(std::cin, phone)) {
                phone = trim(phone);
                if (!validatePhoneNumber(phone)) {
                    std::cerr << "Invalid phone number: " << phone << std::endl;
                    continue;
                }
                phoneNumbers.push_back(phone);
                if (std::cin.peek() == '\n') break;
            }

            phoneBook.addContact({ firstName, lastName, middleName, address, birthDate, email, phoneNumbers });
            storage.saveToFile(phoneBook);
            break;
        }
        case 2:
            phoneBook.listContacts();
            int index;
            std::cout << "Enter contact number to delete: ";
            if (!(std::cin >> index)) {
                std::cerr << "Input error. Please enter a number." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                if (index > 0 && index <= phoneBook.getContacts().size()) {
                    phoneBook.removeContact(index - 1);
                    storage.saveToFile(phoneBook);
                }
                else {
                    std::cerr << "Invalid contact number." << std::endl;
                }
            }
            break;
        case 3:
            phoneBook.listContacts();
            std::cout << "Press Enter to continue..." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        case 4:
            break;
        default:
            std::cerr << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}