#include "dressr.h"
#include "ui_dressr.h"

Dressr::Dressr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dressr)
{
    ui->setupUi(this);
}

Dressr::~Dressr()
{
    delete ui;
}
