#ifndef STARTSCREEN_H
#define STARTSCREEN_H

<<<<<<< HEAD
#include <QMainWindow>

namespace Ui {
class StartScreen;
}

class StartScreen : public QMainWindow
{
    Q_OBJECT

public:
    StartScreen(QWidget *parent = nullptr);
    ~StartScreen();

=======
#include<QDialog>



QT_BEGIN_NAMESPACE
namespace Ui {
class StartScreen;
}
QT_END_NAMESPACE
class GraphicalUI;
class StartScreen : public QDialog
{
    Q_OBJECT
public:
    StartScreen(GraphicalUI* gui,QWidget *parent = nullptr);
    ~StartScreen();
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
private slots:
    void buttonclick();

protected:
<<<<<<< HEAD
    virtual void resizeEvent(QResizeEvent* event) override;

private:
    Ui::StartScreen *ui;
=======
   virtual void resizeEvent(QResizeEvent *event) override;

private:
    Ui::StartScreen *ui;
    GraphicalUI* gui_m;

>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
};

#endif // STARTSCREEN_H
