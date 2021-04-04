#ifndef DATA_EVENTS
#define DATA_EVENTS
#include "structures.h"

#include <string.h>
#include <iostream>
#include "structures.h"

extern const int event_num;

void printEventEffect(struct Event object);

struct Event choose(struct Event category[], int len, int x, std::string name);

struct Event events(int x);

void call_event(int water_count[], int weapon_count[], int other_count[], 
            int food_count[], int status[]);

#endif
