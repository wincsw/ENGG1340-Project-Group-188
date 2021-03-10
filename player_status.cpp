# include <iostream>
# include <iomanip>
# include <string>

using namespace std;

// the variable of the player status will be in the main.cpp

// {HP, Hydration, Health, Hunger, Mentailty}
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

