# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "structures.h"
# include "data_items.h"


struct item draw() 
{
  struct item choosen;
  srand(time(NULL));
  int num = rand() % 100 + 1;
  if (num <= 20){
    choosen = water(num % 4 + 1);
  }
  else if (num <= 40) {
    choosen = food(num % 4 + 1);
  }
  else if (num <= 60) {
    int temp = num % 5;
    if (temp <= 2) {
      choosen = medicine(temp);
    }
    else if (temp % 5 <= 1) {
      choosen = medicine(3);
    }
    else {
      choosen = medicine(4);
    }
  }
  else if (num <= 90) {
    choosen = weapon(num % 2 + 1);
  }
  else {
    int temp = num % 10;
    if (temp < 6) {
      choosen = mystery(temp % 2);
    }
    else {
      choosen = mystery(temp);
    }
  }

  return choosen;  
}