// data_item.cpp
// Store all the resource item in five catagory 
// -- water, food, medicine, weapon, mystery 

# include <iostream>
# include <string>
# include "structures.h"

using namespace std;


// x = -1 --> search by name
// string = " " --> search by number
struct item choose(struct item list[], int len, int x, string name) {
  struct item choosen;
  if (x != -1) {
    for (int i = 0; i < len; i++) {
      if (i == x) {
        choosen = list[i];
      }
    }
  }
  else {
    for (int i = 0; i < len; i++) {
      if (list[i].name == name) {
        choosen = list[i];
      }
    }
  }

  return choosen;
}

// effect --> [HP, Hydration, Hunger, Mentailty, ATK]

// Water Items
struct item water(int x, string name) 
{
  const int num_of_item = 5;
  struct item water_items[num_of_item];
  struct item choosen;

  // Clean Water
  // initial, can't be drawn
  water_items[0].name = "Clean Water";
  water_items[0].effect[0] = 0;
  water_items[0].effect[1] = 10;
  water_items[0].effect[2] = 0;
  water_items[0].effect[3] = 0;
  water_items[0].effect[4] = 0;
  water_items[0].des = "Water that is save to drink, nothing special";
 
  // Soda / Pepsi
  water_items[1].name = "Pepsi";
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
  water_items[3].name = "Cocunut";
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

  return choose(water_items, num_of_item, x, name);
}

// Food Items
struct item food(int x, string name) 
{
  const int num_of_item = 5;
  struct item food_items[num_of_item];
  struct item choosen;

  // Energy Bar
  // initial, can't be drawn
  food_items[0].name = "Energy Bar";
  food_items[0].effect[0] = 0;
  food_items[0].effect[1] = 10;
  food_items[0].effect[2] = 0;
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
  food_items[3].effect[1] = 10;
  food_items[3].effect[2] = 0;
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

  return choose(food_items, num_of_item, x, name);
}

// Medicine Items
struct item medicine(int x, string name) 
{
  const int num_of_item = 5;
  struct item medicine_items[num_of_item];
  struct item choosen;

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
  medicine_items[3].des = "First Aid Kit that can save your life. \
  At least this is what video game taught me";

  // Sedative
  medicine_items[4].name = "Sedative";
  medicine_items[4].effect[0] = 0;
  medicine_items[4].effect[1] = 0;
  medicine_items[4].effect[2] = 0;
  medicine_items[4].effect[3] = 20;
  medicine_items[4].effect[4] = 0;
  medicine_items[4].des = "Sedative is useful when you are mentally unstable";

  return choose(medicine_items, num_of_item, x, name);
}

// Weapon Items
struct item weapon(int x, string name) 
{
  const int num_of_item = 4;
  struct item weapon_items[num_of_item];
  struct item choosen;

  // Wooden Stick
  // initial, can't be drawn, forever
  weapon_items[0].name = "Wooden Stick";
  weapon_items[0].effect[0] = 0;
  weapon_items[0].effect[1] = 0;
  weapon_items[0].effect[2] = 0;
  weapon_items[0].effect[3] = 0;
  weapon_items[0].effect[4] = 5;
  weapon_items[0].des = "The best (most usless) weapon ever";
 
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
  weapon_items[3].name = "Spear";
  weapon_items[3].effect[0] = 0;
  weapon_items[3].effect[1] = 0;
  weapon_items[3].effect[2] = 0;
  weapon_items[3].effect[3] = 0;
  weapon_items[3].effect[4] = -100;
  weapon_items[3].des = "This spear from the cannibals should be useful";

  return choose(weapon_items, num_of_item, x, name);
}

// Mystery Items
struct item mystery(int x, string name) 
{
  const int num_of_item = 6;
  struct item mystery_items[num_of_item];
  struct item choosen;

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

  // Spear
  mystery_items[4].name = "Gameboy";
  mystery_items[4].effect[0] = 0;
  mystery_items[4].effect[1] = 0;
  mystery_items[4].effect[2] = 0;
  mystery_items[4].effect[3] = 0;
  mystery_items[4].effect[4] = 10;
  mystery_items[4].des = "Forever a GAMER";

  // Seashell
  mystery_items[5].name = "Seashell";
  mystery_items[5].effect[0] = 0;
  mystery_items[5].effect[1] = 0;
  mystery_items[5].effect[2] = 0;
  mystery_items[5].effect[3] = 0;
  mystery_items[5].effect[4] = -100;
  mystery_items[5].des = "You can hear the ocean in the Seashell";

  return choose(mystery_items, num_of_item, x, name);
}
