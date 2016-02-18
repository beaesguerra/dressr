#ifndef DRESSR_UI_H
#define DRESSR_UI_H

#include <QString>
#include <QWidget>

namespace Ui 
{
	class DressrUi;
}

class PickUi;
class ClosetUi;
class AddUi;
class AddClothesConfirmationUi;

class DressrUi : public QWidget
{
    Q_OBJECT

public:
    DressrUi();
    DressrUi(PickUi* pickUi, ClosetUi* closetUi);
    ~DressrUi();

public slots:
	void pickTabClicked();
	void closetTabClicked();
    void addTabClicked();
    void confirmClothes(QString path);

private:
    Ui::DressrUi* ui;
    PickUi* pickUi;
    ClosetUi* closetUi;
    AddUi* addUi;
    AddClothesConfirmationUi* addClothesConfirmation;
};

#endif // DRESSR_UI_H
