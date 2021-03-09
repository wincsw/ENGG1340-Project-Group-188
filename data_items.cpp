# include <iostream>
# include <string>
# include <cstdlib>
# include "structures.h"

using namespace std;

// effect --> [HP, Hydration, Hunger, Mentailty, ATK]

// Water items
struct item water(int x) 
{
  const int num_of_item = 5;
  struct item water_items[5];
  struct item choosen;

  // Clean Water
  water_items[0].name = "Clean Water";
  water_items[0].effect[0] = 0;
  water_items[0].effect[1] = 10;
  water_items[0].effect[2] = 0;
  water_items[0].effect[3] = 0;
  water_items[0].effect[4] = 0;
  water_items[0].des = "Water that is save to drink, nothing special";

  // Pee
  water_items[1].name = "Pee";
  water_items[1].effect[0] = 0;
  water_items[1].effect[1] = 5;
  water_items[1].effect[2] = 0;
  water_items[1].effect[3] = 0;
  water_items[0].effect[4] = 0;
  water_items[1].des = "Seriously? Drinking pee? Ew!";

  for (int i = 0; i < num_of_item; i++) {
    if (i == x) {
      choosen = water_items[i];
    }
  }

  return choosen;
}



