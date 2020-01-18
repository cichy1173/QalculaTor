#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <math.h>
#include "aboutwindow.h"
#include "bmicalc.h"

double firstNumber;
bool isTypingSecondNumber = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->oneButton,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->TwoButton,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->ThreeButton,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->fourButton,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->fiveButton,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->sixButton,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->sevenButton,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->eightButton,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->nineButton,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->zeroButton,SIGNAL(released()),this,SLOT(digitPressed()));

    connect(ui->plusMinusButton,SIGNAL(released()),this,SLOT(unaryOperation_pressed()));

    connect(ui->addButton,SIGNAL(released()),this,SLOT(BinaryOperation_pressed()));
    connect(ui->subButton,SIGNAL(released()),this,SLOT(BinaryOperation_pressed()));
    connect(ui->multiButton,SIGNAL(released()),this,SLOT(BinaryOperation_pressed()));
    connect(ui->divButton,SIGNAL(released()),this,SLOT(BinaryOperation_pressed()));
    connect(ui->sqrtButton,SIGNAL(released()),this,SLOT(BinaryOperation_pressed()));


    ui->addButton->setCheckable(true);
    ui->subButton->setCheckable(true);
    ui->multiButton->setCheckable(true);
    ui->divButton->setCheckable(true);
    ui->sqrtButton->setCheckable(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::digitPressed()
{
//    qDebug() << "Pressed";

    QPushButton* button = (QPushButton*)sender();

    QString newLabel;
    double labelNumber;

    if((ui->addButton->isChecked() || ui->subButton->isChecked() ||
            ui->multiButton->isChecked() || ui->divButton->isChecked()) &&
            (!isTypingSecondNumber))
    {
        labelNumber = (button->text()).toDouble();
        isTypingSecondNumber = true;
        newLabel = QString::number(labelNumber, 'g', 15);
    }
    else
    {
        if (ui->display->text().contains(".") && button->text()== "0")
        {
            newLabel = ui->display->text() + button->text();
        }
        else
        {
            labelNumber = (ui->display->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber, 'g', 15);
        }
    }

    ui->display->setText(newLabel);

}


//void MainWindow::on_plusMinusButton_released()
//{

//}

void MainWindow::on_dotButton_released()
{
    ui->display->setText(ui->display->text() +".");
}


void MainWindow::unaryOperation_pressed()
{
    double labelNumber;
    QString newLabel;
    QPushButton* button = (QPushButton*)sender();
    if (button->text() =="+/-")
    {
        labelNumber = ui->display->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->display->setText(newLabel);
    }
}

void MainWindow::on_ClearButton_released()
{
    ui->display->setText("0");
    ui->addButton->setChecked(false);
    ui->subButton->setChecked(false);
    ui->multiButton->setChecked(false);
    ui->divButton->setChecked(false);
    ui->sqrtButton->setChecked(false);

    isTypingSecondNumber = false;

}

void MainWindow::on_resButton_released()
{
    double labelNumber, secondNumber;

    secondNumber = ui->display->text().toDouble();

    QString newLabel;

    if(ui->addButton->isChecked())
    {
        labelNumber = firstNumber + secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->display->setText(newLabel);
        ui->addButton->setChecked(false);
    }

    else if(ui->subButton->isChecked())
    {
        labelNumber = firstNumber - secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->display->setText(newLabel);
        ui->subButton->setChecked(false);

    }

    else if(ui->multiButton->isChecked())
    {
        labelNumber = firstNumber * secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->display->setText(newLabel);
        ui->multiButton->setChecked(false);

    }

    else if(ui->divButton->isChecked())
    {
       if (firstNumber == 0)
       {
           ui->display->setText("impossible action");
       }
       else
       {
        labelNumber = firstNumber / secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->display->setText(newLabel);
        ui->divButton->setChecked(false);
       }

    }

    else if(ui->sqrtButton->isChecked())
    {
        if (firstNumber < 1)
        {
            ui->display->setText("impossible action");
        }
        else
        {
            double sqrtResult = sqrt(firstNumber);
            QString QsqrtResult = QString::number(sqrtResult, 'g', 15);
            ui->display->setText(QsqrtResult);
            ui->sqrtButton->setChecked(false);
        }
    }

    isTypingSecondNumber = false;
}

void MainWindow::BinaryOperation_pressed()
{
    QPushButton* button = (QPushButton*)sender();


    firstNumber = ui->display->text().toDouble();


    button->setChecked(true);


}


void MainWindow::on_actionAbout_triggered()
{
    AboutWindow mAbout;
    mAbout.setModal(true);
    mAbout.exec();
}

void MainWindow::on_actionBMI_Calc_triggered()
{
    BMICalc mBMI;
    mBMI.setModal(true);
    mBMI.exec();
}
