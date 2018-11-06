#include "eventfilter.h"

EventFilter::EventFilter(QObject *parent) : QObject(parent)
{

}
/*virtual*/ bool EventFilter::eventFilter(QObject* obj, QEvent* event)
{
    if(event->type() == QEvent::KeyRelease){
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        QString letter = keyEvent->text().toUpper();
        emit signalLetter(letter);
    }

    return false;
}
