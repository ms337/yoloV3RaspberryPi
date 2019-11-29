/**
 * @file objectlist.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2019-10-31
 *
 * @copyright Copyright (c) 2019
 *
 */
#ifndef OBJECTLIST_H
#define OBJECTLIST_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <string>

/**
 * @brief
 *
 */
namespace Ui
{
class ObjectList;
}

/**
 * @brief
 *
 */
class ObjectList : public QDialog
{
    Q_OBJECT

public:
    explicit ObjectList(QWidget *parent = 0);
    ~ObjectList();
    int getObjs(int i);

public slots:
    void save();

private:
    Ui::ObjectList *ui;
    QListWidget *widget;
    QDialogButtonBox *buttonBox;
    QGroupBox *viewBox;
    QPushButton *saveButton;

    void makeObjList();
};

#endif // OBJECTLIST_H
