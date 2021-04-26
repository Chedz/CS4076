#include <iostream>
#include "mainwindow.h"
#include <QDebug>
#include "item.h"
#include "Room.h"

using namespace std;
#include "ZorkUL.h"
ZorkUL temp;

void setConsole(QString s);

void startGame() {
    //ZorkUL temp;
    temp.play();
    //return 0;
}

ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h;

    a = new Room("[A] Docking Hatch");
        UsableItem x = UsableItem("Hose", 200);
        a->addItem("Hose");
        UsableItem y = UsableItem("Clamps", 100);
        a->addItem("Clamps");
        UsableItem z = UsableItem("Keycard", 5);
        a->addItem("Keycard");

    b = new Room("[B] Kitchen");
    //no items in b (kitchen)

    c = new Room("[C] Main Hub");
        UsableItem t = UsableItem("Override Keycard", 5);
        c->addItem("Override Keycard");

    d = new Room("[D] Filtration Room");
        UsableItem p = UsableItem("Air Filters", 10);
        d->addItem("Air Filters");
        UsableItem q = UsableItem("Canister of Helium", 250);
        d->addItem("Canister of Helium");
        UsableItem r = UsableItem("Keycard", 5);
        d->addItem("Keycard");
        UsableItem i = UsableItem("Canister of Oxygen", 350);
        d->addItem("Canister of Oxygen");

    e = new Room("[E] Lab");
        UsableItem s = UsableItem("Sleeping Quarters Keycard", 10);
        e->addItem("Sleeping Quarters Keycard");

    f = new Room("[F] Maintenance");
        UsableItem j = UsableItem("Screwdriver", 15);
        f->addItem("Screwdriver");
        UsableItem k = UsableItem("Battery", 25);
        f->addItem("Battery");
        UsableItem l = UsableItem("Copper Wire", 10);
        f->addItem("Copper Wire");
    g = new Room("[G] Gym");
    h = new Room("[H] Sleeping Quarters");


    //             (N, E, S, W)
        a->setExits(b, NULL, NULL, NULL);
        b->setExits(c, NULL, a, NULL);
        c->setExits(h, f, b, d);
        d->setExits(NULL, c, NULL, e);
        e->setExits(NULL, d, NULL, NULL);
        f->setExits(NULL, g, NULL, c);
        g->setExits(NULL, NULL, NULL, f);
        h->setExits(NULL, NULL, c, NULL);


            currentRoom = a;

}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
    printWelcome();
   // void updateConsole();

    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.
/**
    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command;
    }
    **/



    //call function for end game (outro/credits)
    cout << endl;
    cout << "end" << endl;
}

void ZorkUL::printWelcome() {
    //int openingText = 1;
   // cin  << userName;
    cout << "Welcome , let the challenge begin" << endl;
    cout << "info for help"<< endl;
    cout << "********************************************" << endl;
    //cout << typePrint(openingText) << endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}


/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
        cout << "invalid input"<< endl;
        return false;
    }

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("map") == 0)
        {
        cout << "                          [Sleeping Quarters]                         " << endl;
        cout << "                                    |                                 " << endl;
        cout << "                                    |                                 " << endl;
        cout << "[Lab] --- [Filtration Room] --- [Main Hub] --- [Maintenance] --- [Gym]" << endl;
        cout << "                                    |                                 " << endl;
        cout << "                                    |                                 " << endl;
        cout << "                                [Kitchen]                             " << endl;
        cout << "                                    |                                 " << endl;
        cout << "                                    |                                 " << endl;
        cout << "                             [Docking Hatch]                          " << endl;
        }

    else if (commandWord.compare("go") == 0)
        goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
        cout << "Try that again , say take and then the item you want to take ..."<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
           cout << "That item cannot be found here, have a look in the other rooms" << endl;
        else
            cout << "item is in room" << endl;

           cout << "index number " << + location << endl;
           cout << endl;
           cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return true; /**signal to quit*/
    }
    return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else {
        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;
    }
}

string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else if(nextRoom->shortDescription() == "[H] Sleeping Quarters"){
        return("You have entered the Final Room! \n"
    "You have made it to the end in one piece somehow, thanks for playing! \n"
    "You can exit via the file action bar in the top left <-");
    }
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}

QString goNorth(){
    return QString::fromStdString(temp.go("north"));
}
QString goSouth(){
  return QString::fromStdString(temp.go("south"));
}
QString goEast(){
   return QString::fromStdString(temp.go("east"));
}
QString goWest(){
   return QString::fromStdString(temp.go("west"));
}
