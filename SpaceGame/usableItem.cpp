#include "item.h"

UsableItem::UsableItem (int id, string inDescription) : Item(inDescription) //calls Item constructor
{
    this->id = id;
    description = inDescription;
}

UsableItem::UsableItem ( string inDescription, int inWeightGrams) : Item(inDescription, inWeightGrams) { //calls Item constructor
    //this->id = id;
    description = inDescription;
    setWeight(inWeightGrams);
    //value = inValue;
}

void UsableItem::useItem(int id)
{
    switch(id){

    case '1' : cout << "ID is 1" << endl;   //functionality based on id
    case '2' : cout << "ID is 2" << endl;



    default: cout << "Inavlid ID" << endl;
    }
}
string UsableItem::getShortDescription(){

    return this->description;
}
