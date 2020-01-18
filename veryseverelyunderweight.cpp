#include "veryseverelyunderweight.h"
#include "ui_veryseverelyunderweight.h"

verySeverelyUnderweight::verySeverelyUnderweight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::verySeverelyUnderweight)
{
    ui->setupUi(this);
}

verySeverelyUnderweight::~verySeverelyUnderweight()
{
    delete ui;
}
