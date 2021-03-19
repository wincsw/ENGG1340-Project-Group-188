// data_items.h
// Header file of data_items.cpp

#ifndef ITEM_DATA
#define ITEM_DATA


#include <string.h>
#include <iostream>
#include "structures.h"

// the number of item of different category
extern const int water_num;
extern const int food_num;
extern const int medicine_num;
extern const int weapon_num;
extern const int mystery_num;

struct item choose(struct item category[], int len, int x, std::string name);

// call items by either index number (default) or name (int x = -1)

// 0: Clean Water; 1: Soda/Pepsi; 2: Pee; 3: Cocount; 4: Dirty Water
struct item water(int x, std::string name = " ");

// 0: Energy Bar; 1: Meat; 2: Wild Berry; 3: Worm; 4: Unknown Mushroom
struct item food(int x, std::string name = " ");

// 0: Herb; 1: Pill; 2: Bandage; 3: First Aid Kit; 4: Sedative
struct item medicine(int x, std::string name = " ");

// 0: Wooden Stick; 1: Rock; 2: Knife; 3: Spear
struct item weapon(int x, std::string name = " ");

// 0: Leaf; 1: Newspaper; 2: Wilson the Volleyball; 3: Flashlight; 4: Gameboy; 5: Seashell
struct item mystery(int x, std::string name = " ");

#endif
