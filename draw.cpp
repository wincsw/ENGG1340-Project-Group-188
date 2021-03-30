// draw.cpp
// set the probability of the items and 
// dailyDraw(water_count, food_count, medicine_count ,weapon_count ,other_count)
// to execute 3 daily draws

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "structures.h"
#include "data_items.h"
#include "item_pack.h" // for printEffect()

using namespace std;




// Function: general one draw item
// Input: int catagory: use to indicate the catagory
//        int item_index: index of the item 
//        int num: random value
void draw(int &catagory, int &item_index, int num) {

  // draw water item --> 20% --> 1 ~ 20
  // Clean Water cannot be drawn
  if (num <= 20){
    catagory = 1;
    // 4 remaining item same probability --> 5%
    item_index = num % 4 + 1; // range 1-4 --> 20%/4 = 5%
  }
  // draw food item --> 20% --> 21 ~ 40
  // Energy Bar cannot be drawn
  else if (num <= 40) {
    catagory = 2;
    // 4 remaining item same probability --> 5%
    item_index = num % 4 + 1; 
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
  }
  // draw weapon item --> 30%
  // Wooden Stick and Spear cannot be drawn
  else if (num <= 90) {
    // 2 remaining item same probability --> 15% 
    catagory = 4;
    item_index = num % 2 + 1; // range 1-2 --> 30%/2 = 15%
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
      item_index = temp % 4 + 2;
    }
  }
}


// Function: draw 3 item and add the item to item pack
// Input: int water_count[]: quanity of water items
//        int food_count[]: quanity of food items
//        int medicine_count[]: quanity of medicine items
//        int weapon_count[]: quanity of weapon items
//        int other_count[]: quanity of other items
void dailyDraw(int water_count[], int food_count[], int medicine_count[], 
                  int weapon_count[], int other_count[]) { 


  srand(time(NULL)); // set seed to time

  // 2D array allocated in dynamic memory 
  // refrence: https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
  int** draw_item = new int*[3];  
  for (int j = 0; j < 3; j++) {
    draw_item[j] = new int[2];
  }
  
  cout << "Daily Draw" << endl;
  cout << "---------------------------" << endl;

  for (int i = 0; i < 3; i++) {
    


    int num = rand() % 100 + 1; // random number in range [1, 100]

    // draw the item
    draw(draw_item[i][0], draw_item[i][1], num);
    
    // add 1 to the drawn item
    switch(draw_item[i][0]) {
      case 1:
        water_count[draw_item[i][1]]++;
        cout << water(draw_item[i][1]).name << endl;
        printEffect(water(draw_item[i][1]));
        break;
      case 2:
        food_count[draw_item[i][1]]++;
        cout << food(draw_item[i][1]).name << endl;
        printEffect(food(draw_item[i][1]));
        break;
      case 3:
        medicine_count[draw_item[i][1]]++;
        cout << medicine(draw_item[i][1]).name << endl;
        printEffect(medicine(draw_item[i][1]));
        break;
      case 4:
        weapon_count[draw_item[i][1]]++;
        cout << weapon(draw_item[i][1]).name << endl;
        printEffect(weapon(draw_item[i][1]));
        break;
      case 5:
        other_count[draw_item[i][1]]++;
        cout << mystery(draw_item[i][1]).name << endl;
        printEffect(mystery(draw_item[i][1]));
        break;
    }
    cout << "---------------------------" << endl;
  }

  // free memory of the 2D array
  // reference: https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
  for (int k = 0; k < 3; k++) {
    delete[] draw_item[k];
  }
  delete[] draw_item; 

  // press any key to continue game
  char quit;
  cout << "Press any key to continue game" << endl;
  cin >> quit;

  return;
}
/*
int main() {
  //tempory quantity of items
int water_count[5];
int food_count[5];
int medicine_count[5];
int weapon_count[4];
int other_count[6];
  
  dailyDraw(water_count, food_count, medicine_count, weapon_count, other_count);
}*/
 