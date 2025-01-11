#include "Contact.h"
#include <iostream>
#include <sstream>
#include <vector>

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& middleName,
    const std::string& address, const std::string& birthDate, const std::string& email,
    const std::vector<std::string>& phoneNumbers)
    : firstName(firstName), lastName(lastName), middleName(middleName),
    address(address), birthDate(birthDate), email(email), phoneNumbers(phoneNumbers) {}

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