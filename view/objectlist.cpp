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

using namespace std;

QString qObjList[80];
int sObjList[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
QStringList strList = {"person", "bicycle", "car", "motorcycle", "airplane", "bus", "train", "truck", "boat", "traffic light", "fire hydrant", "stop_sign", "parking meter", "bench", "bird", "cat", "dog", "horse", "sheep", "cow", "elephant", "bear", "zebra", "giraffe", "backpack", "umbrella", "handbag", "tie", "suitcase", "frisbee", "skis", "snowboard", "sports ball", "kite", "baseball bat", "baseball glove", "skateboard", "surfboard", "tennis racket", "bottle", "wine glass", "cup", "fork", "knife", "spoon", "bowl", "banana", "apple", "sandwich", "orange", "broccoli", "carrot", "hot dog", "pizza", "doughnut", "cake", "chair", "couch", "potted plant", "bed", "dining table", "toilet", "tv", "laptop", "mouse", "remote", "keyboard", "cell phone", "microwave", "oven", "toaster", "sink", "refrigerator", "book", "clock", "vase", "scissors", "teddy bear", "hair dryer", "toothbrush"};

/**
 * @brief Construct a new Object List:: Object List object
 *
 * @param parent
 */
ObjectList::ObjectList(QWidget *parent) : QDialog(parent),
                                          ui(new Ui::ObjectList)
{
    ui->setupUi(this);
    makeObjList();

    QVBoxLayout *viewLayout = new QVBoxLayout;
    viewBox = new QGroupBox("Objects - select max 10");
    viewLayout->addWidget(widget);
    viewBox->setLayout(viewLayout);

    buttonBox = new QDialogButtonBox;
    saveButton = buttonBox->addButton(QDialogButtonBox::Save);

    QVBoxLayout *mainLayout = new QVBoxLayout;
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
/*!
   \brief used in the ui to list all the selectable objects to be tracked
*/
void ObjectList::makeObjList()
{
    widget = new QListWidget;
    widget->addItems(strList);
    for (int i = 0; i < widget->count(); ++i)
    {
        widget->item(i)->setFlags(widget->item(i)->flags() | Qt::ItemIsUserCheckable);
        widget->item(i)->setCheckState(Qt::Unchecked);
    }
}
/*!
   \brief "saves the selected objects in the object list displayed in the ui
*/
void ObjectList::save()
{
    int j = 0;
    for (int i = 0; i < widget->count(); i++)
    {
        if (widget->item(i)->checkState() == Qt::Checked)
        {
            qObjList[j] = widget->item(i)->text();
            for (int k = 0; k < 80; k++)
            {
                if (qObjList[j].toStdString().compare(strList[k].toStdString()) == 0)
                {
                    sObjList[j] = k;
                    j++;
                }
            }
        }
    }
}
/*!
   \brief used to return the numerical representation of an object
   \param object value in the object list
   \return numerical representation of the object
*/
int ObjectList::getObjs(int i)
{
    return sObjList[i];
}
