#ifndef MAINWINDOW_H
#define MAINWINDOW_H
<<<<<<< HEAD
#include "dungeoncrawler.h"
#include "graphicalui.h"
#include "abstractcontroller.h"
#include <QWidget>
#include <QLabel>
#include <vector>
#include <QMainWindow>
=======

#include <QMainWindow>
#include "dungeoncrawler.h"
#include <QWidget>
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

<<<<<<< HEAD
class DungeonCrawler;
class GraphicalUI;

=======
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(DungeonCrawler* dc, QWidget *parent = nullptr);
<<<<<<< HEAD
    MainWindow(int row, int col, std::string level, QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent* event) override;

    void resizeEvent(QResizeEvent *event) override;
    void draw();
    void remove_exis_char();

    Input_gui getLastClicked() const;

    DungeonCrawler *getDc() const;

    void check_Won();
private slots:

    void on_upleft_clicked();

    void on_upright_clicked();

    void on_up_clicked();

    void on_left_clicked();

    void on_right_clicked();

    void on_downright_clicked();

    void on_down_clicked();

    void on_downleft_clicked();

    void on_turn_clicked();

private:
    Ui::MainWindow *ui_m;
    Level* current_level;
    DungeonCrawler* dc;

    int cur_pos_row{};
    int cur_pos_col{};
    std::vector<std::pair<int,int>> characters;
    Input_gui LastClicked;

    // QWidget interface
};
#endif // MAINWINDOW_H
=======
    ~MainWindow();

    void resizeEvent(QResizeEvent* event) override;
    void draw(Level* level);

    void remove_exis_char();

private slots:
    void on_upleft_clicked();
    void on_upright_clicked();
    void on_up_clicked();
    void on_left_clicked();
    void on_right_clicked();
    void on_downright_clicked();
    void on_down_clicked();
    void on_downleft_clicked();
    void on_turn_clicked();

private:
    Ui::MainWindow* ui_m;
    Level* level;
    DungeonCrawler* dc;
    int cur_pos_row;
    int cur_pos_col;
};

#endif // MAINWINDOW_H


>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
