/**
 * @file zonelist.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include "zonelist.h"
#include "ui_zonelist.h"
#include <QDebug>
#include <QMessageBox>


QString coordsArr[8];

/**
 * @brief Construct a new Zone List:: Zone List object
 * 
 * @param parent 
 */
ZoneList::ZoneList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZoneList)
{
    ui->setupUi(this);
}

/**
 * @brief Destroy the Zone List:: Zone List object
 * 
 */
ZoneList::~ZoneList()
{
    delete ui;
}

/**
 * @brief 
 * 
 */
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

/**
 * @brief 
 * 
 * @return QString* 
 */
QString* ZoneList::getCoords() {
    return coordsArr;
}
