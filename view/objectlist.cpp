/**
 * @file objectlist.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "objectlist.h"
#include "ui_objectlist.h"

/**
 * @brief Construct a new Object List:: Object List object
 * 
 * @param parent 
 */
ObjectList::ObjectList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ObjectList)
{
    ui->setupUi(this);
}

/**
 * @brief Destroy the Object List:: Object List object
 * 
 */
ObjectList::~ObjectList()
{
    delete ui;
}
