#include "panel.h"
#include "ui_panel.h"

#include <QPushButton>
#include <QColorDialog>
#include <QFontDatabase>


panel::panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::panel)
{
    ui->setupUi(this);

    connect(ui->textSize, SIGNAL(currentTextChanged(QString)), this, SIGNAL(signalTextSize(QString)));
    connect(ui->color, SIGNAL(clicked()), this, SLOT(slotSelectColor()));
    connect(ui->FontFamily, SIGNAL(currentTextChanged(QString)), this, SIGNAL(signalFontChange(QString)));

    QFontDatabase fonts;
    this->setFontFamily(fonts.families());

    ui->textSize->setCurrentText("24");
    ui->FontFamily->setCurrentText("Times New Roman");
}
void panel::setFontFamily(QStringList list)
{
    ui->FontFamily->addItems(list);
}
void panel::slotSelectColor()
{
   emit signalColorChange( QColorDialog::getColor(Qt::black, this, "Выбор цвета текста") );
}

panel::~panel()
{
    delete ui;
}
