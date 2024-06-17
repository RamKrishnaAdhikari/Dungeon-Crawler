
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "character.h"
#include "level.h"
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <iostream>
#include <QObject>
#include <QGridLayout>
#include<ctime>
#include"portal.h"

MainWindow::MainWindow(DungeonCrawler* dc, QWidget* parent)
    : QMainWindow{parent},
    ui_m(new Ui::MainWindow),
    dc(dc), cur_pos_row(0), cur_pos_col(0)
{
    ui_m->setupUi(this);

    this->setStyleSheet("background-color: rgb(0, 0, 0); border-image: url(:/textures/bloody_frame.png);");

    ui_m->verticalLayout->setContentsMargins(10, 100, 10, 10);

    QGridLayout* l = ui_m->tiles;

    level = dc->getLevel();

    for (int row = 0; row < level->getHeight(); row++)
    {
        for (int col = 0; col < level->getWidth(); col++)
        {

            QLabel* widget = new QLabel(nullptr);

            widget->setScaledContents(true);

            std::string texture = level->getTile(row, col)->getTexture();
            char* tex_c= texture.data();
            if (*tex_c == 'C')
            {
                widget->setPixmap(QPixmap(":/textures/floor/floor1.png"));
            }
            l->addWidget(widget, row, col, Qt::AlignCenter);
        }
    }
    l->setAlignment(Qt::AlignHCenter);
}

MainWindow::~MainWindow()
{
    delete ui_m;
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);

    Level* level = dc->getLevel();

    const int w = ui_m->centralwidget->width() / level->getHeight();
    const int h = ui_m->centralwidget->height() / level->getWidth();

    const int opt = std::min(w, h);

    ui_m->verticalLayout->setContentsMargins(opt, opt * 1.5, opt, opt * 0.5);

    for (int row = 0; row < level->getHeight(); row++)
    {
        for (int col = 0; col < level->getWidth(); col++)
        {
            QWidget* widget = ui_m->tiles->itemAtPosition(row, col)->widget();
            widget->setFixedSize(opt * 0.80, opt * 0.80);
        }
    }
}

void initializeRandom() {
    std::srand(std::time(0));
}
void MainWindow::draw(Level* level)
{
    for (int row = 0; row < level->getHeight(); row++)
    {
        for (int col = 0; col < level->getWidth(); col++)
        {
            QWidget* widget1 = ui_m->tiles->itemAtPosition(row, col)->widget();

            QLabel* widget = qobject_cast<QLabel*>(widget1);

            std::string texture = level->getTile(row, col)->getTexture();
            char* tex_c = texture.data();

            int tmp = (row + col) % 5;

            if (*tex_c == '.')
            {
                if (tmp == 0)
                {
                    widget->setPixmap(QPixmap(":/textures/floor/floor1.png"));
                }
                if (tmp == 1)
                {
                    widget->setPixmap(QPixmap(":/textures/floor/floor2.png"));
                }
                if (tmp == 2)
                {
                    widget->setPixmap(QPixmap(":/textures/floor/floor3.png"));
                }
                if (tmp == 3)
                {
                    widget->setPixmap(QPixmap(":/textures/floor/floor4.png"));
                }
                if (tmp == 4)
                {
                    widget->setPixmap(QPixmap(":/textures/floor/floor5.png"));
                }
            }

            else if (*tex_c == '#')
            {
                widget->setPixmap(QPixmap(":/textures/wall/wall1.png"));
            }
            else if (*tex_c == '<')
            {
                widget->setPixmap(QPixmap(":/textures/ramp.png"));
            }
            else if (*tex_c == '_')
            {
                widget->setPixmap(QPixmap(":/textures/pit.png"));
                widget->setStyleSheet("background: transparent;");
            }
            else if (*tex_c == 'O')
            {
                Portal* portal = dynamic_cast<Portal*>(level->getTile(row, col));
                int portalType = portal->getportaltype();
                widget->setPixmap(QPixmap(":/textures/portal/portal" + QString::number(portalType) + ".png"));
            }
            else if (*tex_c == '?')
            {
                widget->setPixmap(QPixmap(":/textures/switch.png"));
            }
            else if (*tex_c == 'X')
            {
                widget->setPixmap(QPixmap(":/textures/doors/door1.png"));
            }
            else if (*tex_c == '/')
            {
                widget->setPixmap(QPixmap(":/textures/doors/door2.png"));
            }
            if (level->getTile(row, col)->hasCharacter())
            {
                QLabel* charac = new QLabel(nullptr);

                cur_pos_row = row;
                cur_pos_col = col;

                charac->setStyleSheet("background: transparent; border-image: none;");

                Input moved_dir = level->getTile(row, col)->getCharacter()->getMoveDirection();

                if (moved_dir.getVertical() == -1)
                {
                    charac->setPixmap(QPixmap(":/textures/char/back/char_back_2.png"));
                }
                if (moved_dir.getVertical() == 1)
                {
                    charac->setPixmap(QPixmap(":/textures/char/front/char_front_2.png"));
                }
                if (moved_dir.getHorizontal() == 1)
                {
                    charac->setPixmap(QPixmap(":/textures/char/right/char_right_2.png"));
                }
                if (moved_dir.getHorizontal() == -1)
                {
                    charac->setPixmap(QPixmap(":/textures/char/left/char_left_2.png"));
                }
                if (moved_dir.getExit())
                {
                    charac->setPixmap(QPixmap(":/textures/char/front/char_front_2.png"));
                }
                charac->setFixedSize(55, 55);
                charac->setScaledContents(true);
                charac->setParent(nullptr);
                ui_m->tiles->addWidget(charac, row, col, Qt::AlignCenter);

                if (*tex_c=='_')
                {
                    charac->lower();
                }
            }
        }
    }

    const int w = ui_m->centralwidget->width() / level->getHeight();
    const int h = ui_m->centralwidget->height() / level->getWidth();

    const int opt = std::min(w, h);

    ui_m->verticalLayout->setContentsMargins(opt, opt * 1.5, opt, opt * 0.5);

    for (int row = 0; row < level->getHeight(); row++)
    {
        for (int col = 0; col < level->getWidth(); col++)
        {
            QWidget* widget = ui_m->tiles->itemAtPosition(row, col)->widget();
            widget->setFixedSize(opt * 0.80, opt * 0.80);
        }
    }
}


void MainWindow::remove_exis_char()
{
    QWidget* widget = ui_m->tiles->itemAtPosition(cur_pos_row,cur_pos_col)->widget();
    ui_m->tiles->removeWidget(widget);
    widget->setParent(nullptr);
    delete widget;
}


void MainWindow::on_upleft_clicked()
{
    remove_exis_char();
    if (dc->turn(Input(0, -1, false)))
    {
        if (!(dc->turn(Input(-1, 0, false))))
        {
            dc->turn(Input(0, 1, false));
            dc->turn(Input(0, 0, true));
        }
    }
    else if (dc->turn(Input(-1,0,false)))
    {
        if (!(dc->turn(Input(0,-1,false))))
        {
            dc->turn(Input(1,0,false));
            dc->turn(Input(0,0,true));
        }
    }
    this->draw(dc->getLevel());
}

void MainWindow::on_upright_clicked()
{
    remove_exis_char();
    if (dc->turn(Input(0,-1,false)))
    {
        if (!(dc->turn(Input(1,0,false))))
        {
            dc->turn(Input(0,1,false));
            dc->turn(Input(0,0,true));
        }
    }
    else if (dc->turn(Input(1,0,false)))
    {
        if (!(dc->turn(Input(0,-1,false))))
        {
            dc->turn(Input(-1,0,false));
            dc->turn(Input(0,0,true));
        }
    }
    this->draw(dc->getLevel());
}

void MainWindow::on_up_clicked()
{
    remove_exis_char();
    if (!(dc->turn(Input(0,-1,false))))dc->turn(Input(0,0,true));
    this->draw(dc->getLevel());
}

void MainWindow::on_left_clicked()
{
    remove_exis_char();
    if (!(dc->turn(Input(-1,0,false))))dc->turn(Input(0,0,true));
    this->draw(dc->getLevel());
}

void MainWindow::on_right_clicked()
{
    remove_exis_char();
    if (!(dc->turn(Input(1,0,false))))dc->turn(Input(0,0,true));
    this->draw(dc->getLevel());
}

void MainWindow::on_downright_clicked()
{
    remove_exis_char();
    if (dc->turn(Input(0,1,false)))
    {
        if (!(dc->turn(Input(1,0,false))))
        {
            dc->turn(Input(0,-1,false));
            dc->turn(Input(0,0,true));
        }
    }
    else if (dc->turn(Input(1,0,false)))
    {
        if (!(dc->turn(Input(0,1,false))))
        {
            dc->turn(Input(-1,0,false));
            dc->turn(Input(0,0,true));
        }
    }
    this->draw(dc->getLevel());
}

void MainWindow::on_downleft_clicked()
{
    remove_exis_char();
    if (dc->turn(Input(0,1,false)))
    {
        if (!(dc->turn(Input(-1,0,false))))
        {
            dc->turn(Input(0,-1,false));
            dc->turn(Input(0,0,true));
        }
    }
    else if (dc->turn(Input(-1,0,false)))
    {
        if (!(dc->turn(Input(0,1,false))))
        {
            dc->turn(Input(1,0,false));
            dc->turn(Input(0,0,true));
        }
    }
    this->draw(dc->getLevel());
}

void MainWindow::on_down_clicked()
{
    remove_exis_char();
    if ((dc->turn(Input(0,1,false))))dc->turn(Input(0,0,true));
    this->draw(dc->getLevel());
}


void MainWindow::on_turn_clicked()
{
    remove_exis_char();

    Input curr_Direction = level->getTile(cur_pos_row, cur_pos_col)->getCharacter()->getMoveDirection();

    if (curr_Direction.getVertical() == -1)
    {
        level->getTile(cur_pos_row, cur_pos_col)->getCharacter()->setMoveDirection(Input(-1,0,false));
    }

    if (curr_Direction.getVertical() == 1)
    {
        level->getTile(cur_pos_row, cur_pos_col)->getCharacter()->setMoveDirection(Input(1,0,false));
    }

    if (curr_Direction.getHorizontal() == 1)
    {
        level->getTile(cur_pos_row, cur_pos_col)->getCharacter()->setMoveDirection(Input(0,-1,false));
    }

    if (curr_Direction.getHorizontal() == -1)
    {
        level->getTile(cur_pos_row, cur_pos_col)->getCharacter()->setMoveDirection(Input(0,1,false));
    }

    if (curr_Direction.getExit())
    {
        level->getTile(cur_pos_row, cur_pos_col)->getCharacter()->setMoveDirection(Input(1,0,false));
    }
    this->draw(dc->getLevel());
}
