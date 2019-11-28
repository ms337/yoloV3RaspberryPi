/********************************************************************************
** Form generated from reading UI file 'objectlist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECTLIST_H
#define UI_OBJECTLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_ObjectList
{
public:
    QListWidget *listWidget;

    void setupUi(QDialog *ObjectList)
    {
        if (ObjectList->objectName().isEmpty())
            ObjectList->setObjectName(QStringLiteral("ObjectList"));
        ObjectList->resize(400, 300);
        listWidget = new QListWidget(ObjectList);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 401, 301));

        retranslateUi(ObjectList);

        QMetaObject::connectSlotsByName(ObjectList);
    } // setupUi

    void retranslateUi(QDialog *ObjectList)
    {
        ObjectList->setWindowTitle(QApplication::translate("ObjectList", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ObjectList: public Ui_ObjectList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECTLIST_H
