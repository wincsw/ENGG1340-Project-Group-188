#ifndef ITEM_PACK
#define ITEM_PACK

void item_menu(int water_count[], int food_count[], int medicine_count[], int weapon_count[], int other_count[]);
void water_menu();
void food_menu();
void medicine_menu();
void weapon_menu();
void other_menu();
void use_water(int x);
void use_food(int x);
void use_medicine(int x);
void use_weapon(int x);
void use_other(int x);
void printEffect(struct item object);

#endif
