#ifndef DRESSR_UI_H
#define DRESSR_UI_H

#include <QWidget>

namespace Ui 
{
	class DressrUi;
}

class PickUi;
class ClosetUi;
class AddUi;

class DressrUi : public QWidget
{
    Q_OBJECT

public:
    DressrUi();
    ClosetUi * getClosetUi();
    ~DressrUi();

public slots:
	void pickTabClicked();
	void closetTabClicked();
    void addTabClicked();

private:
    Ui::DressrUi* ui;
    PickUi* pickUi;
    ClosetUi* closetUi;
    AddUi* addUi;
};

#endif // DRESSR_UI_H
