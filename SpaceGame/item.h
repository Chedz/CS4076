#ifndef ITEMH
#define ITEMH

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
protected:
    string description;
    string longDescription;
    int weightGrams;
    float value;
    bool weaponCheck;

public:
    Item (string description, int inWeight);
    Item (string description);
    string getShortDescription();
    string getLongDescription();
    int getWeight();
    void setWeight(int weightGrams);
    float getValue();
    void setValue(float value);
    int getWeaponCheck();
    void setWeaponCheck(int weaponCheck);
    virtual void useItem(int id) = 0;     //virtual function, each item use will be different depending on the item
};

//Derived classes
class UsableItem: public Item {
   private:
    int id; //use friendship to access

   public:
        UsableItem( string description, int inWeight);
        UsableItem (int id, string description);
        void useItem(int id);
        string getShortDescription();
};

class NonUsableItem: public Item {
   public:
      //void useItem(int id); //nonusable item by it's name, cannot be used
};

#endif
