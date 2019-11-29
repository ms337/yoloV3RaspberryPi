#ifndef HEATMAP_H
#define HEATMAP_H

#include <QDialog>
#include "../model/DatabaseReader.h"

namespace Ui
{
class Heatmap;
}

class Heatmap : public QDialog
{
    Q_OBJECT

public:
    explicit Heatmap(QWidget *parent = 0);
    ~Heatmap();

private:
    Ui::Heatmap *ui;
};

#endif // HEATMAP_H
