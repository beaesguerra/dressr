#ifndef DRESSR_UI_H
#define DRESSR_UI_H

#include <QWidget>

namespace Ui 
{
	class DressrUi;
}

class PickUi;
class ClosetUi;

class DressrUi : public QWidget
{
    Q_OBJECT

public:
    DressrUi();
    ~DressrUi();

public slots:
	void pickTabClicked();
	void closetTabClicked();

private:
    Ui::DressrUi* ui;
    PickUi* pickUi;
    ClosetUi* closetUi;
};

#endif // DRESSR_UI_H