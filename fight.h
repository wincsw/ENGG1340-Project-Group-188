#ifndef FIGHT
#define FIGHT

struct Attacker randAttacker();

int printWeapon(int weapon_count[], int * &index_to_weapon);

void fight(int weapon_count[], int other_count[], int food_count[], 
            int player_status[]);




#endif
