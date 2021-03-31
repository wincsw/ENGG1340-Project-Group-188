#ifndef DATA_EVENTS
#define DATA_EVENTS
#include "structures.h"

#include <string.h>
#include <iostream>
#include "structures.h"

extern const int event_num;

void printEffect(struct event object);

struct item choose(struct item category[], int len, int x, std::string name);

struct event events(int x, std::string name = " ");

void call_event();

#endif
