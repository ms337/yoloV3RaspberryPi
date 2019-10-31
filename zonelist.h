#ifndef ZONELIST_H
#define ZONELIST_H

#include <QDialog>

namespace Ui {
class ZoneList;
}

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
