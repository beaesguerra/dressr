#ifndef ADDUI_H
#define ADDUI_H

#include <QWidget>

namespace Ui
{
    class AddUi;
}

class AddUi : public QWidget
{
    Q_OBJECT

public:
    AddUi();
    ~AddUi();

private:
    Ui::AddUi* ui;
};

#endif // ADDUI_H
