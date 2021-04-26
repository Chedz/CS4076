#include <QtWidgets>

#include "arrowpad.h"
#include "ZorkUL.h"

QString goNorth();
QString goSouth();
QString goEast();
QString goWest();


ArrowPad::ArrowPad(QWidget *parent)
    : QWidget(parent)
{
//! [0]
    upButton = new QPushButton(tr("&North"));
//! [0] //! [1]
    downButton = new QPushButton(tr("&South"));
//! [1] //! [2]
    leftButton = new QPushButton(tr("&West"));
//! [2] //! [3]
    rightButton = new QPushButton(tr("&East"));
//! [3]

    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->addWidget(upButton, 0, 1);
    connect(upButton, &QPushButton::released, this, &ArrowPad::handleNorth);

    mainLayout->addWidget(leftButton, 1, 0);
    connect(leftButton, &QPushButton::released, this, &ArrowPad::handleWest);

    mainLayout->addWidget(rightButton, 1, 2);
    connect(rightButton, &QPushButton::released, this, &ArrowPad::handleEast);

    mainLayout->addWidget(downButton, 2, 1);
    connect(downButton, &QPushButton::released, this, &ArrowPad::handleSouth);

    setLayout(mainLayout);
}


void ArrowPad::handleNorth()
{
    QMessageBox::information(this, "Console", goNorth());
}
void ArrowPad::handleSouth()
{
    QMessageBox::information(this, "Console", goSouth());
}
void ArrowPad::handleEast()
{
    QMessageBox::information(this, "Console", goEast());
}
void ArrowPad::handleWest()
{
    QMessageBox::information(this, "Console", goWest());
}

