// item_pack.cpp
// item_menu(water_count, food_count, medicine_count ,weapon_count ,other_count) to call menu
// printing item pack and allow using the items
# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>     // allow to use system ("clear")
# include <unistd.h>     // allow to use sleep()
# include "item_pack.h"
# include "data_items.h"  // for item datas
# include "structures.h"  // for structures

using namespace std;


// Function: print the effect of the item
// Input: struct Item object: printed item
void printEffect(struct Item object)
{
  string status[] = {"HP", "Hydration", "Hunger", "Mentality", "ATK"};
  int empty[] = {0, 0, 0, 0, 0};

  if (object.effect == empty) {
    cout << "USELESS" << endl;
  }
  else {
    for (int i = 0; i < 5; i++) {
      char sign;
      if (object.effect[i] > 0) {
        sign = '+';
      }
      else if (object.effect[i] < 0) {
        sign = '\0';
      }
      else {
        continue;
      }
      cout << sign << object.effect[i] << " " << status[i] << endl;
    }
  }
}

// Function: show details of water items and allow player to use selected items
// Input: int x: item index
//        int water_count[]: quanity of water item
//        int status[]: player status
void use_water(int x, int water_count[], int status[])
{
  char choose_use_or_not = 'x';
  system("clear");

  while (true)
  {
    // call name and des directly by <water(x)> function
    cout << water(x).name << endl;
    cout << water(x).des << endl;
    printEffect(water(x));
    sleep(1);
    cout << "Do you want to use? (You have " << water_count[x] << ' ' << water(x).name << ")"<< endl;
    cout << "Y for use, other key to back" << endl;
    cin >> choose_use_or_not;
    if (choose_use_or_not == 'Y' || choose_use_or_not == 'y')
    {
      if (water_count[x] > 0)
      {
        sleep(1);
        cout << water(x).name << " used!" << endl;
        water_count[x] -= 1;
        status[0] += water(x).effect[0]; // directly use <water(x).effect>
        status[1] += water(x).effect[1];
        status[3] += water(x).effect[3];
        // stop the loop and end this function
        sleep(1);
        system("clear");
        break;
      }// if user choose sth they don have --> let them choose again by looping
      else
      {
        cout << "You do not have it!" << endl;
        sleep(1);
        cout << "Please choose something that you HAVE!" << endl;
        sleep(1);
        system("clear");
        // back to menu
        return;
      }
    }
  // if input is not 'y' or 'Y':
    cout << "Back to the menu!" << endl;
    sleep(1);
    system("clear");
    return;
  }
}

// Function: show details of food items and allow player to use selected items
// Input: int x: item index
//        int food_count[]: quanity of food item
//        int status[]: player status
void use_food(int x, int food_count[], int status[])
{
  char choose_use_or_not = 'x';
  system("clear");

  while (true)
  {
    // call name and des directly by <food(x)> function
    cout << food(x).name << endl;
    cout << food(x).des << endl;
    printEffect(food(x));
    sleep(1);
    cout << "Do you want to use? (You have " << food_count[x] << ' ' << food(x).name << ")"<< endl;
    cout << "Y for use, other key to back" << endl;
    cin >> choose_use_or_not;
    if (choose_use_or_not == 'Y' || choose_use_or_not == 'y')
    {
      if (food_count[x] > 0)
      {
        sleep(1);
        cout << food(x).name << " used!" << endl;
        food_count[x] -= 1;
        status[0] += food(x).effect[0]; // directly use <food(x).effect>
        status[2] += food(x).effect[2];
        status[3] += food(x).effect[3];
        sleep(1);
        system("clear");
        // stop the loop and end this function
        break;
      }// if user choose sth they don have --> let them choose again by looping
      else
      {
        cout << "You do not have it!" << endl;
        sleep(1);
        cout << "Please choose something that you HAVE!" << endl;
        sleep(1);
        system("clear");
        return;
      }
    }
    cout << "Back to the menu!" << endl;
    sleep(1);
    system("clear");
    return;
  }
}

// Function: show details of medicine items and allow player to use selected items
// Input: int x: item index
//        int medicine_count[]: quanity of medicine item
//        int status[]: player status
void use_medicine(int x, int medicine_count[], int status[])
{
  char choose_use_or_not = 'x';
  system("clear");

  while (true)
  {
    // call name and des directly by <food(x)> function
    cout << medicine(x).name << endl;
    cout << medicine(x).des << endl;
    printEffect(medicine(x));
    sleep(1);

    cout << "Do you want to use? (You have " << medicine_count[x] << ' ' << medicine(x).name << ")"<< endl;
    cout << "Y for use, other key to back" << endl;
    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' || choose_use_or_not == 'y')
    {
      if (medicine_count[x] > 0)
      {
        sleep(1);
        cout << medicine(x).name << " used!" << endl;
        medicine_count[x] -= 1;
        status[0] += medicine(x).effect[0]; // directly use <medicine(x).effect>
        status[3] += medicine(x).effect[3];
        sleep(1);
        system("clear");
        // stop the loop and end this function
        break;
      }// if user choose sth they don have --> let them choose again by looping
      else
      {
        cout << "You do not have it!" << endl;
        sleep(1);
        cout << "Please choose something that you HAVE!" << endl;
        sleep(1);
        system("clear");
        // back to menu
        return;
      }
    }
    cout << "Back to the menu!" << endl;
    sleep(1);
    system("clear");
    return;
  }
}

// Function: show details of food items but NOT allow player to use items
// Input: int x: item index
//        int weapon_count[]: quanity of weapon item
//        int status[]: player status
void use_weapon(int x, int weapon_count[], int status[])
{
  char choose_use_or_not = 'x';
  system("clear");

  while (true)
  {
    // call name and des directly by <food(x)> function
    cout << weapon(x).name << endl;
    cout << weapon(x).des << endl;
    printEffect(weapon(x));
    sleep(1);

    cout << "You have " << weapon_count[x] << ' ' << weapon(x).name << endl;
    cout << "Press any key to back" << endl;
    cin >> choose_use_or_not;
    break;
  }
  cout << "Back to the menu!" << endl;
  sleep(1);
  system("clear");
}

// Function: show details of mystery items and allow player to use selected items
// Input: int x: item index
//        int other_count[]: quanity of mystery item
//        int status[]: player status
void use_other(int x, int other_count[], int status[])
{
  char choose_use_or_not = 'x';
  system("clear");

  while (true)
  {
    // call name and des directly by <food(x)> function
    cout << mystery(x).name << endl;
    cout << mystery(x).des << endl;
    printEffect(mystery(x));
    sleep(1);

    cout << "Do you want to use? (You have " << other_count[x] << ' ' << mystery(x).name << ")"<< endl;
    cout << "Y for use, other key to back" << endl;
    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' || choose_use_or_not == 'y')
    {
      if (other_count[x] > 0)
      {
        sleep(1);
        cout << mystery(x).name << " used!" << endl;
        other_count[x] -= 1;
        status[3] += mystery(x).effect[3]; // directly use <medicine(x).effect>
        sleep(1);
        system("clear");
        // stop the loop and end this function
        break;
      }// if user choose sth they don have --> let them choose again by looping
      else
      {
        cout << "You do not have it!" << endl;
        sleep(1);
        cout << "Please choose something that you HAVE!" << endl;
        sleep(1);
        system("clear");
        return;
      }
    }
    cout << "Back to the menu!" << endl;
    sleep(1);
    system("clear");
    return;
  }
}

// Function: print out the menu of all water items including item quanity
// Input: int water_count[]: quanity of water item
//        int status[]: player status
void water_menu(int water_count[], int status[])
{
  int choice_in_useitem = 0;
  cout << "Water Menu" << endl;
  cout << "1. " << setw(13) << left << water(0).name << water_count[0] << endl;  // Clean Water
  cout << "2. " << setw(13) << left << water(1).name << water_count[1] << endl;  // Soda
  cout << "3. " << setw(13) << left << water(2).name << water_count[2] << endl;  // Pee
  cout << "4. " << setw(13) << left << water(3).name << water_count[3] << endl;  // Cocunut
  cout << "5. " << setw(13) << left << water(4).name << water_count[4] << endl;  // Dirty Water
  cout << "6. Back " << endl;

  //ensure that only with input 1-5 will proceed to next stage

  while (choice_in_useitem > 6 || choice_in_useitem < 1)
  {
    cout << "Which one do you want to choose?" << endl;
    cin >> choice_in_useitem;
    if (choice_in_useitem > 5 + 1 || choice_in_useitem < 1)
    {
      cout << "Invaild input, please input again!" << endl;
    }
  }
  if (choice_in_useitem != 5 + 1)
  {
    use_water(choice_in_useitem - 1, water_count, status);
    water_menu(water_count, status);
  }
  else
  {
    return;
  }
}

// Function: print out the menu of all food items including item quanity
// Input: int food_count[]: quanity of food item
//        int status[]: player status
void food_menu(int food_count[], int status[])
{
  int choice_in_useitem = 0;
  cout << "Food Menu" << endl;
  cout << "1. " << setw(18) << left << food(0).name << food_count[0] << endl;  // Energy Bar
  cout << "2. " << setw(18) << left << food(1).name << food_count[1] << endl;  // Meat
  cout << "3. " << setw(18) << left << food(2).name << food_count[2] << endl;  // Wild Berry
  cout << "4. " << setw(18) << left << food(3).name << food_count[3] << endl;  // Worm
  cout << "5. " << setw(18) << left << food(4).name << food_count[4] << endl;  // Unknown Mushroom
  cout << "6. Back " << endl;

  //ensure that only with input 1-5 will proceed to next stage

  while (choice_in_useitem > 6 || choice_in_useitem < 1)
  {
    cout << "Which one do you want to choose?" << endl;
    cin >> choice_in_useitem;
    if (choice_in_useitem > 5 + 1 || choice_in_useitem < 1)
    {
      cout << "Invaild input, please input again!" << endl;
    }
  }
  if (choice_in_useitem != 5 + 1)
  {
    use_food(choice_in_useitem - 1, food_count, status);
    food_menu(food_count, status);
  }
  else
  {
    return;
  }
}

// Function: print out the menu of all medicine items including item quanity
// Input: int medicine_count[]: quanity of medicine item
//        int status[]: player status
void medicine_menu(int medicine_count[], int status[])
{
  int choice_in_useitem = 0;
  cout << "Medicine Menu" << endl;
  cout << "1. " << setw(15) << left << medicine(0).name << medicine_count[0] << endl;  // Herb
  cout << "2. " << setw(15) << left << medicine(1).name << medicine_count[1] << endl;  // Pill
  cout << "3. " << setw(15) << left << medicine(2).name << medicine_count[2] << endl;  // Bandage
  cout << "4. " << setw(15) << left << medicine(3).name << medicine_count[3] << endl;  // First Aid Kit
  cout << "5. " << setw(15) << left << medicine(4).name << medicine_count[4] << endl;  // Sedative
  cout << "6. Back " << endl;

  //ensure that only with input 1-5 will proceed to next stage

  while (choice_in_useitem > 6 || choice_in_useitem < 1)
  {
    cout << "Which one do you want to choose?" << endl;
    cin >> choice_in_useitem;
    if (choice_in_useitem > 5 + 1 || choice_in_useitem < 1)
    {
      cout << "Invaild input, please input again!" << endl;
    }
  }
  if (choice_in_useitem != 5 + 1)
  {
    use_medicine(choice_in_useitem - 1, medicine_count, status);
    medicine_menu(medicine_count, status);
  }
  else
  {
    return;
  }
}

// Function: print out the menu of all weapon items including item quanity
// Input: int weapon_count[]: quanity of weapon item
//        int status[]: player status
void weapon_menu(int weapon_count[], int status[])
{
  int choice_in_useitem = 0;
  cout << "Weapon Menu" << endl;
  cout << "1. " << setw(14) << left << weapon(0).name << weapon_count[0] << endl;  // Wooden Stick
  cout << "2. " << setw(14) << left << weapon(1).name << weapon_count[1] << endl;  // Rock
  cout << "3. " << setw(14) << left << weapon(2).name << weapon_count[2] << endl;  // Knife
  cout << "4. " << setw(14) << left << weapon(3).name << weapon_count[3] << endl;  // Spear
  cout << "5. Back " << endl;

  //ensure that only with input 1-5 will proceed to next stage

  while (choice_in_useitem > 5 || choice_in_useitem < 1)
  {
    cout << "Weapon can only be used in fight." << endl;
    cout << "Which one do you want to see?" << endl;
    cin >> choice_in_useitem;
    if (choice_in_useitem > 4 + 1 || choice_in_useitem < 1)
    {
      cout << "Invaild input, please input again!" << endl;
    }
  }
  if (choice_in_useitem != 4 + 1)
  {
    use_weapon(choice_in_useitem - 1, weapon_count, status);
    weapon_menu(weapon_count, status);
  }
  else
  {
    return;
  }
}

// Function: print out the menu of all mystery items including item quanity
// Input: int other_count[]: quanity of mystery item
//        int status[]: player status
void other_menu(int other_count[], int status[])
{
  int choice_in_useitem = 0;
  cout << "Other Items Menu" << endl;
  cout << "1. " << setw(23) << left << mystery(0).name << other_count[0] << endl;  // Leaf
  cout << "2. " << setw(23) << left << mystery(1).name << other_count[1] << endl;  // Newspaper
  cout << "3. " << setw(23) << left << mystery(2).name << other_count[2] << endl;  // Wilson the Volleyball
  cout << "4. " << setw(23) << left << mystery(3).name << other_count[3] << endl;  // Flashlight
  cout << "5. " << setw(23) << left << mystery(4).name << other_count[4] << endl;  // Gameboy
  cout << "6. " << setw(23) << left << mystery(5).name << other_count[5] << endl;  // Seashell
  cout << "7. Back " << endl;

  //ensure that only with input 1-5 will proceed to next stage

  while (choice_in_useitem > 7 || choice_in_useitem < 1)
  {
    cout << "Which one do you want to choose?" << endl;
    cin >> choice_in_useitem;
    if (choice_in_useitem > 6 + 1 || choice_in_useitem < 1)
    {
      cout << "Invaild input, please input again!" << endl;
    }
  }
  if (choice_in_useitem != 6 + 1)
  {
    use_other(choice_in_useitem - 1, other_count, status);
    other_menu(other_count, status);
  }
  else
  {
    return;
  }
}

// Funtion: print out the main item menu for different item catagory
// Input: int status[]: player status
//        int water_count[]: quantity of water items
//        int food_count[]: quantity of food items
//        int medicine_count[]: quantity of medicine items
//        int weapon_count[]: quantity of weapon items
//        int other_count[]: quantity of other items
void item_menu(int status[], int water_count[], int food_count[], int medicine_count[], int weapon_count[], int other_count[])
{
  // clear the page first to make tidier
  system("clear");
  int choice_in_mainmeun = 0;
  // printing out the meun for player to choose
  cout << "Item Pack" << endl;
  cout << "1. Water" << endl;
  cout << "2. Food " << endl;
  cout << "3. Medicine" << endl;
  cout << "4. Weapon" << endl;
  cout << "5. Other" << endl;
  cout << "6. Quit" << endl;

  //ensure that only with input 1-6 will proceed to next stage
  while (choice_in_mainmeun > 6 || choice_in_mainmeun < 1)
  {
    cout << "Which one do you want to choose?" << endl;
    cin >> choice_in_mainmeun;
    if (choice_in_mainmeun > 6 || choice_in_mainmeun < 1)
    {
    cout << "Invaild input, please input again!" << endl;
    }
  }
  system("clear");

  if (choice_in_mainmeun == 1)
    water_menu(water_count, status);
  if (choice_in_mainmeun == 2)
    food_menu(food_count, status);
  if (choice_in_mainmeun == 3)
    medicine_menu(medicine_count, status);
  if (choice_in_mainmeun == 4)
    weapon_menu(weapon_count, status);
  if (choice_in_mainmeun == 5)
    other_menu(other_count, status);
  if (choice_in_mainmeun == 6)
    return;

  // set the upper limit of the status to 100
  for (int i = 0; i < 4; i++) {
    if (status[i] > 100) {
      status[i] = 100;
    }
  }

  // exicute the function again for user to continue choosing untill they choose quit
  item_menu(status, water_count, food_count, medicine_count ,weapon_count ,other_count);
}

