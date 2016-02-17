#ifndef DRESSR_UI_H
#define DRESSR_UI_H

#include <QWidget>

namespace Ui 
{
	class DressrUi;
}

class PickUi;

class DressrUi : public QWidget
{
    Q_OBJECT

public:
    DressrUi();
    ~DressrUi();

private:
    Ui::DressrUi* ui;
    PickUi* pickUi;
};

#endif // DRESSR_UI_H