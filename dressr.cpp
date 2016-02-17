#include "dressr.h"
#include "ui_dressr.h"

Dressr::Dressr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dressr)
{
    ui->setupUi(this);

    Closet closet();
    mdWriter(closet);
}

Dressr::~Dressr()
{
    delete ui;
}
