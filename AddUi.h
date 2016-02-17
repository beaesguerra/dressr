#ifndef ADDUI_H
#define ADDUI_H

#include <QWidget>
#include <QString>

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

public slots:
    void captureImage();
    void imageSaved(QString url);

private:
    Ui::AddUi* ui;
};

#endif // ADDUI_H
