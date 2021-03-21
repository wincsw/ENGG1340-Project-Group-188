// item_pack.cpp
// item_menu(water_count, food_count, medicine_count ,weapon_count ,other_count) to call menu
// printing item pack and allow using the items
# include <iostream>
# include <string>
# include <stdlib.h>     // allow to use system ("clear")
# include <unistd.h>     // allow to use sleep()
# include "data_items.h"
# include "structures.h"
# include "player_status.h"

using namespace std;
/* just for test
const int water_num = 5;
const int food_num = 5;
const int medicine_num = 5;
const int weapon_num = 4;
const int mystery_num = 6;
*/

// call all the function at the beginning
void item_menu(int water_count[], int food_count[], int medicine_count[], int weapon_count[], int other_count[]);
void water_menu();
void food_menu();
void medicine_menu();
void weapon_menu();
void other_menu();
void use_water(int x);
void use_food(int x);
void use_medicine(int x);
void use_weapon(int x);
void use_other(int x);
void printEffect(struct item object);

// use arrays to store numbers of items
// NOTE: this is tempory --> the official one should be in main.cpp
int water_count[5] = {1};
int food_count[5] = {1};
int medicine_count[5] = {1};
int weapon_count[4] = {1};
int other_count[6] = {1};

// print the effect of the item
void printEffect(struct item object)
{
  string status[] = {"HP", "Hydration", "Hunger", "Mentality", "ATK"};
  int empty[] = {0, 0, 0, 0, 0};

  if (object.effect == empty) {
    cout << "USELESS" << endl;
  }
  else {
    for (int i = 0; i < 4; i++) {
      char sign;
      if (object.effect[i] > 0) {
        sign = '+';
      }
      else if (object.effect[i] < 0) {
        sign = '-';
      }
      else {
        continue;
      }
      cout << sign << object.effect[i] << " " << status[i] << endl;
    }
  }
}

// show details about the items and allow to use the selected items
void use_water(int x)
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
        temp_status[0] += water(x).effect[0]; // directly use <water(x).effect>
        temp_status[1] += water(x).effect[1];
        temp_status[3] += water(x).effect[3];
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
        water_menu();
        cin >> x;
        continue;
      }
    }
  // if input is not 'y' or 'Y':
    cout << "Back to the menu!" << endl;
    sleep(1);
    system("clear");
    // back to menu
    water_menu();
  }
}


void use_food(int x)
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
        temp_status[0] += food(x).effect[0]; // directly use <water(x).effect>
        temp_status[2] += food(x).effect[2];
        temp_status[3] += food(x).effect[3];
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
        food_menu();
        cin >> x;
        continue;
      }
    }
    cout << "Back to the menu!" << endl;
    sleep(1);
    system("clear");
    // back to menu
    food_menu();
  }
}

void use_medicine(int x)
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
        temp_status[0] += medicine(x).effect[0]; // directly use <medicine(x).effect>
        temp_status[3] += medicine(x).effect[3];
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
        medicine_menu();
        cin >> x;
        continue;
      }
    }
    cout << "Back to the menu!" << endl;
    sleep(1);
    system("clear");
    medicine_menu();
  }
}

void use_weapon(int x)
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
    cout << "key to back" << endl;
    cin >> choose_use_or_not;
    break;
  }
  cout << "Back to the menu!" << endl;
  sleep(1);
  system("clear");
}

void use_other(int x)
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
        temp_status[3] += mystery(x).effect[3]; // directly use <medicine(x).effect>
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
        other_menu();
        cin >> x;
        continue;
      }
    }
    cout << "Back to the menu!" << endl;
    sleep(1);
    system("clear");
    other_menu();
  }
}

void water_menu()
{
  int choice_in_useitem = 0;
  cout << "Water Menu" << endl;
  cout << "1. " << water(0).name << ": " << water_count[0] << endl;  // Clean Water
  cout << "2. " << water(1).name << ": " << water_count[1] << endl;  // Soda
  cout << "3. " << water(2).name << ": " << water_count[2] << endl;  // Pee
  cout << "4. " << water(3).name << ": " << water_count[3] << endl;  // Cocunut
  cout << "5. " << water(4).name << ": " << water_count[4] << endl;  // Dirty Water
  cout << "6. Back " << endl;

  //ensure that only with input 1-5 will proceed to next stage

  while (choice_in_useitem > 6 | choice_in_useitem < 1)
  {
    cout << "Which one do you want to choose?" << endl;
    cin >> choice_in_useitem;
    if (choice_in_useitem > water_num + 1 || choice_in_useitem < 1)
    {
      cout << "Invaild input, please input again!" << endl;
    }
  }
  if (choice_in_useitem != water_num + 1)
  {
    use_water(choice_in_useitem - 1);
    water_menu();
  }
  else
  {
  item_menu(water_count, food_count, medicine_count ,weapon_count ,other_count);
  }
}

//printing fooditem_menu, include number of card the player had and allow to proceed to use
void food_menu()
{
  int choice_in_useitem = 0;
  cout << "Food Menu" << endl;
  cout << "1. " << food(0).name << ": " << food_count[0] << endl;  // Energy Bar
  cout << "2. " << food(1).name << ": " << food_count[1] << endl;  // Meat
  cout << "3. " << food(2).name << ": " << food_count[2] << endl;  // Wild Berry
  cout << "4. " << food(3).name << ": " << food_count[3] << endl;  // Worm
  cout << "5. " << food(4).name << ": " << food_count[4] << endl;  // Unknown Mushroom
  cout << "6. Back " << endl;

  //ensure that only with input 1-5 will proceed to next stage

  while (choice_in_useitem > 6 | choice_in_useitem < 1)
  {
    cout << "Which one do you want to choose?" << endl;
    cin >> choice_in_useitem;
    if (choice_in_useitem > food_num + 1 || choice_in_useitem < 1)
    {
      cout << "Invaild input, please input again!" << endl;
    }
  }
  if (choice_in_useitem != food_num + 1)
  {
    use_food(choice_in_useitem - 1);
    food_menu();
  }
  else
  {
    item_menu(water_count, food_count, medicine_count ,weapon_count ,other_count);
  }
}

//printing medicineitem_menu, include number of card the player had and allow to proceed to use
void medicine_menu()
{
  int choice_in_useitem = 0;
  cout << "Medicine Menu" << endl;
  cout << "1. " << medicine(0).name << ": " << medicine_count[0] << endl;  // Herb
  cout << "2. " << medicine(1).name << ": " << medicine_count[1] << endl;  // Pill
  cout << "3. " << medicine(2).name << ": " << medicine_count[2] << endl;  // Bandage
  cout << "4. " << medicine(3).name << ": " << medicine_count[3] << endl;  // First Aid Kit
  cout << "5. " << medicine(4).name << ": " << medicine_count[4] << endl;  // Sedative
  cout << "6. Back " << endl;

  //ensure that only with input 1-5 will proceed to next stage

  while (choice_in_useitem > 6 | choice_in_useitem < 1)
  {
    cout << "Which one do you want to choose?" << endl;
    cin >> choice_in_useitem;
    if (choice_in_useitem > medicine_num + 1 || choice_in_useitem < 1)
    {
      cout << "Invaild input, please input again!" << endl;
    }
  }
  if (choice_in_useitem != medicine_num + 1)
  {
    use_medicine(choice_in_useitem - 1);
    medicine_menu();
  }
  else
  {
    item_menu(water_count, food_count, medicine_count ,weapon_count ,other_count);
  }
}

//printing weapon item_menu, include number of card the player had and allow to proceed to use
void weapon_menu()
{
  int choice_in_useitem = 0;
  cout << "Weapon Menu" << endl;
  cout << "1. " << weapon(0).name << ": " << weapon_count[0] << endl;  // Wooden Stick
  cout << "2. " << weapon(1).name << ": " << weapon_count[1] << endl;  // Rock
  cout << "3. " << weapon(2).name << ": " << weapon_count[2] << endl;  // Knife
  cout << "4. " << weapon(3).name << ": " << weapon_count[3] << endl;  // Spear
  cout << "5. Back " << endl;

  //ensure that only with input 1-5 will proceed to next stage

  while (choice_in_useitem > 5 | choice_in_useitem < 1)
  {
    cout << "Weapon can only be used in fight." << endl;
    cout << "Which one do you want to see?" << endl;
    cin >> choice_in_useitem;
    if (choice_in_useitem > weapon_num + 1 || choice_in_useitem < 1)
    {
      cout << "Invaild input, please input again!" << endl;
    }
  }
  if (choice_in_useitem != weapon_num + 1)
  {
    use_weapon(choice_in_useitem - 1);
    weapon_menu();
  }
  else
  {
    item_menu(water_count, food_count, medicine_count ,weapon_count ,other_count);
  }
}

//printing otheritem_menu
void other_menu()
{
  int choice_in_useitem = 0;
  cout << "Other Items Menu" << endl;
  cout << "1. " << mystery(0).name << ": " << other_count[0] << endl;  // Leaf
  cout << "2. " << mystery(1).name << ": " << other_count[1] << endl;  // Newspaper
  cout << "3. " << mystery(2).name << ": " << other_count[2] << endl;  // Wilson the Volleyball
  cout << "4. " << mystery(3).name << ": " << other_count[3] << endl;  // Flashlight
  cout << "5. " << mystery(4).name << ": " << other_count[4] << endl;  // Gameboy
  cout << "6. " << mystery(5).name << ": " << other_count[5] << endl;  // Seashell
  cout << "7. Back " << endl;

  //ensure that only with input 1-5 will proceed to next stage

  while (choice_in_useitem > 7 | choice_in_useitem < 1)
  {
    cout << "Which one do you want to choose?" << endl;
    cin >> choice_in_useitem;
    if (choice_in_useitem > mystery_num + 1 || choice_in_useitem < 1)
    {
      cout << "Invaild input, please input again!" << endl;
    }
  }
  if (choice_in_useitem != mystery_num + 1)
  {
    use_other(choice_in_useitem - 1);
    other_menu();
  }
  else
  {
    item_menu(water_count, food_count, medicine_count ,weapon_count ,other_count);
  }
}

// item_menu() printing the main item menu
void item_menu(int water_count[], int food_count[], int medicine_count[], int weapon_count[], int other_count[])
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
  while (choice_in_mainmeun > 6 | choice_in_mainmeun < 1)
  {
    cout << "Which one do you want to choose?" << endl;
    cin >> choice_in_mainmeun;
    if (choice_in_mainmeun > 6 | choice_in_mainmeun < 1)
    {
    cout << "Invaild input, please input again!" << endl;
    }
  }
  system("clear");

  if (choice_in_mainmeun == 1)
    water_menu();
  if (choice_in_mainmeun == 2)
    food_menu();
  if (choice_in_mainmeun == 3)
    medicine_menu();
  if (choice_in_mainmeun == 4)
    weapon_menu();
  if (choice_in_mainmeun == 5)
    other_menu();

  // exicute the function again for user to continue choosing untill they choose quit
  item_menu(water_count, food_count, medicine_count ,weapon_count ,other_count);
}

