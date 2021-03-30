// fight.cpp
// fighting events 

#include <iostream>
#include <string>
#include <stdlib.h>     // allow to use system ("clear")
#include <unistd.h>     // allow to use sleep()
#include "structures.h"
#include "data_attackers.h"
#include "data_items.h"
#include "player_status.h"

// tempory --> will be in main.cpp
int water_count[5] = {1};
int food_count[5] = {1};
int medicine_count[5] = {1};
int weapon_count[4] = {1, 2, 1};
int other_count[6] = {1, 0, 0, 1};

using namespace std;

// Function: generate a random attacker
struct attacker randAttacker() {

  // random number generater
  srand(time(NULL)); // set seed to time
  int num = rand() % 5; // random in range [0, 5] --> 5 attacker to choose

  // return the attacker according to the RNG
  return attackers(num);
}

// Function: print out the weapons the player have
// Input: int weapon_count[]: quanity of each weapon item
//        int index_to_weapon[]: linking display index to weapon index
// Output: int: total number of weapon types allowed to choose
int printWeapon(int weapon_count[], int * &index_to_weapon) {
  // display index - 1 and the total number of usable weapons
  int index = 0;

  for (int i = 0; i < 4; i++) {
    if (weapon_count[i] > 0) {
      // print out the name, quanity and ATK of the weapon
      cout << index + 1 << ". " << weapon(i).name << ' ' << weapon_count[i] 
              << " ATK: " << weapon(i).effect[4] <<endl;
      // link the display index to the weapon index
      index_to_weapon[index] = i;
      index++;
    }
  }

  // return the total number of usable weapon
  return index;
}


// Function: exicute the fighting event
// Input: int weapon_count[]: quanity of each weapon item
//        int other_count[]: quanity of each mystery item (for Flashlight)
//        int food_count[]: quanity of each food item
//        int player_status[]: player status
void fight(int weapon_count[], int other_count[], int food_count[], 
            int player_status[]) {

  // randonly choose an attacker 
  struct attacker opponent = randAttacker();

  cout << opponent.des << endl;
  sleep(1);

  // if the player have a Flashlight, they can choose to end the fight
  if (other_count[3] > 0) {
    char choose;
    cout << endl;
    cout << "A Flashlight can scare away the " << opponent.name << endl;
    cout << "Do you want to use? (You have " << other_count[3] << "Flashlight)" << endl;
    cout << "Y for use, other key for not to use" << endl;
    cin >> choose;
    
    if (choose == 'y' || choose == 'Y') {
      // end this function and minus 1 on the number of Flashlight
      sleep(1);
      system("clear");

      cout << "The " << opponent.name << " is scared by the Flashlight and run away" << endl;
      cout << "You are save now" << endl;
      other_count[3]--;
      return;
    }
    else {
      sleep(1);
      system("clear");
      cout << "You are a brave person" << endl;
    }
  }

  // a temporary HP for determining player win/lose
  int temp_hp = 100;
  // the attacker's HP
  int opponent_hp = opponent.hp;
  // the number of usable weapon
  int len = 4;

  cout << "Let's fight the " << opponent.name << "!!!!" << endl;
  
  sleep(2);
  system("clear");

  // fight end when the player's or attacker's reach 0
  while (temp_hp > 0 && opponent_hp > 0) {

    // the linkage between the displayed index and weapon index
    int * index_to_weapon = new int [len];

    // players weapon choice in display index
    int weapon_choice = 0;

    // display player and attacker's hp
    cout << "Your fighting HP: " << temp_hp << endl;
    cout << opponent.name << " HP:" << opponent_hp << endl;
    sleep(1);
    
    cout << endl;
    cout << "Choose a weapon" << endl;

    // print out usable weapons
    len = printWeapon(weapon_count, index_to_weapon);

    cin >> weapon_choice;

    // make sure input is in range of 1~number of usable weapon
    while (weapon_choice < 1 || weapon_choice > len) {
        cout << "Invaild input, please input again!" << endl;
        cin >> weapon_choice;
    }

    
    sleep(1);
    system("clear");

    // link player's choice from display index to weapon index
    weapon_choice = index_to_weapon[weapon_choice - 1];

    delete[] index_to_weapon; // free out memory

    cout << "You attack " << opponent.name << " with "
          << weapon(weapon_choice).name << endl;
    cout << opponent.name << " -" << weapon(weapon_choice).effect[4] << "HP" 
          << endl;
    
    // deduct attacker's hp
    opponent_hp -= weapon(weapon_choice).effect[4];
    
    // minus 1 for the weapon used --> except Wooden Stick
    if (weapon_choice != 0) {
      weapon_count[weapon_choice]--;
    }

    sleep(2);
    system("clear");    

    // if attacker is not dead --> attacks player
    if (opponent_hp > 0) {
      cout << opponent.name << " attack you!" << endl;
      cout << "You -" << opponent.atk << "HP" << endl;
      temp_hp -= opponent.atk;
    }
    
    sleep(2);
    system("clear");
  }

  // player win
  if (temp_hp > 0) {
    cout << "You WIN the fight!!!" << endl;

    // reward for winning the fight 
    int reward_catagory = opponent.item[0];

    switch (reward_catagory) {
      // no reward
      case 0:
        break;
      // food reward
      case 1:
        cout << food(opponent.item[1]).name << " +1" << endl;
        food_count[opponent.item[1]] += 1;
        break;
      // weapon reward
      case 2:
        cout << weapon(opponent.item[1]).name << " +1" << endl;
        weapon_count[opponent.item[1]] += 1;
        break;
    }

    sleep(1);
  }
  // player lose
  else {
    cout << "You LOSE the fight!!!" << endl;
    // losing the fight --> lose HP
    cout << "HP -" << opponent.lost << endl;
    player_status[0] -= opponent.lost;

    sleep(1);
  }

}

int main() {
  fight(weapon_count, other_count, food_count, temp_status);
}