#include "startscreen.h"
#include <QPushButton>
#include "ui_startscreen.h"
#include"graphicalui.h"
#include <QLabel>

    StartScreen::StartScreen(GraphicalUI* gui,QWidget *parent):
    QDialog(parent)
, ui(new Ui::StartScreen)
, gui_m(gui){
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(0, 0, 0); border-image: url(:/textures/startscreen.png);");





    auto *button = new QPushButton();
    connect(ui->pushButton, &QPushButton::clicked, this, &StartScreen::buttonclick);
    QIcon icon(":/textures/new_game_button.png");
    ui->pushButton->setIcon(icon);
    QSize p(200,100);
    ui->pushButton->setIconSize(p);
    ui->gridLayout->addWidget(button, 0, 0, Qt::AlignBottom);


}

StartScreen::~StartScreen()
{
    delete ui;
}

void StartScreen::buttonclick()
{
    if (gui_m)
    {
        gui_m->showGameScreen();
    }
}

void StartScreen::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);

    const int h = ui->centralWidget->height() / 8;
    const int w = ui->centralWidget->width() / 8;

    const int tmp = std::min(h, w);
    auto *widget = ui->gridLayout->itemAtPosition(0, 0)->widget();
    widget->setFixedSize(tmp * (2.5), tmp * (1.5));


}
