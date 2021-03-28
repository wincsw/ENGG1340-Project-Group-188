// draw.cpp
// set the probability of the items and the function for the 3 daily drawn items

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "structures.h"
#include "data_items.h"

// tempory quantity of items
int water_count[5];
int food_count[5];
int medicine_count[5];
int weapon_count[4];
int other_count[6];


// general draw item
// int catagory: use to indicate the catagory
// int item_index: index of the item 
struct item draw(int &catagory, int &item_index) 
{
  struct item choosen; // the resturn item

  // random number generater
  srand(time(NULL)); // set seed to time
  int num = rand() % 100 + 1; // random in range [1, 100]

  // draw water item --> 20% --> 1 ~ 20
  // Clean Water cannot be drawn
  if (num <= 20){
    catagory = 1;
    // 4 remaining item same probability --> 5%
    item_index = num % 4 + 1; // range 1-4 --> 20%/4 = 5%
    choosen = water(item_index); 
  }
  // draw food item --> 20% --> 21 ~ 40
  // Energy Bar cannot be drawn
  else if (num <= 40) {
    catagory = 2;
    // 4 remaining item same probability --> 5%
    item_index = num % 4 + 1; 
    choosen = food(item_index);  
  }
  // draw medicine item --> 20% --> 41 ~ 60
  else if (num <= 60) {
    catagory = 3;
    int temp = num % 20 + 1; // range 1-4 --> 20%/4 = 5%
    // Herb, Pill, Bandage --> total 15% --> 3(20%/5) = 15%
    if (temp <= 15) {
      // all same probability --> 5% --> 15%/3 = 5%
      item_index = temp % 3;
    }
    // First Aid Kit, Sedative --> total 5%
    else if (temp >= 19) {
      // First Aid Kit --> 2%
      item_index = 3;  
    }
    else {
      // Sedative --> 3%
      item_index = 4;  
    }
    choosen = medicine(item_index);
  }
  // draw weapon item --> 30%
  // Wooden Stick and Spear cannot be drawn
  else if (num <= 90) {
    // 2 remaining item same probability --> 15% 
    catagory = 4;
    item_index = num % 2 + 1; // range 1-2 --> 30%/2 = 15%
    choosen = weapon(item_index); 
  }
  // draw mystery item --> 10%
  else {
    catagory = 5;
    int temp = num % 10;
    if (temp < 6) {
      // Leaf & Newspaper --> total 6% --> 3% each
      item_index = temp % 2; 
    }
    else {
      // 4 remaining item same probability --> 1%
      item_index = temp;
    }
    choosen = mystery(item_index);
  }

  return choosen;  
}


// draw 3 item every day
void dailyDraw(int water_count[], int food_count[], int medicine_count[], 
                  int weapon_count[], int mystery_count[]) {
  struct item* draw_item;
  draw_item = new struct item;  // dynamic memory management 

  // add 1 to the drawn item
  for (int i = 0; i < 3; i++) {
    int catagory = 0, index = 0;
    draw_item = draw(catagory, index);
    
    switch(catagory) {
      case 1:
        water_count[index]++;
        break;
      case 2:
        food_count[index]++;
        break;
      case 3:
        medicine_count[index]++;
        break;
      case 4:
        weapon_count[index]++;
        break;
      case 5:
        other_count[index]++;
        break;
    }
  }

  delete draw_item; // free memory  
  
}