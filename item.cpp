#include "item.h"

Item::Item (string inDescription, int inWeightGrams) {
	description = inDescription;
	setWeight(inWeightGrams);

}

Item::Item(string inDescription) {
	description = inDescription;
}

void Item::setWeight(int inWeightGrams)
{
    if (inWeightGrams > 999 || inWeightGrams < 0)
       cout << "weight invalid, must be 0<weight<999" ;
    else
	   weightGrams = inWeightGrams;
}


string Item::getShortDescription()
{
	return description;
}

string Item::getLongDescription()
{
	return " item(s), " + description + ".\n";
}




