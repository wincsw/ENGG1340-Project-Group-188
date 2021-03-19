#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int temp_status[4] = {100, 100, 100, 100};
// the official of the player status will be in the main.cpp

// HP, Hydration, Hunger, Mentailty
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

void dailyDrop(int status[4]) {
  // random number generater
  srand(time(NULL)); // set seed to time
  int num1 = rand() % 5 + 1; // random in range [1, 5]
  int num2 = rand() % 5 + 1; 

  status[1] -= num1;  // hydration drop 
  status[2] -= num2;  // hunger drop
}
