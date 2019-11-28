/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListView *objectsList;
    QListView *zonesList;
    QLabel *object;
    QPushButton *pushButton;
    QPushButton *pushButton2;
    QWidget *camera;
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *startStopButton;
    QPushButton *histButton;
    QPushButton *heatmapButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(825, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        objectsList = new QListView(centralWidget);
        objectsList->setObjectName(QStringLiteral("objectsList"));
        objectsList->setGeometry(QRect(580, 0, 241, 411));
        zonesList = new QListView(centralWidget);
        zonesList->setObjectName(QStringLiteral("zonesList"));
        zonesList->setGeometry(QRect(0, 291, 581, 121));
        object = new QLabel(centralWidget);
        object->setObjectName(QStringLiteral("object"));
        object->setGeometry(QRect(660, 110, 68, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(630, 0, 131, 31));
        pushButton2 = new QPushButton(centralWidget);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));
        pushButton2->setGeometry(QRect(230, 290, 131, 31));
        camera = new QWidget(centralWidget);
        camera->setObjectName(QStringLiteral("camera"));
        camera->setGeometry(QRect(0, 0, 581, 291));
        label = new QLabel(camera);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 10, 571, 281));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(640, 100, 104, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(610, 40, 171, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(620, 70, 151, 21));
        startStopButton = new QPushButton(centralWidget);
        startStopButton->setObjectName(QStringLiteral("startStopButton"));
        startStopButton->setGeometry(QRect(50, 380, 101, 31));
        histButton = new QPushButton(centralWidget);
        histButton->setObjectName(QStringLiteral("histButton"));
        histButton->setGeometry(QRect(250, 380, 101, 31));
        heatmapButton = new QPushButton(centralWidget);
        heatmapButton->setObjectName(QStringLiteral("heatmapButton"));
        heatmapButton->setGeometry(QRect(450, 380, 101, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 825, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        object->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Add New Zones", Q_NULLPTR));
        pushButton2->setText(QApplication::translate("MainWindow", "Add New Object", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Set how many zones?", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "(Default: 3, Max 30)", Q_NULLPTR));
        startStopButton->setText(QApplication::translate("MainWindow", "Start/Stop", Q_NULLPTR));
        histButton->setText(QApplication::translate("MainWindow", "Histogram", Q_NULLPTR));
        heatmapButton->setText(QApplication::translate("MainWindow", "Heatmap", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
