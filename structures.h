#ifndef STRUCTS
#define STRUCTS

#include <iostream>

struct item {
  // item name
  std::string name;
  // effect on player status and ATK (weapon only)
  //  [HP, Hydration, Hunger, Mentality, ATK]         
  int effect[5];            
  // item description
  std::string des;  
};

struct attacker {
  // attacker name
  std::string name;
  // attacker's hp   
  int hp;           
  // reduce of player TEMP HP after each attack  
  int atk;            
  // reduce of player HP if the player lost the fight
  int lost;           
  // reward after winning
  //  [catagory, item_index]
  //  catagory: 0 = no reward; 1 = food; 2 = weapon
  int item[2];        
  // attacker description
  std::string des;    
};

struct event {
  std::string name;     // event name 
  int effect[4];        // effect on player status
  // [HP, Hydration, Hunger, Mentality]
  std::string item;          // item given after the event
  char output[10][100]; // lines outputed 
  // max 10 lines with 100 characters
};

#endif 
