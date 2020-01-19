#ifndef TEMPERATUREWINDOW_H
#define TEMPERATUREWINDOW_H

#include <QDialog>

namespace Ui {
class TemperatureWindow;
}

class TemperatureWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TemperatureWindow(QWidget *parent = nullptr);
    ~TemperatureWindow();

private slots:
    void on_CheckBMIButton_released();

private:
    Ui::TemperatureWindow *ui;
};

#endif // TEMPERATUREWINDOW_H
