#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <QKeyEvent>
#include <QApplication>

class EventFilter : public QObject
{
    Q_OBJECT
public:
    EventFilter(QObject* parent = nullptr);

protected:
    virtual bool eventFilter(QObject*, QEvent*);

signals:
    void signalLetter(QString);
};


#endif // EVENTFILTER_H
