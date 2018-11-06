#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>
#include <QMediaPlayer>

#include "eventfilter.h"


class MyTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    MyTextEdit();
    ~MyTextEdit();

public slots:
    void slotFontChanged(QString);

private:
    void defaultSettings();

    QMediaPlayer* mp = nullptr;
    EventFilter* eventFilter = nullptr;

private slots:
    void slotKeyPress(QString);

signals:
    void signalLastLetter(QString);

protected:
//    virtual void keyPressEvent(QKeyEvent* key);
};

#endif // MYTEXTEDIT_H
