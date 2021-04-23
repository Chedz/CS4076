#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

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
    explicit MainWindow(QWidget *parent = nullptr);
    QString consoleVal;
    QString updateConsole();
    void setConsole(QString);
    QString getConsole();

private slots:
    void handleButton();

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
