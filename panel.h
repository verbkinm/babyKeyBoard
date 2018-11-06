#ifndef PANEL_H
#define PANEL_H

#include <QWidget>

namespace Ui {
class panel;
}

class panel : public QWidget
{
    Q_OBJECT

public:
    explicit panel(QWidget *parent = nullptr);
    ~panel();

    void setFontFamily(QStringList);

signals:
    void signalTextSize(QString);
    void signalColorChange(QColor);
    void signalFontChange(QString);

private:
    Ui::panel *ui;

private slots:
    void slotSelectColor();
};

#endif // PANEL_H
