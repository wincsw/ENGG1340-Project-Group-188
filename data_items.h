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

struct item water(int x, std::string name = " ");

struct item food(int x, std::string name = " ");

struct item medicine(int x, std::string name = " ");

struct item weapon(int x, std::string name = " ");

struct item mystery(int x, std::string name = " ");

#endif
