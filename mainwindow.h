#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QLabel;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
QT_END_NAMESPACE
class ArrowPad;

//! [0]
class MainWindow : public QMainWindow
//! [0] //! [1]
{
    Q_OBJECT
//! [1]

public:
    MainWindow();
    QString updateConsole();

private:
    ArrowPad *arrowPad;
    QMenu *fileMenu;
    QAction *exitAct;
    QLabel *label;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
};

#endif
