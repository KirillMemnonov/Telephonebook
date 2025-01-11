#include "PhoneBook.h"
#include <iostream>
#include <algorithm>
#include <vector>

void PhoneBook::addContact(const Contact& contact) {
    contacts.push_back(contact);
}

void PhoneBook::removeContact(int index) {
    if (index >= 0 && index < contacts.size()) {
        contacts.erase(contacts.begin() + index);
    }
    else {
        std::cout << "Error: Invalid index.\n";
    }
}

void PhoneBook::editContact(int index, const Contact& newContact) {
    if (index >= 0 && index < contacts.size()) {
        contacts[index] = newContact;
    }
    else {
        std::cout << "Error: Invalid index.\n";
    }
}

void PhoneBook::listContacts() const {
    if (contacts.empty()) {
        std::cout << "Phone book is empty.\n";
        return;
    }

    for (size_t i = 0; i < contacts.size(); ++i) {
        std::cout << i + 1 << ". ";
        contacts[i].print();
        std::cout << "----------------------\n";
    }
}

void PhoneBook::sortContacts(const std::function<bool(const Contact&, const Contact&)>& comparator) {
    std::sort(contacts.begin(), contacts.end(), comparator);
}

std::vector<Contact> PhoneBook::searchContacts(const std::function<bool(const Contact&)>& predicate) const {
    std::vector<Contact> result;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), predicate);
    return result;
}
