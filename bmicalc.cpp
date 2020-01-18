#include "bmicalc.h"
#include "ui_bmicalc.h"


BMICalc::BMICalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BMICalc)
{
    ui->setupUi(this);
}

BMICalc::~BMICalc()
{
    delete ui;
}

void BMICalc::on_CheckBMIButton_clicked()
{
    //bmi= (weight in kilograms) divided by (squared height in metres)

    double usersBMI, usersWeight, usersHeight;
    usersWeight = ui->weightLineEdit->text().toDouble();
    usersHeight = ui->heightLineEdit->text().toDouble();
    usersBMI = usersWeight / (usersHeight * usersHeight);
    QString Result;
    QString QResultNumber = QString::number(usersBMI, 'g', 2);
    ui->userBMIInput->setText(QResultNumber);

    if (usersBMI < 16.0) //very severely underweight
    {
        Result ="Your BMI is really to low. You should see your doctor as fast as you can";
        ui->ResultEdit->setText(Result);

    }

    else if (usersBMI >= 16.0 && usersBMI < 17.0) // severely underweight
    {
        Result ="Your BMI is to low. You should see your doctor";
        ui->ResultEdit->setText(Result);

    }

    else if (usersBMI >= 17.0 && usersBMI < 18.5) //underweight
    {
        Result ="Your BMI is to a little bit low. You should eat more often";
        ui->ResultEdit->setText(Result);
    }

    else if (usersBMI >= 18.5 && usersBMI < 25.0) //Normal
    {
        Result ="Your BMI is OK! You can go to McDonald's and not worry about it";
        ui->ResultEdit->setText(Result);
    }

    else if (usersBMI >=25.0 && usersBMI < 30) //Obese Class I
    {
        Result ="Your BMI is a little bit to big. You should exercise more";
        ui->ResultEdit->setText(Result);
    }

    else if (usersBMI >= 30 && usersBMI < 35) //Obese Class II
    {
        Result ="Your BMI is to big. You should see your doctor";
        ui->ResultEdit->setText(Result);
    }

    else if (usersBMI >=35) //Obesse Class II
    {
        Result ="Your BMI is really to big. You should see your doctor as fast as you can";
        ui->ResultEdit->setText(Result);
    }

}
