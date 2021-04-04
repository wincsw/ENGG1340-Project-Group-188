// data_items.h
// Header file of data_items.cpp

#ifndef ITEM_DATA
#define ITEM_DATA


#include "structures.h"


extern const int water_num;    
extern const int food_num;    
extern const int medicine_num; 
extern const int weapon_num;   
extern const int mystery_num;   

Item water(int x);

Item food(int x);

Item medicine(int x);

Item weapon(int x);

Item mystery(int x);

#endif
