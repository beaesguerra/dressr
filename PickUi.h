#ifndef PICK_UI_H
#define PICK_UI_H

#include <QWidget>

namespace Ui 
{
	class PickUi;
}

class PickUi : public QWidget
{
    Q_OBJECT

public:
    PickUi();
    ~PickUi();

private:
    Ui::PickUi* ui;
};

#endif // PICK_UI_H
