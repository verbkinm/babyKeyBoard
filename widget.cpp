#include "widget.h"

#include <QIcon>
#include <QColor>

#define START_TEXT "Привет!\n"



Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    defaultSettings();

    connect(pTextEdit, SIGNAL(signalLastLetter(QString)), this,     SLOT(slotLastLetter(QString)));

    connect(pPanel, SIGNAL(signalTextSize(QString)),    this,       SLOT(slotTextSize(QString)));
    connect(pPanel, SIGNAL(signalColorChange(QColor)),  this,       SLOT(slotSetTextColor(QColor)));
    connect(pPanel, SIGNAL(signalFontChange(QString)),  pTextEdit,  SLOT(slotFontChanged(QString)));

}
void Widget::defaultSettings()
{
    pLayuot     = new QVBoxLayout();
    pTextEdit   = new MyTextEdit();
    pLabel      = new QLabel();
    pPanel      = new panel();

    pLabel->setAlignment(Qt::AlignCenter);
    QFont font = pLabel->font();
    font.setPixelSize(256);
    pLabel->setFont(font);

    pLayuot->addWidget(pPanel);
    pLayuot->addWidget(pTextEdit);
    pLayuot->addWidget(pLabel);

    this->setLayout(pLayuot);

    pTextEdit->setFocus();
    pTextEdit->append(START_TEXT);

    this->setWindowIcon(QIcon(":/keyboard"));
}
void Widget::slotTextSize(QString size)
{
    QFont font = pTextEdit->font();
    font.setPixelSize(size.toInt());
    pTextEdit->setFont(font);
}
void Widget::slotLastLetter(QString letter)
{
    pLabel->setText(letter);
}
void Widget::slotSetTextColor(QColor color)
{
    pTextEdit->setTextColor(color);
    pTextEdit->setFocus();
}

Widget::~Widget()
{
    delete pLayuot;
    delete pTextEdit;

    delete pLabel;
    delete pPanel;
}


