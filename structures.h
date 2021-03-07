#ifndef STRUCTS
#define STRUCTS

#include <iostream>

struct item {
  std::string name;         // item name
  int effect[5];            // effect on player status and ATK (weapon only)
  // [HP, Hydration, Hunger, Mentality, ATK]
  std::string des;  // item description
};

struct attacker {
  std::string name;   // attacker name
  int hp;             // attacker's hp
  int atk;            // reduce of player TEMP HP after each attack
  int lost;           // reduce of player HP if the player lost the fight
  struct item;        // item given after winning
  std::string des;    // attacker description
};

struct event {
  std::string name;     // event name 
  int effect[4];        // effect on player status
  // [HP, Hydration, Hunger, Mentality]
  struct item;          // item given after the event
  char output[10][100]; // lines outputed 
  // max 10 lines with 100 characters
};

#endif 
