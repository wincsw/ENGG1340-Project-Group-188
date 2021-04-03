#ifndef DATA_EVENTS
#define DATA_EVENTS
#include "structures.h"

#include <string.h>
#include <iostream>
#include "structures.h"

extern const int event_num;

void printEventEffect(struct event object);

struct event choose(struct event category[], int len, int x, std::string name);

struct event events(int x);

void call_event(int water_count[], int weapon_count[], int other_count[], 
            int food_count[], int status[]);

#endif
