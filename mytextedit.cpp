#include "mytextedit.h"

#include <QFile>
#include <QApplication>

MyTextEdit::MyTextEdit()
{
    defaultSettings();
}
void MyTextEdit::defaultSettings()
{
    mp = new QMediaPlayer(this);

    QFont font = this->font();
    font.setPixelSize(24);
    this->setFont(font);

    eventFilter = new EventFilter(this);
    this->installEventFilter(eventFilter);

    connect(eventFilter, SIGNAL(signalLetter(QString)), this, SLOT(slotKeyPress(QString)));
}
void MyTextEdit::slotKeyPress(QString key)
{
    QFile file(QString(QApplication::applicationDirPath() + "/letters/" + key + ".wav"));

    if(file.exists())
    {
        mp->stop();
        mp->setVolume(100);
        mp->setMedia(QUrl::fromLocalFile(file.fileName()) );
        mp->play();
    }
    emit signalLastLetter(key);
}
void MyTextEdit::slotFontChanged(QString font)
{
    this->setFontFamily(font);
}
MyTextEdit::~MyTextEdit()
{
    delete mp;
    delete eventFilter;
}
