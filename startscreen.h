#ifndef STARTSCREEN_H
#define STARTSCREEN_H

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
private slots:
    void buttonclick();

protected:
   virtual void resizeEvent(QResizeEvent *event) override;

private:
    Ui::StartScreen *ui;
    GraphicalUI* gui_m;

};

#endif // STARTSCREEN_H
