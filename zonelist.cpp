#include <iostream>
#include "zonelist.h"
#include "ui_zonelist.h"
#include <QDebug>

QStringList strList;

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
    QString coordsArr[8];
    QString coords = ui->textEdit->toPlainText();
    QStringList crds = coords.split(",");
    for(int i=0; i<crds.length(); i++) {
        ui->textBrowser->setText(crds[i]);
        coordsArr[i] = crds[i];
        std::cout << coordsArr[i].toStdString() << std::endl;
    }
}
