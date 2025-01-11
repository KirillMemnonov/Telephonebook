#include "Validators.h"
#include <QDate>

// Валидация имени, фамилии, отчества
bool validateName(const QString& name) {
    QRegularExpression regex("^[a-zA-Zа-яА-ЯёЁ][a-zA-Zа-яА-ЯёЁ0-9 -]+[a-zA-Zа-яА-ЯёЁ]$");
    return regex.match(name).hasMatch();
}

// Валидация номера телефона
bool validatePhoneNumber(const QString& phoneNumber) {
    QRegularExpression regex("^[+]?[78][ -]?[(]?[0-9]{3}[)]?[ -]?[0-9]{3}[- ]?[0-9]{2}[- ]?[0-9]{2}$");
    return regex.match(phoneNumber).hasMatch();
}

// Валидация email
bool validateEmail(const QString& email) {
    QRegularExpression regex("^[a-zA-Z0-9]+@[a-zA-Z0-9]+\\.[a-zA-Z]{2,}$");
    return regex.match(email).hasMatch();
}

// Валидация даты рождения
bool validateBirthDate(const QString& birthDate) {
    QDate date = QDate::fromString(birthDate, "dd.MM.yyyy");
    return date.isValid() && date < QDate::currentDate();
}

// Удаление незначащих пробелов
QString trim(const QString& str) {
    return str.trimmed();
}
