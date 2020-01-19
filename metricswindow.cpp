#include "metricswindow.h"
#include "ui_metricswindow.h"

MetricsWindow::MetricsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MetricsWindow)
{
    ui->setupUi(this);
}

MetricsWindow::~MetricsWindow()
{
    delete ui;
}

void MetricsWindow::on_CheckBMIButton_released()
{
    double input = ui->inputLabel->text().toDouble();

    QString Qoutput;
    double output;

    if (ui->comboBoxOutPut->currentText()==("Kilometres"))
    {

        if (ui->comboBox->currentText()==("Kilometres"))
        {
            output = input;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLabel->setText(Qoutput);
        }

        else if (ui->comboBox->currentText()==("Feets"))
        {
            output = input * 3280.8399;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLabel->setText(Qoutput);
        }

        else if (ui->comboBox->currentText()==("Miles"))
        {
            output = input * 0.621371192;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLabel->setText(Qoutput);
        }

    }


    else if (ui->comboBoxOutPut->currentText()==("Feets"))
    {

        if (ui->comboBox->currentText()==("Kilometres"))
        {
            output = input * 0.0003048;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLabel->setText(Qoutput);
        }

        else if (ui->comboBox->currentText()==("Feets"))
        {
            output = input;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLabel->setText(Qoutput);
        }

        else if (ui->comboBox->currentText()==("Miles"))
        {
            output = input * 0.0001893939;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLabel->setText(Qoutput);
        }

    }



  else if (ui->comboBoxOutPut->currentText()==("Miles"))
    {

        if (ui->comboBox->currentText()==("Kilometres"))
        {
            output = input * 1.609344;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLabel->setText(Qoutput);
        }

        else if (ui->comboBox->currentText()==("Feets"))
        {
            output = input * 5280;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLabel->setText(Qoutput);
        }

        else if (ui->comboBox->currentText()==("Miles"))
        {
            output = input;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLabel->setText(Qoutput);
        }

    }


}
