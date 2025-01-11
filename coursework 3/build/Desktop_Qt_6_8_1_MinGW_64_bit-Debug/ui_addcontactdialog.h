/********************************************************************************
** Form generated from reading UI file 'addcontactdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCONTACTDIALOG_H
#define UI_ADDCONTACTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddContactDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *firstNameEdit;
    QLabel *label_2;
    QLineEdit *lastNameEdit;
    QLabel *label_3;
    QLineEdit *middleNameEdit;
    QLabel *label_4;
    QLineEdit *addressEdit;
    QLabel *label_6;
    QLineEdit *emailEdit;
    QLabel *label_5;
    QDateEdit *birthDateEdit;
    QLabel *label_7;
    QLineEdit *phoneEdit;

    void setupUi(QDialog *AddContactDialog)
    {
        if (AddContactDialog->objectName().isEmpty())
            AddContactDialog->setObjectName("AddContactDialog");
        AddContactDialog->resize(332, 420);
        buttonBox = new QDialogButtonBox(AddContactDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(-70, 380, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(AddContactDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(40, 20, 251, 346));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        firstNameEdit = new QLineEdit(verticalLayoutWidget);
        firstNameEdit->setObjectName("firstNameEdit");

        verticalLayout->addWidget(firstNameEdit);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        lastNameEdit = new QLineEdit(verticalLayoutWidget);
        lastNameEdit->setObjectName("lastNameEdit");

        verticalLayout->addWidget(lastNameEdit);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        middleNameEdit = new QLineEdit(verticalLayoutWidget);
        middleNameEdit->setObjectName("middleNameEdit");

        verticalLayout->addWidget(middleNameEdit);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        addressEdit = new QLineEdit(verticalLayoutWidget);
        addressEdit->setObjectName("addressEdit");

        verticalLayout->addWidget(addressEdit);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);

        emailEdit = new QLineEdit(verticalLayoutWidget);
        emailEdit->setObjectName("emailEdit");

        verticalLayout->addWidget(emailEdit);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        birthDateEdit = new QDateEdit(verticalLayoutWidget);
        birthDateEdit->setObjectName("birthDateEdit");

        verticalLayout->addWidget(birthDateEdit);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");

        verticalLayout->addWidget(label_7);

        phoneEdit = new QLineEdit(verticalLayoutWidget);
        phoneEdit->setObjectName("phoneEdit");

        verticalLayout->addWidget(phoneEdit);


        retranslateUi(AddContactDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddContactDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddContactDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddContactDialog);
    } // setupUi

    void retranslateUi(QDialog *AddContactDialog)
    {
        AddContactDialog->setWindowTitle(QCoreApplication::translate("AddContactDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddContactDialog", "\320\270\320\274\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("AddContactDialog", "\321\204\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("AddContactDialog", "\320\276\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_4->setText(QCoreApplication::translate("AddContactDialog", "\320\260\320\264\321\200\320\265\321\201", nullptr));
        label_6->setText(QCoreApplication::translate("AddContactDialog", "email ", nullptr));
        label_5->setText(QCoreApplication::translate("AddContactDialog", "\320\264\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        label_7->setText(QCoreApplication::translate("AddContactDialog", "\321\202\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddContactDialog: public Ui_AddContactDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCONTACTDIALOG_H
