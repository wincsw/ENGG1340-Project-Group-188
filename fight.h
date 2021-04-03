#ifndef FIGHT
#define FIGHT

// Function: generate a random attacker
struct attacker randAttacker();

// Function: print out the weapons the player have
// Input: int weapon_count[]: quanity of each weapon item
//        int index_to_weapon[]: linking display index to weapon index
// Output: int: total number of weapon types allowed to choose
int printWeapon(int weapon_count[], int * &index_to_weapon);

// Function: exicute the fighting event
// Input: int weapon_count[]: quanity of each weapon item
//        int other_count[]: quanity of each mystery item (for Flashlight)
//        int food_count[]: quanity of each food item
//        int player_status[]: player status
void fight(int weapon_count[], int other_count[], int food_count[], 
            int player_status[]);




#endif