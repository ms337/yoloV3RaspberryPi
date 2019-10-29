#ifndef OBJECTLIST_H
#define OBJECTLIST_H

#include <QDialog>

namespace Ui {
class ObjectList;
}

class ObjectList : public QDialog
{
    Q_OBJECT

public:
    explicit ObjectList(QWidget *parent = 0);
    ~ObjectList();

private:
    Ui::ObjectList *ui;
};

#endif // OBJECTLIST_H
