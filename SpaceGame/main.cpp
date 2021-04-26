#include "ZorkUL.h"
#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPushButton>
#include<QHBoxLayout>

//ZorkUL temp;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();


    //int p = startGame(); //call to start main gameplay
   // return 1;
    return a.exec();
}

