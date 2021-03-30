#ifndef DATA_ATTACKER
#define DATA_ATTACKER
#include "structures.h"

// total number of attackers
extern const int attacker_num;

// Function: choose attacker according to the attacker index or name
// Input: struct attacker category[]: array of attacker
//        int len: lenght of the array
//        int x: attacker index
//        string name: attacker name
// Output: struct attacker: choosen attacker
struct attacker choose(struct attacker category[], int len, int x, std::string name);

// Function: call attacker (default choose by index)
// Input: int x: attacker index (-1 --> choose by name)
//        string name = " ": attacker name, (" "--> choose by index)
// Output: struct attacker: called attacker
// NOTE: 0: Bear; 1: Crocodile; 2: Wolf; 3: Cannibal; 4: Zombie
struct attacker attackers(int x, std::string name = " ");

#endif
