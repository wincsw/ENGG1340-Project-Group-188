#ifndef DATA_ATTACKER
#define DATA_ATTACKER
#include "structures.h"

// total number of attackers
extern const int attacker_num;

struct attacker choose(struct attacker category[], int len, int x, std::string name);

// call attackers 
struct item attackers(int x, std::string name = " ");

#endif
