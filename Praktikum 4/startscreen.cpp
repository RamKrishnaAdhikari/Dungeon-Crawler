#include "startscreen.h"
#include <QPushButton>
#include "ui_startscreen.h"
#include"graphicalui.h"
#include <QLabel>

    StartScreen::StartScreen(GraphicalUI* gui,QWidget *parent):
    QDialog(parent)
, ui(new Ui::StartScreen)
, gui_m(gui)
{
/*
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(0, 0, 0); border-image: url(:/textures/startscreen.png);");
    auto *button = new QPushButton();
    connect(ui->pushButton, &QPushButton::clicked, this, &StartScreen::buttonclick);
    QIcon icon(":/textures/new_game_button.png");
    ui->pushButton->setIcon(icon);
    QSize p(200,100);
    ui->pushButton->setIconSize(p);
    ui->gridLayout->addWidget(button, 0, 0, Qt::AlignBottom);

    ui->setupUi(this);

    // Set the background color
    this->setStyleSheet("background-color: rgb(0, 0, 0);");

    // Create a QLabel for the background image
    QLabel *backgroundLabel = new QLabel(this);
    QPixmap backgroundPixmap(":/textures/startscreen.png");
    backgroundLabel->setPixmap(backgroundPixmap);
    backgroundLabel->setScaledContents(true);


    connect(ui->pushButton, &QPushButton::clicked, this, &StartScreen::buttonclick);
    QIcon icon(":/textures/new_game_button.png");
    ui->pushButton->setIcon(icon);
    QSize p(200,100);
    ui->pushButton->setIconSize(p);



    // Add the button to the layout

    */


ui->setupUi(this);
this->setStyleSheet("background-color: black;");
QLabel *imageLabel = new QLabel(this);
imageLabel->setScaledContents(true);
QPixmap pixmap(":/textures/startscreen.png"); // Ensure you have the correct path to your image
imageLabel->setPixmap(pixmap);
imageLabel->setGeometry(0, 0, pixmap.width(), pixmap.height()); // Adjust the position and size as needed
imageLabel->show();
//QIcon icon=QIcon("../../assets/textures/new_game_button.png");
connect(ui->pushButton, &QPushButton::clicked, this, &StartScreen::buttonclick);
QIcon buttonIcon(":/textures/new_game_button.png");
ui->pushButton->setIcon(buttonIcon);
ui->pushButton->setIconSize(QSize(200,100));
ui->pushButton->raise();
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

/*void StartScreen::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);

    const int h = ui->centralWidget->height() / 8;
    const int w = ui->centralWidget->width() / 8;

    const int tmp = std::min(h, w);
    auto *widget = ui->gridLayout->itemAtPosition(0, 0)->widget();
    widget->setFixedSize(tmp * (2.5), tmp * (1.5));


}

#include "startscreen.h"
#include <QPushButton>
#include "ui_startscreen.h"
#include "graphicalui.h"
#include <QLabel>

StartScreen::StartScreen(GraphicalUI* gui, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StartScreen)
    , gui_m(gui)
{
    ui->setupUi(this);

    // Set the background color
    this->setStyleSheet("background-color: rgb(0, 0, 0);");

    // Create a QLabel for the background image
    QLabel *backgroundLabel = new QLabel(this);
    QPixmap backgroundPixmap(":/textures/startscreen.png");
    backgroundLabel->setPixmap(backgroundPixmap);
    backgroundLabel->setScaledContents(true);

    // Add the background label to the grid layout
    ui->gridLayout->addWidget(backgroundLabel, 0, 0, 1, 1);

    // Create a container widget for the button
    QWidget *buttonContainer = new QWidget(this);
    QVBoxLayout *buttonLayout = new QVBoxLayout(buttonContainer);
    buttonLayout->setAlignment(Qt::AlignBottom); // Align button to the bottom
    buttonContainer->setLayout(buttonLayout);

    // Create the button
    QPushButton *button = new QPushButton(buttonContainer);
    connect(button, &QPushButton::clicked, this, &StartScreen::buttonclick);

    // Set the icon for the button
    QIcon icon(":/textures/new_game_button.png");
    button->setIcon(icon);
    QSize p(200, 100);
    button->setIconSize(p);

    // Add the button to the layout within the container
    buttonLayout->addWidget(button);

    // Add the container widget to the grid layout at the bottom
    ui->gridLayout->addWidget(buttonContainer, 1, 0, 1, 1, Qt::AlignBottom);

    // Ensure the background label stays behind other widgets
    backgroundLabel->lower();
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

    // Adjust the button size based on the window size
    const int h = ui->centralWidget->height() / 8;
    const int w = ui->centralWidget->width() / 8;

    const int tmp = std::min(h, w);
    auto *widget = ui->gridLayout->itemAtPosition(1, 0)->widget(); // Adjusted to position 1, 0 for the button container
    widget->setFixedSize(tmp * 2.5, tmp * 1.5);
}
*/
