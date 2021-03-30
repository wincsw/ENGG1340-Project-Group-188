#ifndef ITEM_PACK
#define ITEM_PACK

void item_menu(int status[], int water_count[], int food_count[], int medicine_count[], int weapon_count[], int other_count[]);

void water_menu(int water_count[], int status[]);

void food_menu(int food_count[], int status[]);

void medicine_menu(int medicine_count[], int status[]);

void weapon_menu(int weapon_count[], int status[]);

void other_menu(int other_count[], int status[]);

void use_water(int x, int water_count[], int status[]);

void use_food(int x,int food_count[], int status[]);

void use_medicine(int x, int medicine_count[], int status[]);

void use_weapon(int x, int weapon_count[], int status[]);

void use_other(int x, int other_count[], int status[]);

void printEffect(struct item object);

#endif
