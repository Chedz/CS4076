
#ifndef OUTPUT_H_
#define OUTPUT_H_


#include <string>
#include <vector>
#include "ZorkUL.h"

using namespace std;
using std::vector;

class Output {

private:
	
	vector<string> textBlocks;
    
  public :
  
  void typePrint(string text);
};

#endif
