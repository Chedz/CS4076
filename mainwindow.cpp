#include <QtWidgets>
#include <QLabel>
#include <QPushButton>
#include <QtGui>
#include <QtCore>
#include <QPixmap>
#include <QDebug>
#include <QApplication>


#include "arrowpad.h"
#include "mainwindow.h"
#include "ZorkUL.h"

QString consoleVal = "";


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    QGridLayout *layout = new QGridLayout;

    ArrowPad *arrowPad = new ArrowPad;


    QTextBrowser *console = new QTextBrowser();
    console->setText(consoleVal);

    QTextBrowser *currentRoom = new QTextBrowser();
    currentRoom->setText("Current Room");

    QTextBrowser *inventory = new QTextBrowser();
    inventory->setText("Inventory");

    QPushButton *button1 = new QPushButton("info", this);
    QPushButton *button2 = new QPushButton("put");
    QPushButton *button3 = new QPushButton("take");


    QLabel *picLabel = new QLabel();
    QPixmap pic (":/GameWindow/Rooms/Hatch.png");
    QPixmap picScaled = pic.scaled(QSize(1200, 720));
    picLabel->setPixmap(picScaled);

    QLabel *mapLabel = new QLabel();
    QPixmap map (":/GameWindow/Map/ISS_Map_Frame.PNG");
    QPixmap mapScaled = map.scaled(QSize(500, 350));
    mapLabel->setPixmap(mapScaled);


    layout->addWidget(picLabel,0,0,6,5);
    layout->addWidget(button1,5,0,1,1);
    layout->addWidget(button2,5,2,1,1);
    layout->addWidget(button3,5,4,1,1);
    layout->addWidget(console,6,0,2,9);
    layout->addWidget(currentRoom,0,7,1,1);
    layout->addWidget(mapLabel,1,7,1,2);
    layout->addWidget(inventory,2,7,1,2);
    layout->addWidget(arrowPad,3,7,2,2);

    QWidget *window = new QWidget();
    window->setLayout(layout);
    setCentralWidget(window);


    connect(button1, &QPushButton::released, this, &MainWindow::handleButton);

    //exit code
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAct);

}

void MainWindow::handleButton(){

    //QMessageBox::information(this, "Info", "Tip: ");
   //add in functionality for button here
}

//Setter
void setConsole(QString s) {

      //consoleVal.append(s); //append instead of reset to keep track of previouse output
    //void QTextEdit::append( const QString & text );
   // console->append(s);
    consoleVal.append(s);
   // console.repaint();
   // console->append(s);
    //console->setText();
    //qApp->processEvents();
   // console->reload();
}

    // Getter
QString getConsole() {
      return consoleVal;
    }
