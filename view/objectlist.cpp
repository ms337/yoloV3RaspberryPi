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
#include <string>
#include <iostream>

QString qObjList[80];
std::string sObjList[10];

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
    makeObjList();

    QVBoxLayout* viewLayout = new QVBoxLayout;
    viewBox = new QGroupBox("Objects - select max 10");
    viewLayout->addWidget(widget);
    viewBox->setLayout(viewLayout);

    buttonBox = new QDialogButtonBox;
    saveButton = buttonBox->addButton(QDialogButtonBox::Save);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(viewBox);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
}

/**
 * @brief Destroy the Object List:: Object List object
 * 
 */
ObjectList::~ObjectList()
{
    delete ui;
}

void ObjectList::makeObjList(){
    QStringList strList;
    strList << "Person" << "Banana" << "Laptop" << "Butt";

    widget = new QListWidget;
    widget->addItems(strList);
    for(int i = 0; i < widget->count(); ++i){
        widget->item(i)->setFlags(widget->item(i)->flags() | Qt::ItemIsUserCheckable);
        widget->item(i)->setCheckState(Qt::Unchecked);
    }
}

void ObjectList::save(){
    int j = 0;
    for (int i = 0; i < widget->count(); i++) {
        if (widget->item(i)->checkState() == Qt::Checked) {
            qObjList[j] = widget->item(i)->text();
            sObjList[j] = qObjList[j].toStdString();
            j++;
        }
    }
}

std::string ObjectList::getObjs(int i) {
    return sObjList[i];
}
