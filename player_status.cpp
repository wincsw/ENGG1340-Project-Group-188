// player_status.cpp
// print out the player status and excute the daily hydration and hunger drop

#include <iostream>
#include <iomanip>  // for the format layout
#include <cstdlib>  // for random number generater
#include <ctime>  // for the seed of random number generater
#include <string>

using namespace std;

int temp_status[4] = {100, 100, 100, 100};
// the official of the player status will be in the main.cpp

// print the player's status
// --> HP, Hydration, Hunger, Mentailty
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

// the daily drop of Hydration and Hunger
void dailyDrop(int status[4]) {
  // random number generater
  srand(time(NULL)); // set seed to time
  int hydration_drop = rand() % 5 + 1; // random in range [1, 5]
  int hunger_drop = rand() % 5 + 1; 

  status[1] -= hydration_drop;  // hydration drop 
  status[2] -= hunger_drop;  // hunger drop
}
