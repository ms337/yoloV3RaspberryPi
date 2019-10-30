#include "objectlist.h"
#include "ui_objectlist.h"

ObjectList::ObjectList(QWidget *parent) : QDialog(parent),
                                          ui(new Ui::ObjectList)
{
    ui->setupUi(this);
}

ObjectList::~ObjectList()
{
    delete ui;
}
