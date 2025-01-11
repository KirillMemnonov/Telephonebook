#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string middleName;
    std::string address;
    std::string birthDate;
    std::string email;
    std::vector<std::string> phoneNumbers;

public:
    // Конструктор
    Contact(const std::string& firstName, const std::string& lastName, const std::string& middleName,
            const std::string& address, const std::string& birthDate, const std::string& email,
            const std::vector<std::string>& phoneNumbers);

    // Конструктор копирования
    Contact(const Contact& other);

    // Оператор присваивания копированием
    Contact& operator=(const Contact& other);

    // Конструктор перемещения
    Contact(Contact&& other) noexcept;

    // Оператор присваивания перемещением
    Contact& operator=(Contact&& other) noexcept;

    // Оператор new
    static void* operator new(size_t size);

    // Оператор delete
    static void operator delete(void* ptr);

    // Методы
    void print() const;
    std::string toString() const;
    static Contact fromString(const std::string& data);

    // Геттеры
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getMiddleName() const { return middleName; }
    std::string getEmail() const { return email; }
    std::string getAddress() const { return address; }
    std::string getPhoneNumbersAsString() const { return phoneNumbers[0]; }
    std::string getBirthDate() const { return birthDate; }
};

#endif // CONTACT_H
