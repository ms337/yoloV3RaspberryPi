/********************************************************************************
** Form generated from reading UI file 'zonelist.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZONELIST_H
#define UI_ZONELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ZoneList
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QTextBrowser *textBrowser;
    QLabel *label_2;

    void setupUi(QDialog *ZoneList)
    {
        if (ZoneList->objectName().isEmpty())
            ZoneList->setObjectName(QStringLiteral("ZoneList"));
        ZoneList->resize(384, 185);
        label = new QLabel(ZoneList);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 201, 61));
        pushButton = new QPushButton(ZoneList);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 120, 101, 31));
        textEdit = new QTextEdit(ZoneList);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 90, 181, 31));
        textBrowser = new QTextBrowser(ZoneList);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(220, 50, 151, 121));
        label_2 = new QLabel(ZoneList);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 50, 181, 41));

        retranslateUi(ZoneList);

        QMetaObject::connectSlotsByName(ZoneList);
    } // setupUi

    void retranslateUi(QDialog *ZoneList)
    {
        ZoneList->setWindowTitle(QApplication::translate("ZoneList", "Dialog", 0));
        label->setText(QApplication::translate("ZoneList", "Enter 4 pairs of coordinates", 0));
        pushButton->setText(QApplication::translate("ZoneList", "Submit", 0));
        label_2->setText(QApplication::translate("ZoneList", "Format: 1,2,3,4,5,6,7,8", 0));
    } // retranslateUi

};

namespace Ui {
    class ZoneList: public Ui_ZoneList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZONELIST_H
