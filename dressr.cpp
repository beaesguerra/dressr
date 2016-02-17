#include "dressr.h"
#include "ui_dressr.h"

Dressr::Dressr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dressr),
    closet()
{
    ui->setupUi(this);

    mdWriter.load(closet);
}

Dressr::~Dressr()
{
    mdWriter.save(closet);
    delete ui;
}
