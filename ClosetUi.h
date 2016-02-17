#ifndef CLOSET_UI_H
#define CLOSET_UI_H

#include <QWidget>

namespace Ui 
{
	class ClosetUi;
}

class ClosetUi : public QWidget
{
    Q_OBJECT

public:
    ClosetUi();
    ~ClosetUi();

private:
    Ui::ClosetUi* ui;
};

#endif // CLOSET_UI_H
