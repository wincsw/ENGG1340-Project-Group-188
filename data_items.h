// data_items.h
// Header file of data_items.cpp

#ifndef ITEM_DATA
#define ITEM_DATA


#include <string.h>
#include <iostream>
#include "structures.h"


extern const int water_num;
extern const int food_num;
extern const int medicine_num;
extern const int weapon_num;
extern const int mystery_num;

struct item choose(struct item category[], int len, int x, std::string name);

// 0: Clean Water; 1: Soda/Pepsi; 2: Pee; 3: Cocount; 4: Dirty Water
// either index number or name
struct item water(int x = -1, std::string name = " ");

// 0: Energy Bar; 1: Meat; 2: Wild Berry; 3: Worm; 4: Unknown Mushroom
// either index number or name
struct item food(int x = -1, std::string name = " ");

// 0: Herb; 1: Pill; 2: Bandage; 3: First Aid Kit; 4: Sedative
// either index number or name
struct item medicine(int x = -1, std::string name = " ");

// 0: Wooden Stick; 1: Rock; 2: Knife; 3: Spear
// either index number or name
struct item weapon(int x = -1, std::string name = " ");

// 0: Leaf; 1: Newspaper; 2: Wilson the Volleyball; 3: Flashlight; 4: Gameboy; 
// 5: Seashell
// either index number or name
struct item mystery(int x = -1, std::string name = " ");

#endif
