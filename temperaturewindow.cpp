#include "temperaturewindow.h"
#include "ui_temperaturewindow.h"

TemperatureWindow::TemperatureWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TemperatureWindow)
{
    ui->setupUi(this);
}

TemperatureWindow::~TemperatureWindow()
{
    delete ui;
}

void TemperatureWindow::on_CheckBMIButton_released()
{
    double input;
    input = ui->InputLine->text().toDouble();

    double output;
    QString Qoutput;

    if (ui->comboBoxOutput->currentText()=="Celsius")
    {
        if (ui->comboBox->currentText()=="Fahrenheit")
        {
            output = input + 33.8;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLine->setText(Qoutput);
        }

        else if (ui->comboBox->currentText()=="Kelvin")
        {
            output = input + 274.15;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLine->setText(Qoutput);
        }

        else if (ui->comboBox->currentText()=="Celsius")
        {
            output = input;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLine->setText(Qoutput);
        }
    }


   else if (ui->comboBoxOutput->currentText()=="Fahrenheit")
    {
        if (ui->comboBox->currentText()=="Fahrenheit")
        {
            output = input;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLine->setText(Qoutput);
        }

        else if (ui->comboBox->currentText()=="Kelvin")
        {
            output = input + 255.927778;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLine->setText(Qoutput);
        }

        else if (ui->comboBox->currentText()=="Celsius")
        {
            output = input - 17.2222;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLine->setText(Qoutput);
        }
    }


   else if (ui->comboBoxOutput->currentText()=="Kelvin")
    {
        if (ui->comboBox->currentText()=="Fahrenheit")
        {
            output = input - 457.87;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLine->setText(Qoutput);
        }

        else if (ui->comboBox->currentText()=="Kelvin")
        {
            output = input;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLine->setText(Qoutput);
        }

        else if (ui->comboBox->currentText()=="Celsius")
        {
            output = input - 272.15;
            Qoutput = QString::number(output, 'g', 15);
            ui->OutputLine->setText(Qoutput);
        }
    }


}
