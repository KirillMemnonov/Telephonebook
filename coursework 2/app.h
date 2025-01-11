#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include "PhoneBook.h"
#include "FileStorage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class App; }
QT_END_NAMESPACE

class App : public QMainWindow {
    Q_OBJECT

public:
    explicit App(QWidget *parent = nullptr);
    ~App();

private slots:
    void addContact();
    void deleteContact();
    void editContact();  // Новый слот для редактирования

private:
    Ui::App *ui;
    QTableWidget *tableWidget;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *editButton;  // Новая кнопка

    PhoneBook phoneBook;
    FileStorage storage;

    void loadContacts();
};

#endif // APP_H
