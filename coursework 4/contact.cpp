#include "Contact.h"
#include <iostream>
#include <sstream>
#include <vector>

// Конструктор
Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& middleName,
    const std::string& address, const std::string& birthDate, const std::string& email,
    const std::vector<std::string>& phoneNumbers)
    : firstName(firstName), lastName(lastName), middleName(middleName),
      address(address), birthDate(birthDate), email(email), phoneNumbers(phoneNumbers)
{
    std::cout << "Contact created - normal constructor" << std::endl;
}

// Конструктор копирования
Contact::Contact(const Contact& other)
    : firstName(other.firstName), lastName(other.lastName), middleName(other.middleName),
      address(other.address), birthDate(other.birthDate), email(other.email), phoneNumbers(other.phoneNumbers)
{
    std::cout << "Contact created - copy constructor" << std::endl;
}

// Оператор присваивания копированием
Contact& Contact::operator=(const Contact& other) {
    if (this != &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        middleName = other.middleName;
        address = other.address;
        birthDate = other.birthDate;
        email = other.email;
        phoneNumbers = other.phoneNumbers;
    }
    std::cout << "Contact copy assignment operator" << std::endl;
    return *this;
}

// Конструктор перемещения
Contact::Contact(Contact&& other) noexcept
    : firstName(std::move(other.firstName)), lastName(std::move(other.lastName)), middleName(std::move(other.middleName)),
      address(std::move(other.address)), birthDate(std::move(other.birthDate)), email(std::move(other.email)), phoneNumbers(std::move(other.phoneNumbers))
{
    std::cout << "Contact created - move constructor" << std::endl;
}

// Оператор присваивания перемещением
Contact& Contact::operator=(Contact&& other) noexcept {
    if (this != &other) {
        firstName = std::move(other.firstName);
        lastName = std::move(other.lastName);
        middleName = std::move(other.middleName);
        address = std::move(other.address);
        birthDate = std::move(other.birthDate);
        email = std::move(other.email);
        phoneNumbers = std::move(other.phoneNumbers);
    }
     std::cout << "Contact move assignment operator" << std::endl;
    return *this;
}
// Оператор new
void* Contact::operator new(size_t size) {
    std::cout << "Contact custom new operator" << std::endl;
    return ::operator new(size);
}
// Оператор delete
void Contact::operator delete(void* ptr) {
   std::cout << "Contact custom delete operator" << std::endl;
   ::operator delete(ptr);
}

void Contact::print() const {
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Middle Name: " << middleName << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Birth Date: " << birthDate << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Phone Numbers: ";
    for (size_t i = 0; i < phoneNumbers.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << phoneNumbers[i];
    }
    std::cout << std::endl;
}

std::string Contact::toString() const {
    std::ostringstream oss;
    oss << firstName << "," << lastName << "," << middleName << ","
        << address << "," << birthDate << "," << email << ",";

    for (size_t i = 0; i < phoneNumbers.size(); ++i) {
        oss << phoneNumbers[i];
        if (i < phoneNumbers.size() - 1) oss << ",";
    }
    return oss.str();
}

Contact Contact::fromString(const std::string& data) {
    std::istringstream iss(data);
    std::string firstName, lastName, middleName, address, birthDate, email, phonesStr;

    std::getline(iss, firstName, ',');
    std::getline(iss, lastName, ',');
    std::getline(iss, middleName, ',');
    std::getline(iss, address, ',');
    std::getline(iss, birthDate, ',');
    std::getline(iss, email, ',');
    std::getline(iss, phonesStr, ',');

    std::vector<std::string> phoneNumbers;
    std::istringstream phonesStream(phonesStr);
    std::string phone;
    while (std::getline(phonesStream, phone, ',')) {
        phoneNumbers.push_back(phone);
    }

    return Contact(firstName, lastName, middleName, address, birthDate, email, phoneNumbers);
}
