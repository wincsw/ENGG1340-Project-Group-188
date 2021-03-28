// data_attackers.cpp
// stored datas of the attackers which will be used for fight event in the game
#include <iostream>
#include <string>
#include "structures.h"

using namespace std;

const int attacker_num = 5;

// selecting the corrsponding item
struct attacker choose(struct attacker category[], int len, int x, string name) {
  struct attacker choosen;
  if (x != -1) {
    for (int i = 0; i < len; i++) {
      if (i == x) {
        choosen = category[i];
      }
    }
  }
  else {
    for (int i = 0; i < len; i++) {
      if (category[i].name == name) {
        choosen = category[i];
      }
    }
  }

  return choosen;
}

// changed: <struc> cannot be global variable (sorry that I didn't tell you) --> use function to access (same as the one in <data_items.cpp>)

// Attackers
// int x = -1 --> choose by name
// string name = " " --> choose by index (default)
// effect --> [HP, Hydration, Hunger, Mentailty, ATK]
struct attacker attackers(int x, string name = " ") {
  struct attacker all[attacker_num];
  struct attacker choosen;

  all[0].name = "Bear";
  all[0].hp = 100;
  all[0].atk = 10;
  all[0].lost = 25;
  all[0].item[0] = 1;
  all[0].item[1] = 1;
  all[0].des = "This is a bear!";

  all[1].name = "Crocodile";
  all[1].hp = 80;
  all[1].atk = 15;
  all[1].lost = 25;
  all[1].item[0] = 1;
  all[1].item[1] = 1;
  all[1].des = "This is a crocodile!";

  all[2].name = "Wolf";
  all[2].hp = 60;
  all[2].atk = 20;
  all[2].lost = 25;
  all[2].item[0] = 1;
  all[2].item[1] = 1;
  all[2].des = "This is a wolf!";

  all[3].name = "Cannibal";
  all[3].hp = 100;
  all[3].atk = 15;
  all[3].lost = 50;
  all[3].item[0] = 2;
  all[3].item[1] = 3;
  all[3].des = "This is a cannibal!";

  all[4].name = "Zombie";
  all[4].hp = 50;
  all[4].atk = 15;
  all[4].lost = 50;
  all[4].item[0] = 0;
  all[4].item[1] = 0;
  all[4].des = "This is a zombie!";

  return choose(all, attacker_num, x, name);

}
