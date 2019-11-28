/********************************************************************************
** Form generated from reading UI file 'histogram.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAM_H
#define UI_HISTOGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Histogram
{
public:
    QCustomPlot *widget;

    void setupUi(QDialog *Histogram)
    {
        if (Histogram->objectName().isEmpty())
            Histogram->setObjectName(QStringLiteral("Histogram"));
        Histogram->resize(400, 300);
        widget = new QCustomPlot(Histogram);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 401, 301));

        retranslateUi(Histogram);

        QMetaObject::connectSlotsByName(Histogram);
    } // setupUi

    void retranslateUi(QDialog *Histogram)
    {
        Histogram->setWindowTitle(QApplication::translate("Histogram", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Histogram: public Ui_Histogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAM_H
