/**
 * @file mainwindow.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#define MAINWINDOW_H
#include <QMainWindow>

/**
 * @brief 
 * 
 */
namespace Ui
{
class MainWindow;
}

/**
 * @brief 
 * 
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    
    void on_pushButton2_clicked();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
