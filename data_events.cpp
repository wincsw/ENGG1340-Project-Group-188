// data_events.cpp
// include all the events effects
// call_event(water_count, weapon_count, other_count, food_count, status) to call the events randonly
// also include the

#include <iostream>
#include <string>
#include <stdlib.h>     // allow to use system ("clear")
#include <unistd.h>     // allow to use sleep()
#include "structures.h"
#include "item_pack.h"
#include "data_items.h"
#include "fight.h"

using namespace std;

const int event_num = 5;

// Function: print out the effect of the event
// Input: struct Event object: printed event
void printEventEffect(struct Event object)
{
  string status[] = {"HP", "Hydration", "Hunger", "Mentality"};
  int empty[] = {0, 0, 0, 0};

  if (object.effect == empty) {
    cout << "Nothing happened." << endl;
  }
  else {
    for (int i = 0; i < 4; i++) {
      char sign;
      if (object.effect[i] > 0) {
        sign = '+';
      }
      else if (object.effect[i] < 0) {
        sign = '\0';
      }
      else {
        continue;
      }
      cout << sign << object.effect[i] << " " << status[i] << endl;
    }
  }
}

// Function: choose event (default choose by index)
// Input: int x: event index
// Output: struct Event: choosen event
// NOTE: 0: Raining; 1: Thunderstorm; 2: Find Dead Body; 3: Find the remains; 4: Bird Poop
struct Event events(int x, string name)
{
    struct Event all[event_num];

    all[0].name = "Raining";
    all[0].effect[0] = -10;
    all[0].effect[1] = 0;
    all[0].effect[2] = 0;
    all[0].effect[3] = 0;
    all[0].item = "Clean Water";
    all[0].output[0] = "Oh, there is raining!";
    all[0].output[1] = "You can get some clear water!";
    all[0].output[2] = "But you have nothing to cover yourself.";
    all[0].output[3] = "You feel cold.";
    all[0].output[4] = "You feel sick now.";


    all[1].name = "Thunderstorm";
    all[1].effect[0] = -10;
    all[1].effect[1] = 0;
    all[1].effect[2] = 0;
    all[1].effect[3] = -5;
    all[1].item = "Clean Water";
    all[1].output[0] = "Oh, the weather is too bad.";
    all[1].output[1] = "There is thunderstorm.";
    all[1].output[2] = "Lightening?";
    all[1].output[3] = "Boom! (A sudden big sound make you feel scared.)";
    all[1].output[4] = "Your heart get hurt.";

    all[2].name = "Find Dead Body";
    all[2].effect[0] = 0;
    all[2].effect[1] = 0;
    all[2].effect[2] = 0;
    all[2].effect[3] = -10;
    all[2].item = "no";
    all[2].output[0] = "You walk through the path.";
    all[2].output[1] = "Seem peaceful. Oh, what's that?";
    all[2].output[2] = "OMG! A dead body here!";
    all[2].output[3] = "What would be your fate?";
    all[2].output[4] = "Your heart be broken!";

    all[3].name = "Find Remains";
    all[3].effect[0] = 0;
    all[3].effect[1] = 0;
    all[3].effect[2] = 0;
    all[3].effect[3] = -10;
    all[3].item = "no";
    all[3].output[0] = "You walk through the path.";
    all[3].output[1] = "Oh! what's that? A remain?";
    all[3].output[2] = "There may be something useful?";
    all[3].output[3] = "After a long time search, you find nothing.";
    all[3].output[4] = "Your emotion get bad.";


    all[4].name = "Bird Boop";
    all[4].effect[0] = 0;
    all[4].effect[1] = 0;
    all[4].effect[2] = 0;
    all[4].effect[3] = -5;
    all[4].item = "no";
    all[4].output[0] = "You walk through the path.";
    all[4].output[1] = "You look up the sky. Sky is blue, it seems a good day today.";
    all[4].output[2] = "A group of birds flying above you.";
    all[4].output[3] = "POP! OMG, something drop on your face.";
    all[4].output[4] = "It's that poop?";


    return all[x];
}

// Function: call event randomly
// Input: int water_count[]: quantity of water items
//        int weapon_count[]: quantity of weapon items
//        int other_count[]: quantity of other items 
//        int status[]: player status
void call_event(int water_count[], int weapon_count[], int other_count[], 
            int food_count[], int status[])
{
  // randonly choose an event
  srand(time(NULL)); // set seed to time

  int num = (rand() % 10); // random number in range [0, 9]

  // num 0 - 4 for the normal events, num from 5-9 is for fight events
  if (num < 5)
  {
    struct Event current_event = events(num, " ");

    system("clear");
    cout << "Random Event: ";
    cout << current_event.name << endl;
    cout << "---------------------------" << endl;

    sleep(1);

    // printing the output text
    for ( int i = 0 ; i < 5 ; i++ )
    {
      cout << current_event.output[i] << endl;
      sleep(1);
    }
    printEventEffect(events(num, " "));
    if ( current_event.item != "no")
    {
      // the event can only gain clean water or nothing
      sleep(1);
      cout << "Clean Water + 1" << endl; 
      water_count[0] += 1;
    }

    // adding the effect of the event to player status
    status[0] += current_event.effect[0]; // HP
    status[3] += current_event.effect[3]; // Mentality

    sleep(3);
    system("clear");
  }

  // the below for the num from 5 - 9 (for fight)
  // call function from fight.cpp
  else
  {
    system("clear");
    cout << "Random Event: Attack" << endl; 
    cout << "---------------------------" << endl;
    fight( weapon_count, other_count, food_count, status );
  }
}
