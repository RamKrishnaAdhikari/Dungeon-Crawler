#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dungeoncrawler.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(DungeonCrawler* dc, QWidget *parent = nullptr);
    ~MainWindow();

    void resizeEvent(QResizeEvent* event) override;
    void draw(Level* level);

    void remove_exis_char();
    void initializeRandom();


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
    std::vector<std::vector<int>> tileTextures;
};

#endif // MAINWINDOW_H
