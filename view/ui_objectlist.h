/********************************************************************************
** Form generated from reading UI file 'objectlist.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECTLIST_H
#define UI_OBJECTLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ObjectList
{
public:
    QComboBox *comboBox;

    void setupUi(QDialog *ObjectList)
    {
        if (ObjectList->objectName().isEmpty())
            ObjectList->setObjectName(QStringLiteral("ObjectList"));
        ObjectList->resize(400, 300);
        comboBox = new QComboBox(ObjectList);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(160, 20, 85, 31));

        retranslateUi(ObjectList);

        QMetaObject::connectSlotsByName(ObjectList);
    } // setupUi

    void retranslateUi(QDialog *ObjectList)
    {
        ObjectList->setWindowTitle(QApplication::translate("ObjectList", "Dialog", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ObjectList", "Object 1", 0)
         << QApplication::translate("ObjectList", "Object 2", 0)
         << QApplication::translate("ObjectList", "Object 3", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class ObjectList: public Ui_ObjectList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECTLIST_H
