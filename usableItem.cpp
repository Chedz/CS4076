#include "item.h"

UsableItem::UsableItem (int id, string inDescription) : Item(inDescription) //calls Item constructor
{
    this->id = id;
    description = inDescription;
}

UsableItem::UsableItem (int id, string inDescription, int inWeightGrams, float inValue) : Item(inDescription, inWeightGrams, inValue) { //calls Item constructor
    this->id = id;
    description = inDescription;
    setWeight(inWeightGrams);
    value = inValue;
}

void UsableItem::useItem(int id)
{
    switch(id){

    case '1' : cout << "ID is 1" << endl;   //will add functionality when puzzle implementation is done
    case '2' : cout << "ID is 2" << endl;



    default: cout << "Inavlid ID" << endl;
    }
}
