#include <iostream>

using namespace std;
#include "ZorkUL.h"

int main(int argc, char*argv[]) {
	ZorkUL temp;
	temp.play();
	return 0;
}

ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h; 

	a = new Room("Docking Hatch");
       a->addItem(new Item("Hose", 200));
       a->addItem(new Item("Sarah's Space Suit",500));
       a->addItem(new Item("Jack's Space Suit", 500));
       a->addItem(new Item("Adam's Space Suit", 500));
       a->addItem(new Item("Clamps", 100));
       a->addItem(new Item("Keycard", 5));
	
        b = new Room("Kitchen");
	// no items in kitchen 
	c = new Room("Main Hub");
	c->addItem(new Item("Override Keycard", 5));
	
	d = new Room("Filtration Room");
	d->addItem(new Item("Canister of Oxygen", 250));
	d->addItem(new Item("Canister of Water", 300));
	d->addItem(new Item("Canister of Carbon Dioxide", 250));
	d->addItem(new Item("Canister of Helium", 250));
	d->addItem(new Item("Air filters", 10));
	
	e = new Room("Lab");
        e->addItem(new Item(" Sleeping Quarters Keycard", 5));
	
	f = new Room("Maintenance");
	f->addItem(new Item("Copper Wire", 10));
	f->addItem(new Item("Nail", 5));
	f->addItem(new Item("Hammer", 15));
	f->addItem(new Item("Battery", 25));
	f->addItem(new Item("Screwdriver", 15));
	f->addItem(new Item("Cloth", 5));
	f->addItem(new Item("Tool Chest", 250));
	
	
	g = new Room("Gym");
	g->addItem(new Item(" Sleeping Quarters Keycard", 5));
	h = new Room("Sleeping Quarters");
        // no items in sleeping quarters 
	

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

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

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
	cout << endl;
	cout << "end" << endl;
}

void ZorkUL::printWelcome() {
	cout << "start"<< endl;
	cout << "info for help"<< endl;
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

	else if (commandWord.compare("go") == 0){
		goRoom(command);
	}
	
    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "Try that again , say take and then the item you want to take ..."<< endl;
        }
	    
        else if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "That item cannot be found here, have a look in the other rooms" << endl;
        else
            cout << "You took " << command.getSecondWord() << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {


    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "You put " + command.getSecondWord() + " down" << endl;
            itemsInRoom.push_Back;
        }
    }
    }
	

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
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
