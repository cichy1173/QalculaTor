#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digitPressed();
//    void on_plusMinusButton_released();
    void on_dotButton_released();

    void unaryOperation_pressed();
    void on_ClearButton_released();
    void on_resButton_released();
    void BinaryOperation_pressed();

    void on_actionAbout_triggered();
    void on_actionBMI_Calc_triggered();
};
#endif // MAINWINDOW_H
