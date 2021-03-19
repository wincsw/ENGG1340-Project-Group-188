# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "structures.h"
# include "data_items.h"

// tempory quantity of items
int water_count[5];
int food_count[5];
int medicine_count[5];
int weapon_count[4];
int other_count[6];


// general draw item
// int x: use to indicate the catagory
// int y: index of the item 
struct item draw(int &x, int &y) 
{
  struct item choosen; // the resturn item

  // random number generater
  srand(time(NULL)); // set seed to time
  int num = rand() % 100 + 1; // random in range [1, 100]

  // draw water item
  if (num <= 20){
    x = 1;
    y = num % 4 + 1;  // range 1-4
    choosen = water(y); // Clean Water cannot be drawn
  }
  // draw food item
  else if (num <= 40) {
    x = 2;
    y = num % 4 + 1;  // range 1-4
    choosen = food(y);  // Energy Bar cannot be drawn
  }
  // draw medicine item
  else if (num <= 60) {
    x = 3;
    int temp = num % 5;
    if (temp <= 2) {
      y = temp;
    }
    else if (temp % 5 <= 1) {
      y = 3;  // First Aid Kit have only 10% chance
    }
    else {
      y = 4;  // Sedative have only 15% chance
    }
    choosen = medicine(y);
  }
  // draw weapon item
  else if (num <= 90) {
    x = 4;
    y = num % 2 + 1; // range 1-3
    choosen = weapon(num % 2 + 1);  // Wooden Stick & Spear cannot be drawn
  }
  // draw mystery item
  else {
    x = 5;
    int temp = num % 10;
    if (temp < 6) {
      choosen = mystery(temp % 2);  // Leaf & Newspaper have 30% chance
    }
    else {
      choosen = mystery(temp);  // other have only 10 % chance
    }
  }

  return choosen;  
}


// draw 3 item every day
void dailyDraw(int wt[], int f[], int md[], int wp[], int my[]) {
  struct item* draw_item;
  draw_item = new struct item;  // dynamic memory management 

  for (int i = 0; i < 3; i++) {
    int catagory, index;
    draw_item = draw(catagory, index);
    switch(catagory) {
      case 1:
        wt[index] += 1;
      case 2:
        f[index] += 1;
      case 3:
        md[index] += 1;
      case 4:
        wp[index] += 1;
    }
  }

  delete draw_item; // free memory  
  
}