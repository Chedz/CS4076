#ifndef ARROWPAD_H
#define ARROWPAD_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE

//! [0]
class ArrowPad : public QWidget
//! [0] //! [1]
{
//! [1] //! [2]
    Q_OBJECT
//! [2]

public:
    ArrowPad(QWidget *parent = 0);

private slots:
    void handleNorth();
    void handleSouth();
    void handleEast();
    void handleWest();

private:
    QPushButton *upButton;
    QPushButton *downButton;
    QPushButton *leftButton;
    QPushButton *rightButton;
};

#endif
