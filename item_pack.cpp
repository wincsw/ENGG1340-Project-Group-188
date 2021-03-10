// item_pack.cpp
// printing item pack and allow using the items
# include <iostream>
# include <string>
# include "data_items.h"

using namespace std;

void item_menu();
void water_menu();
void food_menu();
void medicine_menu();
void weapon_menu();
void other_menu();
void use(int list[], int x);

// set the variables of items
int water_item[5];
int food_item[5];
int medicine_item[5];
int weapon_item[4];
int other_item[6];

// deduct 1 after the item is used
void minus_item(int list[], int x)
{
  list[x - 1] -= 1;
}

// print the information of the item
void printItem(struct item object) 
{
  string status[] = {"HP", "Hydration", "Hunger", "Mentality", "ATK"};
  int empty[] = {0, 0, 0, 0, 0};
  cout << object.name << endl;

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
        sign = '\0';
      }
      else {
        continue;
      }
      cout << sign << object.effect[i] << " " << status[i] << endl;
    }
  }

  cout << object.des << endl;
}

// item_menu() printing the main item menu
void item_menu()
{
  int choice_in_mainmeun = 0;
  // printing out the meun for player to choose
  cout << "----------"  << endl << "Item Pack" << endl << endl;
  cout << "1. Water" << endl;
  cout << "2. Food " << endl;
  cout << "3. Medicine" << endl;
  cout << "4. Weapon" << endl;
  cout << "5. Other" << endl;
  cout << "6. Quit" << endl;

  //ensure that only with input 1-6 will proceed to next stage
  while (choice_in_mainmeun > 6 | choice_in_mainmeun < 1)
  {
    cout << endl;
    cout << "Which one do you want to choose? ";
    cin >> choice_in_mainmeun;
    if (choice_in_mainmeun > 6 | choice_in_mainmeun < 1)
    {
    cout << "Invaild input, please input again!" << endl;
    }
  }

  switch(choice_in_mainmeun) {
    case 1: 
      water_menu();
      item_menu();
      break;
    case 2:
      food_menu();
      item_menu();
      break;
    case 3: 
      medicine_menu();
      item_menu();
      break;
    case 4:
      weapon_menu();
      item_menu();
      break;
    case 5:
      other_menu();
      item_menu();
      break;
    //case 6:
     // break;
  }
}



//printing wateritem_menu, include number of card the player had and allow to proceed to use
void water_menu()
{
  cout << "----------" << endl << "Water" << endl << endl;
  int choice_in_useitem = 0;
  cout << "1. " << water(0).name << ": " << water_item[0] << endl;
  cout << "2. " << water(1).name << ": " << water_item[1] << endl;
  cout << "3. " << water(2).name << ": " << water_item[2] << endl;
  cout << "4. " << water(3).name << ": " << water_item[3] << endl;
  cout << "5. " << water(4).name << ": " << water_item[4] << endl;
  cout << "6. Back" << endl;

  //ensure that only with input 1-5 will proceed to next stage
  while (choice_in_useitem > 6 | choice_in_useitem < 1)
  {
    cout << endl;
    cout << "Which one do you want to choose? ";
    cin >> choice_in_useitem;
    if (choice_in_useitem > 6 | choice_in_useitem < 1)
    {
    cout << "Invaild input, please input again!" << endl;
    }
  }

  if (choice_in_useitem != 6)
  {
    char conferm;
    cout << endl;
    printItem(water(choice_in_useitem - 1));
    cout << endl;
    cout << "Are you sure to use " << water(choice_in_useitem - 1).name << " ? [y/n] ";
    cin >> conferm;
    if (conferm == 'y') {
      minus_item(water_item, choice_in_useitem );
      
    }
    else {
      water_menu();
    }
  }
  else
  {
    item_menu();
  }
}

//printing fooditem_menu, include number of card the player had and allow to proceed to use
void food_menu()
{
  cout << "----------" << endl << "Food" << endl << endl;
  int choice_in_useitem = 0;
  cout << "1. " << food(0).name << ": " << food_item[0] << endl;
  cout << "2. " << food(1).name << ": " << food_item[1] << endl;
  cout << "3. " << food(2).name << ": " << food_item[2] << endl;
  cout << "4. " << food(3).name << ": " << food_item[3] << endl;
  cout << "5. " << food(4).name << ": " << food_item[4] << endl;
  cout << "6. Back" << endl;

  //ensure that only with input 1-5 will proceed to next stage
  while (choice_in_useitem > 6 | choice_in_useitem < 1)
  {
    cout << "Which one do you want to choose?" << endl;
    cin >> choice_in_useitem;
    if (choice_in_useitem > 6 | choice_in_useitem < 1)
    {
    cout << "Invaild input, please input again!" << endl;
    }
  }

  if (choice_in_useitem != 6)
  {
    char conferm;
    cout << endl;
    printItem(food(choice_in_useitem - 1));
    cout << "Are you sure to use " << food(choice_in_useitem - 1).name << " ? [y/n] ";
    cin >> conferm;
    if (conferm == 'y') {
      minus_item(food_item, choice_in_useitem);
    }
    else {
      food_menu();
    }
  }
  else
  {
    item_menu();
  }
}

//printing medicineitem_menu, include number of card the player had and allow to proceed to use
void medicine_menu()
{
  cout << "----------" << endl << "Medicine" << endl << endl;
  int choice_in_useitem = 0;
  cout << "1. " << medicine(0).name << ": " << medicine_item[0] << endl;
  cout << "2. " << medicine(1).name << ": " << medicine_item[1] << endl;
  cout << "3. " << medicine(2).name << ": " << medicine_item[2] << endl;
  cout << "4. " << medicine(3).name << ": " << medicine_item[3] << endl;
  cout << "5. " << medicine(4).name << ": " << medicine_item[4] << endl;
  cout << "6. Back" << endl;

  //ensure that only with input 1-5 will proceed to next stage
  while (choice_in_useitem > 6 | choice_in_useitem < 1)
  {
    cout << endl;
    cout << "Which one do you want to choose?" << endl;
    cin >> choice_in_useitem;
    if (choice_in_useitem > 6 | choice_in_useitem < 1)
    {
    cout << "Invaild input, please input again!" << endl;
    }
  }

  if (choice_in_useitem != 6)
  {
    char conferm;
    cout << endl;
    printItem(medicine(choice_in_useitem - 1));
    cout << "Are you sure to use " << medicine(choice_in_useitem - 1).name << " ? [y/n] ";
    cin >> conferm;
    if (conferm == 'y') {
      minus_item(medicine_item, choice_in_useitem);

    }
    else {
      medicine_menu();
    }
  }
  else
  {
    item_menu();
  }
}

//printing weapon item_menu, include number of card the player had and allow to proceed to use
void weapon_menu()
{
  cout << "----------" << endl << "Weapon" << endl << endl;
  int choice_in_useitem = 0;
  cout << "Water" << endl;
  cout << "1. " << weapon(0).name << ": " << weapon_item[0] << endl;
  cout << "2. " << weapon(1).name << ": " << weapon_item[1] << endl;
  cout << "3. " << weapon(2).name << ": " << weapon_item[2]<< endl;
  cout << "4. " << weapon(3).name << ": " << weapon_item[3] << endl;
  cout << "5. Back" << endl;
  cout << "You can only use the weapon during fight!"<<
           "But you can see the description of it" << endl;

  //ensure that only with input 1-5 will proceed to next stage
  while (choice_in_useitem > 5 | choice_in_useitem < 1)
  {
    cout << "Which one do you want to choose?" << endl;
    cin >> choice_in_useitem;
    if (choice_in_useitem > 5 | choice_in_useitem < 1)
    {
    cout << "Invaild input, please input again!" << endl;
    }
  }

  if (choice_in_useitem != 5)
  {
    char conferm;
    cout << endl;
    printItem(water(choice_in_useitem - 1));
    cout << "Back to category [y/n] ";
    cin >> conferm;
    if (conferm == 'y') {
      minus_item(weapon_item, choice_in_useitem);
    }
    else {
      weapon_menu();
    }
  }
  else
  {
    return item_menu();
  }
}

//printing otheritem_menu
void other_menu()
{
  cout << "----------" << endl << "Other" << endl << endl;
  int choice_in_useitem = 0;
  cout << "1. " << mystery(0).name << ": " << other_item[0] << endl;
  cout << "2. " << mystery(1).name << ": " << other_item[1] << endl;
  cout << "3. " << mystery(2).name << ": " << other_item[2] << endl;
  cout << "4. " << mystery(3).name << ": " << other_item[3] << endl;
  cout << "5. " << mystery(4).name << ": " << other_item[4] << endl;
  cout << "6. " << mystery(5).name << ": " << other_item[5] << endl;
  cout << "7. Back" << endl;

  //ensure that only with input 1-7 will proceed to next stage
  while (choice_in_useitem > 7 | choice_in_useitem < 1)
  {
    cout << "Which one do you want to choose?" << endl;
    cin >> choice_in_useitem;
    if (choice_in_useitem > 7 | choice_in_useitem < 1)
    {
    cout << "Invaild input, please input again!" << endl;
    }
  }

  if (choice_in_useitem != 7)
  {
    char conferm;
    cout << endl;
    printItem(mystery(choice_in_useitem - 1));
    cout << "Are you sure to use " << mystery(choice_in_useitem - 1).name << " ? [y/n] ";
    cin >> conferm;
    if (conferm == 'y') {
      minus_item(other_item, choice_in_useitem);
    }
    else {
      other_menu();
    }
  }
  else
  {
    item_menu();
  }
}

int main()
{
  item_menu();
}
