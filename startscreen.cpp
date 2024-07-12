#include "startscreen.h"
<<<<<<< HEAD
#include "ui_startscreen.h"
#include "mainwindow.h"
#include <QPushButton>

StartScreen::StartScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartScreen)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(0,0,0); border-image: url(:textures/startscreen.png);");

    auto* button = new QPushButton();
    button->setFixedSize(200, 100);
    button->setStyleSheet("border-image: url(:/textures/new_game_button.png);");
    ui->gridLayout->addWidget(button, 0, 0, Qt::AlignBottom);
    connect(button, SIGNAL(clicked()), this, SLOT(buttonclick()));
=======
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


>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
}

StartScreen::~StartScreen()
{
    delete ui;
<<<<<<< HEAD
    ui = nullptr;
=======
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
}

void StartScreen::buttonclick()
{
<<<<<<< HEAD
    this->close();
}

void StartScreen::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);

    const int h = ui->centralWidget->height()/8;
    const int w = ui->centralWidget->width()/8;

    const int tmp = std::min(h,w);
    auto* widget = ui->gridLayout->itemAtPosition(0,0)->widget();
    widget->setFixedSize(tmp*2.5,tmp*1.5);
=======
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


>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
}
