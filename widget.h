#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

#include "mytextedit.h"
#include "panel.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QVBoxLayout*    pLayuot     = nullptr;
    MyTextEdit*     pTextEdit   = nullptr;
    QLabel*         pLabel      = nullptr;
    panel*          pPanel      = nullptr;

    void defaultSettings();

private slots:
    void slotLastLetter(QString);
    void slotTextSize(QString);

    void slotSetTextColor(QColor);
};

#endif // WIDGET_H
