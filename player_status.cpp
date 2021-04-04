// player_status.cpp
// print out the player status and excute the daily hydration and hunger drop

#include <iostream>
#include <iomanip>  // for the format layout
#include <cstdlib>  // for random number generater
#include <ctime>  // for the seed of random number generater
#include <string>
#include "player_status.h"

using namespace std;

// Function: print out player status
// Input: int status[4]: player status
// NOTE: 0: HP; 1: Hydration; 2: Hunger; 3: Mentailty
void printStatus(int status[4]) {
  cout << "Player Status" << endl;
  cout.width(9);
  cout << left << "HP" << ": " << status[0] << endl;
  cout.width(9);
  cout << left << "Hydration" << ": " << status[1] << endl;
  cout.width(9);
  cout << left << "Hunger" << ": " << status[2] << endl;
  cout.width(9);
  cout << left << "Mentality" << ": " << status[3] << endl;
}

// Function: exicute the daily deduction of hydration and hunger 
//           and HP deduction if mental is below 50
// Input: int status[4]: player status
void dailyDrop(int status[4]) {
  // random number generater
  srand(time(NULL)); // set seed to time
  // random in range [1, 10] 
  int * hydration_drop = new int (rand() % 10 + 1); 
  int * hunger_drop = new int(rand() % 10 + 1); 

  cout << "Daily Drop" << endl;
  cout << "---------------------------" << endl;

  status[1] -= *hydration_drop;  // hydration drop 
  cout << "-" << *hydration_drop << " Hydration" << endl;
  
  status[2] -= *hunger_drop;  // hunger drop
  cout << "-" << *hunger_drop << " Hunger" << endl;

  // mental < 50 --> HP deduct 5 per day
  if (status[3] < 50 || status[2] < 50) {
    status[0] -= 10;
    cout << "-5 HP" << endl;
  }

  // free out memory
  delete hydration_drop;
  hydration_drop = 0;
  delete hunger_drop;
  hunger_drop = 0;
}
