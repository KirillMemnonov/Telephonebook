#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"
#include <vector>
#include <functional> 

class PhoneBook {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const Contact& contact);
    void removeContact(int index);
    void editContact(int index, const Contact& newContact);
    void listContacts() const;
    void sortContacts(const std::function<bool(const Contact&, const Contact&)>& comparator);
    std::vector<Contact> searchContacts(const std::function<bool(const Contact&)>& predicate) const;
    const std::vector<Contact>& getContacts() const { return contacts; }
};

#endif // PHONEBOOK_H