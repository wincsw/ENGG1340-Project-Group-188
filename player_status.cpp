# include <iostream>
# include <iomanip>
# include <string>

using namespace std;

int temp_status[4] = {100, 100, 100, 100};
// the official array of the player status will be in the main.cpp

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
  cout << left <<"Mentality" << ": " << status[3] << endl;
}

