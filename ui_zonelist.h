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
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *ZoneList)
    {
        if (ZoneList->objectName().isEmpty())
            ZoneList->setObjectName(QStringLiteral("ZoneList"));
        ZoneList->resize(333, 221);
        label = new QLabel(ZoneList);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 10, 231, 61));
        pushButton = new QPushButton(ZoneList);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 180, 101, 31));
        textEdit = new QTextEdit(ZoneList);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 140, 311, 31));
        label_2 = new QLabel(ZoneList);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 60, 271, 31));
        label_3 = new QLabel(ZoneList);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 90, 291, 21));
        label_4 = new QLabel(ZoneList);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 110, 191, 21));

        retranslateUi(ZoneList);

        QMetaObject::connectSlotsByName(ZoneList);
    } // setupUi

    void retranslateUi(QDialog *ZoneList)
    {
        ZoneList->setWindowTitle(QApplication::translate("ZoneList", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ZoneList", "Enter 4 pairs of coordinates (int)", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ZoneList", "Submit", Q_NULLPTR));
        label_2->setText(QApplication::translate("ZoneList", "Format: TopLeftX, TopLeftY, TopRightX,", Q_NULLPTR));
        label_3->setText(QApplication::translate("ZoneList", "TopRightY, BottomRightX, BottomRightY, ", Q_NULLPTR));
        label_4->setText(QApplication::translate("ZoneList", "BottomLeftX, BottomLeftY", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ZoneList: public Ui_ZoneList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZONELIST_H
