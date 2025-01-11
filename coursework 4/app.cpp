#include "App.h"
#include "ui_App.h"
#include "AddContactDialog.h"
#include <QVBoxLayout>
#include <QHeaderView>
#include <QMessageBox>

App::App(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::App),
      storage("contacts.txt"),
      dbStorage("contacts.db") {
    ui->setupUi(this);

    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(7);
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

    dbStorage.loadFromDatabase(phoneBook);
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
        tableWidget->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(contact.getBirthDate())));
        tableWidget->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(contact.getEmail())));
        tableWidget->setItem(row, 6, new QTableWidgetItem(QString::fromStdString(contact.getPhoneNumbersAsString())));
    }
}

// Сохранение контактов в файл и базу данных
void App::saveContacts() {
    storage.saveToFile(phoneBook);  // Сохранение в файл
    dbStorage.saveToDatabase(phoneBook);  // Сохранение в базу данных
}

// Добавление контакта
void App::addContact() {
    AddContactDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Contact newContact = dialog.getContact();
        phoneBook.addContact(newContact);
        saveContacts();
        loadContacts();
    }
}

// Удаление контакта
void App::deleteContact() {
    int row = tableWidget->currentRow();
    if (row >= 0) {
        phoneBook.removeContact(row);
        saveContacts();
        loadContacts();
    } else {
        QMessageBox::warning(this, "Ошибка", "Выберите контакт для удаления!");
    }
}

// Редактирование контакта
void App::editContact() {
    int row = tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите контакт для редактирования!");
        return;
    }

    Contact oldContact = phoneBook.getContacts()[row];
    AddContactDialog dialog(this);
    dialog.setContact(oldContact);

    if (dialog.exec() == QDialog::Accepted) {
        Contact updatedContact = dialog.getContact();
        phoneBook.updateContact(row, updatedContact);
        saveContacts();
        loadContacts();
    }
}
