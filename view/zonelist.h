/**
 * @file zonelist.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef ZONELIST_H
#define ZONELIST_H

#include <QDialog>

/**
 * @brief 
 * 
 */
namespace Ui {
class ZoneList;
}

/**
 * @brief 
 * 
 */
class ZoneList : public QDialog
{
    Q_OBJECT

public:
    explicit ZoneList(QWidget *parent = 0);
    ~ZoneList();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ZoneList *ui;
    
public:
    QString* getCoords();
};

#endif // ZONELIST_H
