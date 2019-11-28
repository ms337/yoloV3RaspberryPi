/********************************************************************************
** Form generated from reading UI file 'zonelist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
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
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ZoneList
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QLabel *label_2;

    void setupUi(QDialog *ZoneList)
    {
        if (ZoneList->objectName().isEmpty())
            ZoneList->setObjectName(QStringLiteral("ZoneList"));
        ZoneList->resize(425, 191);
        label = new QLabel(ZoneList);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 10, 141, 61));
        pushButton = new QPushButton(ZoneList);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 150, 101, 31));
        textEdit = new QTextEdit(ZoneList);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(50, 110, 311, 31));
        label_2 = new QLabel(ZoneList);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 401, 31));

        retranslateUi(ZoneList);

        QMetaObject::connectSlotsByName(ZoneList);
    } // setupUi

    void retranslateUi(QDialog *ZoneList)
    {
        ZoneList->setWindowTitle(QApplication::translate("ZoneList", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ZoneList", "Enter coordinates:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ZoneList", "Submit", Q_NULLPTR));
        label_2->setText(QApplication::translate("ZoneList", "Format: TopLeftX, TopLeftY, BottomRightX, BottomRightY", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ZoneList: public Ui_ZoneList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZONELIST_H
