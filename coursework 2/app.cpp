#include "App.h"
#include "ui_App.h"
#include "AddContactDialog.h"
#include <QVBoxLayout>
#include <QHeaderView>
#include <QMessageBox>

App::App(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::App), storage("contacts.txt") {
    ui->setupUi(this);

    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(7);  // Теперь 7 столбцов
    tableWidget->setHorizontalHeaderLabels({"Фамилия", "Имя", "Отчество", "Адрес", "Дата рождения", "Email", "Телефоны"});
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    tableWidget->setSortingEnabled(true);

    addButton = new QPushButton("Добавить", this);
    deleteButton = new QPushButton("Удалить", this);
    editButton = new QPushButton("Редактировать", this);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(tableWidget);
    layout->addWidget(addButton);
    layout->addWidget(editButton);
    layout->addWidget(deleteButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    storage.loadFromFile(phoneBook);
    loadContacts();

    connect(addButton, &QPushButton::clicked, this, &App::addContact);
    connect(deleteButton, &QPushButton::clicked, this, &App::deleteContact);
    connect(editButton, &QPushButton::clicked, this, &App::editContact);
}

App::~App() {
    delete ui;
}

// Загрузка контактов в таблицу
void App::loadContacts() {
    tableWidget->setRowCount(0);
    auto contacts = phoneBook.getContacts();
    for (const auto &contact : contacts) {
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(contact.getLastName())));
        tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(contact.getFirstName())));
        tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(contact.getMiddleName())));
        tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(contact.getAddress())));
        tableWidget->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(contact.getBirthDate())));  // Добавляем дату рождения
        tableWidget->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(contact.getEmail())));
        tableWidget->setItem(row, 6, new QTableWidgetItem(QString::fromStdString(contact.getPhoneNumbersAsString())));
    }
}
// Открытие окна добавления контакта
void App::addContact() {
    AddContactDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Contact newContact = dialog.getContact();
        phoneBook.addContact(newContact);
        storage.saveToFile(phoneBook);
        loadContacts();
    }
}

// Удаление контакта
void App::deleteContact() {
    int row = tableWidget->currentRow();
    if (row >= 0) {
        phoneBook.removeContact(row);
        storage.saveToFile(phoneBook);
        loadContacts();
    } else {
        QMessageBox::warning(this, "Ошибка", "Выберите контакт для удаления!");
    }
}

void App::editContact() {
    int row = tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите контакт для редактирования!");
        return;
    }

    // Получаем существующий контакт
    Contact oldContact = phoneBook.getContacts()[row];

    // Открываем диалоговое окно с текущими данными
    AddContactDialog dialog(this);
    dialog.setContact(oldContact);  // Новый метод для установки данных в форму

    if (dialog.exec() == QDialog::Accepted) {
        Contact updatedContact = dialog.getContact();
        phoneBook.updateContact(row, updatedContact); // Обновляем в памяти
        storage.saveToFile(phoneBook);  // Обновляем в файле
        loadContacts();
    }
}
