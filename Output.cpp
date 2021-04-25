#include "Output.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

// set up for all the blocks of text we will need to out put for the game story line
void Output::typePrint(int textIndex){
  String text = " ";
  //1 = game intro 
  //2= opening scene
  //3= Player directions
  //4= viki comment 1
  //5= viki comment 2
  //6= viki comment 3
  //7= noise 1
  //8= noise 2
  //9= Main Hub directions 
  //10= final scene 
  switch (textIndex) {
  case 1:  
    text = "Navigate through several puzzles to further explore ISS and reach survivors. Find hints and hear noises along the way of strange things happening";
    break;
  case 2:
    text = "";
    break;
  case 3:
    text = "";
    break;
  case 4:
    text = "";
    break;
  case 5:
    text = "";
    break;
  case 6:
    text = "";
    break;
  case 7:
    text = "";
    break;
  case 8:
    text = "";
    break;
  case 9:
    text = "";
    break;
  case 10:
    text = "";
    break;
  defualt :
      text = "lads had no idea what they were doing and put nothing in ";
    
      
}
  // prints the text letter by letter 
  for( int i = 0; i < text.length(); i++){
  cout << text[i];
  cout.flush();
  usleep(10000);
  }
   

}
