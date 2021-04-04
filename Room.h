#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
//#include <queue>
using namespace std;
using std::vector;

class Room {

private:
	string description;
	map<string, Room*> exits;
	string exitString();
    vector<string> itemsInRoom;
    vector <UsableItem> usableItemsInRoom;
    vector <NonUsableItem> nonUsableItemsInRoom;


public:
    int numberOfItems();
	Room(string description);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	string longDescription();
	Room* nextRoom(string direction);
   // void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);

    template <typename T>       //add item to room regardless of whether usable or non-usable
     void addItem(T inItem);
};

#endif
