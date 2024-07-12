#include "mainwindow.h"
#include "ui_mainwindow.h"
<<<<<<< HEAD
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <QKeyEvent>
#include <QStatusBar>
#include <QMessageBox>

MainWindow::MainWindow(DungeonCrawler* dc, QWidget *parent)
    : QMainWindow(parent)
    , ui_m(new Ui::MainWindow)
    , dc(dc), cur_pos_row(0), cur_pos_col(0)
{
    ui_m->setupUi(this);

    this->setStyleSheet("background-color: rgb(0, 0, 0); border-image: url(:/textures/bloody_frame.png);");

    ui_m->verticalLayout->setContentsMargins(10, 100, 10, 10);

    QGridLayout* l = ui_m->tiles;

 current_level = dc->getCurrentLevel();

    for(int row = 0; row < current_level->getRows(); row++)
    {
        for(int col = 0; col < current_level->getCols(); col++)
        {
            QLabel* widget = new QLabel(nullptr);

            widget->setScaledContents(true);

            l->addWidget(widget, row, col, Qt::AlignCenter);
        }
    }
    l->setAlignment(Qt::AlignHCenter);
}

MainWindow::MainWindow(int row, int col, std::string level, QWidget *parent)
    : QMainWindow(parent)
    , ui_m(new Ui::MainWindow)
    , dc(new DungeonCrawler(row, col, level)), cur_pos_row(0), cur_pos_col(0)
=======
#include "character.h"
#include "level.h"
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <iostream>
#include <QObject>
#include <QGridLayout>

MainWindow::MainWindow(DungeonCrawler* dc, QWidget* parent)
    : QMainWindow{parent},
    ui_m(new Ui::MainWindow),
    dc(dc), cur_pos_row(0), cur_pos_col(0)
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
{
    ui_m->setupUi(this);

    this->setStyleSheet("background-color: rgb(0, 0, 0); border-image: url(:/textures/bloody_frame.png);");

    ui_m->verticalLayout->setContentsMargins(10, 100, 10, 10);

    QGridLayout* l = ui_m->tiles;

<<<<<<< HEAD
       current_level = dc->getCurrentLevel();

    for(int row = 0; row < current_level->getRows(); row++)
    {
        for(int col = 0; col < current_level->getCols(); col++)
        {
=======
    level = dc->getLevel();

    for (int row = 0; row < level->getHeight(); row++)
    {
        for (int col = 0; col < level->getWidth(); col++)
        {

>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
            QLabel* widget = new QLabel(nullptr);

            widget->setScaledContents(true);

<<<<<<< HEAD
=======
            std::string texture = level->getTile(row, col)->getTexture();
            char* tex_c= texture.data();
            if (*tex_c == 'C')
            {
                widget->setPixmap(QPixmap(":/textures/floor/floor1.png"));
            }
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
            l->addWidget(widget, row, col, Qt::AlignCenter);
        }
    }
    l->setAlignment(Qt::AlignHCenter);
}
<<<<<<< HEAD
void MainWindow::keyPressEvent(QKeyEvent* event)
{
  /*  if(event->modifiers() & !Qt::KeypadModifier)
    {
        return;
    }
    if(event->key()==Qt::Key_L)
    {
        remove_exis_char();
        dc->loadGame();
        LastClicked = down;
        this->draw();
        check_Won();
        return;
    }
    if(event->key()==Qt::Key_S)
    {
        remove_exis_char();
        LastClicked = stand;
        dc->turn();
        this->draw();
        check_Won();
        return;
    }*/
    if (event->key() == Qt::Key_S) {
        dc->saveGame();
        std::cout << "Game saved!" << std::endl;
    } else if (event->key() == Qt::Key_L) {
        dc->loadGame();
        std::cout << "Game loaded!" << std::endl;
        this->draw();  // Redraw the game state
    }
}

MainWindow::~MainWindow()
{
    delete dc;
    dc = nullptr;
    //delete current_current_level;
current_level = nullptr;
    delete ui_m;
    ui_m = nullptr;
}



void MainWindow::on_upleft_clicked()
{
    remove_exis_char();
    LastClicked = upleft;
    dc->turn();
    this->draw();
    check_Won();
}

void MainWindow::on_upright_clicked()
{
    remove_exis_char();
    LastClicked = upright;
    dc->turn();
    this->draw();
    check_Won();
}

void MainWindow::on_up_clicked()
{
    remove_exis_char();
    LastClicked = up;
    dc->turn();
    this->draw();
    check_Won();
}

void MainWindow::on_left_clicked()
{
    remove_exis_char();
    LastClicked = left;
    dc->turn();
    this->draw();
    check_Won();
}

void MainWindow::on_right_clicked()
{
    remove_exis_char();
    LastClicked = right;
    dc->turn();
    this->draw();
    check_Won();
}

void MainWindow::on_downright_clicked()
{
    remove_exis_char();
    LastClicked = downright;
    dc->turn();
    this->draw();
    check_Won();
}

void MainWindow::on_downleft_clicked()
{
    remove_exis_char();
    LastClicked = downleft;
    dc->turn();
    this->draw();
    check_Won();
}

void MainWindow::on_down_clicked()
{
    remove_exis_char();
    LastClicked = down;
    dc->turn();
    this->draw();
    check_Won();
=======

MainWindow::~MainWindow()
{
    delete ui_m;
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);

<<<<<<< HEAD
   current_level = dc->getCurrentLevel();

    const int w = ui_m->centralwidget->width() / current_level->getRows();
    const int h = ui_m->centralwidget->height() /current_level->getCols();

    const int opt = std::min(w, h);

    ui_m->verticalLayout->setContentsMargins(opt, opt*1.5, opt, opt*0.5);

    for(int row = 0; row < current_level->getRows(); row++)
    {
        for(int col = 0; col < current_level->getCols(); col++)
        {
            QWidget* widget = ui_m->tiles->itemAtPosition(row, col)->widget();
            widget->setFixedSize(opt*0.80, opt*0.80);
        }
    }
}
void MainWindow::draw()
{
        current_level = dc->getCurrentLevel();
    for(int row = 0; row < current_level->getRows(); row++)
    {
        for(int col = 0; col < current_level->getCols(); col++)
=======
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

void MainWindow::draw(Level* level)
{
    for (int row = 0; row < level->getHeight(); row++)
    {
        for (int col = 0; col < level->getWidth(); col++)
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
        {
            QWidget* widget1 = ui_m->tiles->itemAtPosition(row, col)->widget();

            QLabel* widget = qobject_cast<QLabel*>(widget1);

<<<<<<< HEAD
            std::string texture = current_level->getTile(row, col)->getTexture();

            char* tex_c = texture.data();

            widget->setPixmap(*current_level->getTile(row, col)->getTex_ui());
            widget->setStyleSheet("background: transparent;");
            if(current_level->getTile(row, col)->hasCharacter())
            {
                QLabel* charac = new QLabel(nullptr);
                charac->setStyleSheet("background: transparent; border-image: none;");

                if(current_level->getTile(row, col)->getCharacter()->isHuman())
                {
                    cur_pos_row = row;
                    cur_pos_col = col;

                    //maybe for future improvement get char location and move direction and only update necessary stuff like door etc -> fun project maybe
                    Input_gui moved_dir = current_level->getTile(row, col)->getCharacter()->getMoveDirection();

                    switch(moved_dir)
                    {
                        case up:
                        {
                            charac->setPixmap(QPixmap(":/textures/char/back/char_back_1.png"));
                            break;
                        }
                        case down:
                        {
                            charac->setPixmap(QPixmap(":/textures/char/front/char_front_1.png"));
                            break;
                        }
                        case right:
                        {
                            charac->setPixmap(QPixmap(":/textures/char/right/char_right_1.png"));
                            break;
                        }
                        case left:
                        {
                            charac->setPixmap(QPixmap(":/textures/char/left/char_left_1.png"));
                            break;
                        }
                        case stand:
                        {
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                }
                else
                {
                    charac->setStyleSheet("background: transparent; border-image: none;");

                    Input_gui moved_dir = current_level->getTile(row, col)->getCharacter()->getMoveDirection();
                    if(moved_dir==right){
                        charac->setPixmap(QPixmap(":/textures/zombie/zombie_right.png"));
                    }
                    else if(moved_dir==left){
                        charac->setPixmap(QPixmap(":/textures/zombie/zombie_left.png"));
                    }
                    else{
                        charac->setPixmap(QPixmap(":/textures/zombie/zombie_right.png"));
                    }
                }

                charac->setFixedSize(75,75);
=======
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
                widget->setPixmap(QPixmap(":/textures/portal/portal1.png"));
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
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
                charac->setScaledContents(true);
                charac->setParent(nullptr);
                ui_m->tiles->addWidget(charac, row, col, Qt::AlignCenter);

<<<<<<< HEAD
                characters.push_back(std::make_pair(row, col));

                if(*tex_c=='_')
=======
                if (*tex_c=='_')
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
                {
                    charac->lower();
                }
            }
        }
    }

<<<<<<< HEAD
    const int w = ui_m->centralwidget->width() / current_level->getRows();
    const int h = ui_m->centralwidget->height() /current_level->getCols();

    const int opt = std::min(w, h);

    ui_m->verticalLayout->setContentsMargins(opt, opt*1.5, opt, opt*0.5);

    for(int row = 0; row < current_level->getRows(); row++)
    {
        for(int col = 0; col < current_level->getCols(); col++)
        {
            QWidget* widget = ui_m->tiles->itemAtPosition(row, col)->widget();
            widget->setFixedSize(opt*0.80,opt*0.80);
        }
    }

    QString HP;
    QString strength;
    QString stamina;

    for(auto chara : dc->getCurrentLevel()->getCharacters()){
        if(chara ->isHuman()){
            HP = QString::number(chara->getHitpoints());
            strength = QString::number(chara->getStrength());
            stamina = QString::number(chara->getStamina());
        }
    }
      ui_m->statusBar->showMessage(QString("HP: %1  Strength: %2  Stamina: %3").arg(HP, strength, stamina));
    ui_m->statusBar->setStyleSheet("background-color: rgb(255, 255, 255); border-image: none;");


}

void MainWindow::check_Won()
{
    if(dc->getLootchest_found()){
        QMessageBox msgBox;
        msgBox.setText("You have reached the lootchest,  YOU WON !!");
        msgBox.exec();
        QApplication::quit();
    }
    if(!(dc->isHuman_alive())){
        QMessageBox msgBox;
        msgBox.setText("You Died,  Better Luck Next time !!");
        msgBox.exec();
        QApplication::quit();
    }
}

void MainWindow::remove_exis_char()
{
    for(auto pos:characters)
    {
        QWidget* widget = ui_m->tiles->itemAtPosition(pos.first,pos.second)->widget();
        ui_m->tiles->removeWidget(widget);
        widget->setParent(nullptr);
        delete widget;
    }
    characters.clear();
}

Input_gui MainWindow::getLastClicked() const
{
    return LastClicked;
}

=======
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


>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
void MainWindow::on_turn_clicked()
{
    remove_exis_char();

<<<<<<< HEAD
    Input_gui curr_Direction = dc->getCurrentLevel()->getTile(cur_pos_row, cur_pos_col)->getCharacter()->getMoveDirection();

    switch(curr_Direction)
    {
    case up:
        dc->getCurrentLevel()->getTile(cur_pos_row, cur_pos_col)->getCharacter()->setMoveDirection(left);
        break;
    case down:
        dc->getCurrentLevel()->getTile(cur_pos_row, cur_pos_col)->getCharacter()->setMoveDirection(right);
        break;
    case right:
        dc->getCurrentLevel()->getTile(cur_pos_row, cur_pos_col)->getCharacter()->setMoveDirection(up);
        break;
    case left:
        dc->getCurrentLevel()->getTile(cur_pos_row, cur_pos_col)->getCharacter()->setMoveDirection(down);
        break;
    case terminate:
        dc->getCurrentLevel()->getTile(cur_pos_row, cur_pos_col)->getCharacter()->setMoveDirection(right);
        break;
    default:
        break;
    }
    this->draw();
}

DungeonCrawler *MainWindow::getDc() const
{
    return dc;
}
=======
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



>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
