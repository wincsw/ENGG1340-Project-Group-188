# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "structures.h"
# include "data_items.h"

// general draw item
struct item draw() 
{
  struct item choosen; // the resturn item

  // random number generater
  srand(time(NULL)); // set seed to time
  int num = rand() % 100 + 1; // random in range [1, 100]

  // draw water item
  if (num <= 20){
    choosen = water(num % 4 + 1);
  }
  // draw food item
  else if (num <= 40) {
    choosen = food(num % 4 + 1);
  }
  // draw medicine item
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
  // draw weapon item
  else if (num <= 90) {
    choosen = weapon(num % 2 + 1);
  }
  // draw mystery item
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


// draw 3 item every day
struct item* dailyDraw() {
  struct item* three_item;
  three_item = new struct item [3];

  for (int i = 0; i < 3; i++) {
    three_item[i] = draw();
  }

  return three_item;
}