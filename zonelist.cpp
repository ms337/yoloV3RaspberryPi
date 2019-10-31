#include <iostream>
#include "zonelist.h"
#include "ui_zonelist.h"
#include <QDebug>
#include <QMessageBox>

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
    if (crds.length() == 8) {
        for(int i=0; i<8; i++) {
            coordsArr[i] = crds[i];
            ui->textBrowser->setText(coordsArr[i]);
        }
        this->close();
    } else {
        QMessageBox::warning(
            this,
            tr("Application Name"),
            tr("Bad Format") );
        this->close();
    }
}

QString* ZoneList::getCoords() {
    return coordsArr;
}
