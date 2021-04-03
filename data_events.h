#ifndef DATA_EVENTS
#define DATA_EVENTS
#include "structures.h"

#include <string.h>
#include <iostream>
#include "structures.h"

extern const int event_num;

void printEventEffect(struct event object);

struct event choose(struct event category[], int len, int x, std::string name);

struct event events(int x, std::string name = " ");

void call_event();

#endif
