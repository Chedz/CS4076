#include "ZorkUL.h"
#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPushButton>
#include<QHBoxLayout>
/**
int startGame();
int main(int argc, char *argv[])
{
    //std::thread t(gui, argc, argv);
   // t.join();
    //int p = startGame(); //call to start main gameplay
   // return 1;

    QApplication mApp(argc, argv);
    //create scene
    QGraphicsScene * scene = new QGraphicsScene();

    //create item to put into scene
   // QGraphicsRectItem * rect = new QGraphicsRectItem();
    //rect->setRect(0,0,100,100);

    //add item to scene
    //scene->addItem(rect);

    //add a view
    QGraphicsView * view = new QGraphicsView();     //use different scene for start menu etc. swap scenes within view
    view->setScene(scene);
    view->show();


        //just for testing and holding the program so it doesn't end
        for(int i = 0; i < 100000000; ++i)
        {
            mApp.processEvents();
        }
        return 0;
}

**/
//int p = startGame();
int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    //create scene
    //QGraphicsScene * scene = new QGraphicsScene();

    //create item to put into scene
    //QGraphicsRectItem * rect = new QGraphicsRectItem();
    //rect->setRect(0,0,100,100);

    //add item to scene
    //scene->addItem(rect);

    //add a view
    //QGraphicsView * view = new QGraphicsView();     //use different scene for start menu etc. swap scenes within view
    //view->setScene(scene);
    //view->show();

    void startGame();
/**
    QWidget *window = new QWidget;
    window->setWindowTitle("My App");
    QPushButton *button1 = new QPushButton("one");
    QPushButton *button2 = new QPushButton("two");
    QPushButton *button3 = new QPushButton("three");
    //layout->addWidget(arrowPad, 0, 1);
    //layout->addWidget(arrowPad, 1, 2);
    //layout->addWidget(label, 1, 1);
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(button1);
    hlayout->addWidget(button2);
    hlayout->addWidget(button3);

    //arrowPad->show();
    //label->show();
    //button1->setVisible(true);
    //button2->setVisible(true);
    //setLayout(hlayout);
    window->show();

    **/
    MainWindow mainWindow;
    mainWindow.show();


    //int p = startGame(); //call to start main gameplay
   // return 1;
    return a.exec();
}

