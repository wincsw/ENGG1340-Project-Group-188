// data_attackers.cpp
// stored datas of the attackers which will be used for fight event in the game
#include <iostream>
#include "structures.h"

int main()
{
attacker bear;
bear.name = "Bear";
bear.hp = 100;
bear.atk = 10;
bear.lost = 25;
bear.item = "Meat";
bear.des = "This is a bear!";

attacker crocodile;
crocodile.name = "Crocodile";
crocodile.hp = 80;
crocodile.atk = 15;
crocodile.lost = 25;
crocodile.item = "Meat";
crocodile.des = "This is a crocodile!";

attacker wolf;
wolf.name = "Wolf";
wolf.hp = 60;
wolf.atk = 20;
wolf.lost = 25;
wolf.item = "Meat";
wolf.des = "This is a wolf!";

attacker cannibal;
cannibal.name = "Cannibal";
cannibal.hp = 100;
cannibal.atk = 15;
cannibal.lost = 50;
cannibal.item = "Spear";
cannibal.des = "This is a cannibal!";

attacker zombie;
zombie.name = "Zombie";
zombie.hp = 50;
zombie.atk = 15;
zombie.lost = 50;
zombie.des = "This is a zombie!";
}
