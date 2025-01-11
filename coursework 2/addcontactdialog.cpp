#include "AddContactDialog.h"
#include "ui_AddContactDialog.h"
#include <QMessageBox>

AddContactDialog::AddContactDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AddContactDialog) {
    ui->setupUi(this);

    // Установка календаря для выбора даты
    ui->birthDateEdit->setCalendarPopup(true);
    ui->birthDateEdit->setDate(QDate::currentDate().addYears(-18));

    // Подключаем кнопку "OK" к слоту validateAndAccept()
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &AddContactDialog::validateAndAccept);
}

AddContactDialog::~AddContactDialog() {
    delete ui;
}

// Проверка введенных данных перед закрытием окна
void AddContactDialog::validateAndAccept() {
    QString firstName = trim(ui->firstNameEdit->text());
    QString lastName = trim(ui->lastNameEdit->text());
    QString middleName = trim(ui->middleNameEdit->text());
    QString address = trim(ui->addressEdit->text());
    QString birthDate = ui->birthDateEdit->date().toString("dd.MM.yyyy");
    QString email = trim(ui->emailEdit->text());
    QString phone = trim(ui->phoneEdit->text());

    if (!validateName(firstName)) {
        QMessageBox::warning(this, "Ошибка", "Некорректное имя!");
        return;
    }
    if (!validateName(lastName)) {
        QMessageBox::warning(this, "Ошибка", "Некорректная фамилия!");
        return;
    }
    if (!middleName.isEmpty() && !validateName(middleName)) {
        QMessageBox::warning(this, "Ошибка", "Некорректное отчество!");
        return;
    }
    if (!validateBirthDate(birthDate)) {
        QMessageBox::warning(this, "Ошибка", "Некорректная дата рождения!");
        return;
    }
    if (!validateEmail(email)) {
        QMessageBox::warning(this, "Ошибка", "Некорректный email!");
        return;
    }
    if (!validatePhoneNumber(phone)) {
        QMessageBox::warning(this, "Ошибка", "Некорректный номер телефона!");
        return;
    }

    // Если все проверки пройдены, закрываем окно с успешным результатом
    QDialog::accept();
}

// Получение объекта контакта
Contact AddContactDialog::getContact() const {
    return Contact(
        ui->firstNameEdit->text().toStdString(),
        ui->lastNameEdit->text().toStdString(),
        ui->middleNameEdit->text().toStdString(),
        ui->addressEdit->text().toStdString(),
        ui->birthDateEdit->date().toString("dd.MM.yyyy").toStdString(),
        ui->emailEdit->text().toStdString(),
        { ui->phoneEdit->text().toStdString() }
    );
}

void AddContactDialog::setContact(const Contact& contact) {
    ui->firstNameEdit->setText(QString::fromStdString(contact.getFirstName()));
    ui->lastNameEdit->setText(QString::fromStdString(contact.getLastName()));
    ui->middleNameEdit->setText(QString::fromStdString(contact.getMiddleName()));
    ui->addressEdit->setText(QString::fromStdString(contact.getAddress()));
    ui->birthDateEdit->setDate(QDate::fromString(QString::fromStdString(contact.getBirthDate()), "dd.MM.yyyy"));
    ui->emailEdit->setText(QString::fromStdString(contact.getEmail()));
    ui->phoneEdit->setText(QString::fromStdString(contact.getPhoneNumbersAsString()));
}
