#ifndef ADDCONTACTDIALOG_H
#define ADDCONTACTDIALOG_H

#include <QDialog>
#include "Contact.h"
#include "Validators.h"

namespace Ui {
class AddContactDialog;
}

class AddContactDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddContactDialog(QWidget *parent = nullptr);
    ~AddContactDialog();

    Contact getContact() const;
    void setContact(const Contact& contact);
private slots:
    void validateAndAccept();  // Валидация перед добавлением

private:
    Ui::AddContactDialog *ui;
};

#endif // ADDCONTACTDIALOG_H
