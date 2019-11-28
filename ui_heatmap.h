/********************************************************************************
** Form generated from reading UI file 'heatmap.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEATMAP_H
#define UI_HEATMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Heatmap
{
public:
    QCustomPlot *widget;

    void setupUi(QDialog *Heatmap)
    {
        if (Heatmap->objectName().isEmpty())
            Heatmap->setObjectName(QStringLiteral("Heatmap"));
        Heatmap->resize(400, 300);
        widget = new QCustomPlot(Heatmap);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 401, 301));

        retranslateUi(Heatmap);

        QMetaObject::connectSlotsByName(Heatmap);
    } // setupUi

    void retranslateUi(QDialog *Heatmap)
    {
        Heatmap->setWindowTitle(QApplication::translate("Heatmap", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Heatmap: public Ui_Heatmap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEATMAP_H
