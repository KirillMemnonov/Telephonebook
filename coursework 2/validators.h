#ifndef VALIDATORS_H
#define VALIDATORS_H

#include <QString>
#include <QRegularExpression>

// Валидация имени, фамилии, отчества
bool validateName(const QString& name);

// Валидация номера телефона
bool validatePhoneNumber(const QString& phoneNumber);

// Валидация email
bool validateEmail(const QString& email);

// Валидация даты рождения
bool validateBirthDate(const QString& birthDate);

// Очистка пробелов
QString trim(const QString& str);

#endif // VALIDATORS_H
