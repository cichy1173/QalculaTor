#ifndef METRICSWINDOW_H
#define METRICSWINDOW_H

#include <QMainWindow>

namespace Ui {
class MetricsWindow;
}

class MetricsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MetricsWindow(QWidget *parent = nullptr);
    ~MetricsWindow();

private slots:
    void on_CheckBMIButton_released();

private:
    Ui::MetricsWindow *ui;
};

#endif // METRICSWINDOW_H
