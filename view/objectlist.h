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

/**
 * @brief 
 * 
 */
namespace Ui {
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

private:
    Ui::ObjectList *ui;
};

#endif // OBJECTLIST_H
