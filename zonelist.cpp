#include <iostream>
#include "zonelist.h"
#include "ui_zonelist.h"
#include <QDebug>

QString coordsArr[8];

ZoneList::ZoneList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZoneList)
{
    ui->setupUi(this);
}

ZoneList::~ZoneList()
{
    delete ui;
}

void ZoneList::on_pushButton_clicked()
{
    QString coords = ui->textEdit->toPlainText();
    QStringList crds = coords.split(",");
    for(int i=0; i<8; i++) {
        coordsArr[i] = crds[i];
        ui->textBrowser->setText(coordsArr[i]);
    }
    this->close();
}

QString* ZoneList::getCoords() {
    return coordsArr;
}
