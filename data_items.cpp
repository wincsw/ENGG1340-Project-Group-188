// data_item.cpp
// all data of the resource item in five catagory 
// anc call the data

#include <iostream>
#include <string>
#include "structures.h"
#include "data_items.h"

using namespace std;

// number of items in each catagory
const int water_num = 5;    // Water
const int food_num = 5;     // Food
const int medicine_num = 5; // Medicine
const int weapon_num = 4;   // Weapon
const int mystery_num = 6;  // Mystery

// Function: choose Water item (default choose by index)
// Input: int x: item index 
// Output: Item: choosen item
// NOTE: 0: Clean Water; 1: Soda/Pepsi; 2: Pee; 3: Cocount; 4: Dirty Water
Item water(int x) {
  Item water_items[water_num];

  // Clean Water
  // initial, can't be drawn
  water_items[0].name = "Clean Water";
  water_items[0].effect[0] = 0;
  water_items[0].effect[1] = 10;
  water_items[0].effect[2] = 0;
  water_items[0].effect[3] = 0;
  water_items[0].effect[4] = 0;
  water_items[0].des = "Water that is save to drink, nothing special";
 
  // Soda
  water_items[1].name = "Soda";
  water_items[1].effect[0] = 0;
  water_items[1].effect[1] = 5;
  water_items[1].effect[2] = 0;
  water_items[1].effect[3] = 5;
  water_items[1].effect[4] = 0;
  water_items[1].des = "CocaCola? Wait, it is Pepsi!";

  // Pee
  water_items[2].name = "Pee";
  water_items[2].effect[0] = 0;
  water_items[2].effect[1] = 5;
  water_items[2].effect[2] = 0;
  water_items[2].effect[3] = -5;
  water_items[2].effect[4] = 0;
  water_items[2].des = "Seriously? Pee? Ew!";

  // Coconut
  water_items[3].name = "Coconut";
  water_items[3].effect[0] = 0;
  water_items[3].effect[1] = 10;
  water_items[3].effect[2] = 0;
  water_items[3].effect[3] = 0;
  water_items[3].effect[4] = 0;
  water_items[3].des = "Fresh cocunut water";

  // Dirty Water
  water_items[4].name = "Dirty Water";
  water_items[4].effect[0] = -5;
  water_items[4].effect[1] = 5;
  water_items[4].effect[2] = 0;
  water_items[4].effect[3] = 0;
  water_items[4].effect[4] = 0;
  water_items[4].des = "This water doesn't seem to be drinkable";

  return water_items[x];
}

// Function: choose Food item (default choose by index)
// Input: int x: item index 
// Output: Item: choosen item
// NOTE: 0: Energy Bar; 1: Meat; 2: Wild Berry; 3: Worm; 4: Unknown Mushroom
Item food(int x) {
  Item food_items[food_num];

  // Energy Bar
  // initial, can't be drawn
  food_items[0].name = "Energy Bar";
  food_items[0].effect[0] = 0;
  food_items[0].effect[1] = 0;
  food_items[0].effect[2] = 10;
  food_items[0].effect[3] = 0;
  food_items[0].effect[4] = 0;
  food_items[0].des = "Well, this is the only thing on your body that is still \
  good to eat";
 
  // Meat
  food_items[1].name = "Meat";
  food_items[1].effect[0] = 0;
  food_items[1].effect[1] = 0;
  food_items[1].effect[2] = 10;
  food_items[1].effect[3] = 0;
  food_items[1].effect[4] = 0;
  food_items[1].des = "Meat from some animal that you killed";

  // Wild Berry
  food_items[2].name = "Wild Berry";
  food_items[2].effect[0] = 0;
  food_items[2].effect[1] = 0;
  food_items[2].effect[2] = 5;
  food_items[2].effect[3] = 0;
  food_items[2].effect[4] = 0;
  food_items[2].des = "Whooo! Berries!";

  // Worm
  food_items[3].name = "Worm";
  food_items[3].effect[0] = 0;
  food_items[3].effect[1] = 0;
  food_items[3].effect[2] = 10;
  food_items[3].effect[3] = -10;
  food_items[3].effect[4] = 0;
  food_items[3].des = "Remember, worms are full of protein, \
  even if they look disgusting";

  // Unknown Mushroom
  food_items[4].name = "Unknown Mushroom";
  food_items[4].effect[0] = -5;
  food_items[4].effect[1] = 0;
  food_items[4].effect[2] = 5;
  food_items[4].effect[3] = 0;
  food_items[4].effect[4] = 0;
  food_items[4].des = "This mushroom seems to be a bit too colorful";

  return food_items[x];
}

// Function: choose Medicine item (default choose by index)
// Input: int x: item index 
// Output: Item: choosen item
// NOTE: 0: Herb; 1: Pill; 2: Bandage; 3: First Aid Kit; 4: Sedative
Item medicine(int x) {
  Item medicine_items[medicine_num];

  // Herb
  medicine_items[0].name = "Herb";
  medicine_items[0].effect[0] = 5;
  medicine_items[0].effect[1] = 0;
  medicine_items[0].effect[2] = 0;
  medicine_items[0].effect[3] = 0;
  medicine_items[0].effect[4] = 0;
  medicine_items[0].des = "Herbs are often used in tradition Chinese medication";
 
  // Pill
  medicine_items[1].name = "Pill";
  medicine_items[1].effect[0] = 10;
  medicine_items[1].effect[1] = 0;
  medicine_items[1].effect[2] = 0;
  medicine_items[1].effect[3] = 0;
  medicine_items[1].effect[4] = 0;
  medicine_items[1].des = "If one pill can't help, then have two pills";

  // Bandage
  medicine_items[2].name = "Bandage";
  medicine_items[2].effect[0] = 15;
  medicine_items[2].effect[1] = 0;
  medicine_items[2].effect[2] = 0;
  medicine_items[2].effect[3] = 0;
  medicine_items[2].effect[4] = 0;
  medicine_items[2].des = "Bandage can reduce blood lost";

  // First Aid Kit
  medicine_items[3].name = "First Aid Kit";
  medicine_items[3].effect[0] = 50;
  medicine_items[3].effect[1] = 0;
  medicine_items[3].effect[2] = 0;
  medicine_items[3].effect[3] = 0;
  medicine_items[3].effect[4] = 0;
  medicine_items[3].des = "This can save your life";

  // Sedative
  medicine_items[4].name = "Sedative";
  medicine_items[4].effect[0] = 0;
  medicine_items[4].effect[1] = 0;
  medicine_items[4].effect[2] = 0;
  medicine_items[4].effect[3] = 20;
  medicine_items[4].effect[4] = 0;
  medicine_items[4].des = "Useful when you are mentally unstable";

  //return choose(medicine_items, medicine_num, x);
  return medicine_items[x];
}

// Function: choose Weapon item (default choose by index)
// Input: int x: item index 
// Output: Item: choosen item
// NOTE: 0: Wooden Stick; 1: Rock; 2: Knife; 3: Spear
Item weapon(int x) {
  Item weapon_items[weapon_num];
  Item choosen;

  // Wooden Stick
  // initial, can't be drawn, forever
  weapon_items[0].name = "Wooden Stick";
  weapon_items[0].effect[0] = 0;
  weapon_items[0].effect[1] = 0;
  weapon_items[0].effect[2] = 0;
  weapon_items[0].effect[3] = 0;
  weapon_items[0].effect[4] = 5;
  weapon_items[0].des = "The weapon that forever belongs to you";
 
  // Rock
  weapon_items[1].name = "Rock";
  weapon_items[1].effect[0] = 0;
  weapon_items[1].effect[1] = 0;
  weapon_items[1].effect[2] = 0;
  weapon_items[1].effect[3] = 0;
  weapon_items[1].effect[4] = 15;
  weapon_items[1].des = "This rock should be able to cause some damage";

  // Knife
  weapon_items[2].name = "Knife";
  weapon_items[2].effect[0] = 0;
  weapon_items[2].effect[1] = 0;
  weapon_items[2].effect[2] = 0;
  weapon_items[2].effect[3] = 0;
  weapon_items[2].effect[4] = 20;
  weapon_items[2].des = "This is a sharp sharp knife";

  // Spear
  // only after event, cannot be drawn
  weapon_items[3].name = "Spear";
  weapon_items[3].effect[0] = 0;
  weapon_items[3].effect[1] = 0;
  weapon_items[3].effect[2] = 0;
  weapon_items[3].effect[3] = 0;
  weapon_items[3].effect[4] = 100;
  weapon_items[3].des = "This spear from the cannibals should be useful";

  return weapon_items[x];
}

// Function: choose Mystery item (default choose by index)
// Input: int x: item index 
// Output: Item: choosen item
// NOTE: 0: Leaf; 1: Newspaper; 2: Wilson the Volleyball; 3: Flashlight; 4: Gameboy; 5: Seashell
Item mystery(int x) {
  Item mystery_items[mystery_num];
  Item choosen;

  // Leaf
  mystery_items[0].name = "Leaf";
  mystery_items[0].effect[0] = 0;
  mystery_items[0].effect[1] = 0;
  mystery_items[0].effect[2] = 0;
  mystery_items[0].effect[3] = 0;
  mystery_items[0].effect[4] = 0;
  mystery_items[0].des = "This useless piece of leaf";

  // Newspaper
  mystery_items[1].name = "Newspaper";
  mystery_items[1].effect[0] = 0;
  mystery_items[1].effect[1] = 0;
  mystery_items[1].effect[2] = 0;
  mystery_items[1].effect[3] = 0;
  mystery_items[1].effect[4] = 0;
  mystery_items[1].des = "The headline of today is .....";

  // Wilson the Volleyball
  mystery_items[2].name = "Wilson the Volleyball";
  mystery_items[2].effect[0] = 0;
  mystery_items[2].effect[1] = 0;
  mystery_items[2].effect[2] = 0;
  mystery_items[2].effect[3] = 10;
  mystery_items[2].effect[4] = 0;
  mystery_items[2].des = "This is your friend, Wilson the Volleyball";

  // Flashlight
  // end any fight
  mystery_items[3].name = "Flashlight";
  mystery_items[3].effect[0] = 0;
  mystery_items[3].effect[1] = 0;
  mystery_items[3].effect[2] = 0;
  mystery_items[3].effect[3] = 0;
  mystery_items[3].effect[4] = 0;
  mystery_items[3].des = "Hmmm? What can a flashlight be use for?";

  // Gameboy
  mystery_items[4].name = "Gameboy";
  mystery_items[4].effect[0] = 0;
  mystery_items[4].effect[1] = 0;
  mystery_items[4].effect[2] = 0;
  mystery_items[4].effect[3] = 10;
  mystery_items[4].effect[4] = 0;
  mystery_items[4].des = "Forever a GAMER";

  // Seashell
  mystery_items[5].name = "Seashell";
  mystery_items[5].effect[0] = 0;
  mystery_items[5].effect[1] = 0;
  mystery_items[5].effect[2] = 0;
  mystery_items[5].effect[3] = 5;
  mystery_items[5].effect[4] = 0;
  mystery_items[5].des = "You can hear the ocean in the Seashell";

  return mystery_items[x];
}

