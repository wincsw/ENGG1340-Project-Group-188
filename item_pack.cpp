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
void use_water(int x);
void use_food(int x);
void use_medicine(int x);
void use_weapon(int x);
void use_other(int x);

// set the variables of items
int cleanwater_number = 0, soda_number = 0, pee_number = 0, coconut_number = 0, dirtywater_number = 0;
int meat_number = 0, wildberry_number = 0, worm_number = 0, mushroom_number = 0, energybar_number = 0;
int herb_number = 0, pill_number = 0, bandage_number = 0, firstaidkit_number = 0, sedative_number = 0;
int woodenstick_number = 0, rock_number = 0, knife_number = 0, spear_number = 0;
int WilsontheVolleyball_number = 0, Newspaper_number = 0, Leaf_number = 0, Flashlight_number = 0, Gameboy_number = 0, Shell_number = 0;

void use_water(int x)
{
  return water_menu();
}

void use_food(int x)
{
  return food_menu();
}

void use_medicine(int x)
{
  return medicine_menu();
}

void use_weapon(int x)
{
  return weapon_menu();
}

void use_other(int x)
{
  return other_menu();
}

// item_menu() printing the main item menu
void item_menu()
{
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

  if (choice_in_mainmeun == 1)  water_menu();
  if (choice_in_mainmeun == 2)  food_menu();
  if (choice_in_mainmeun == 3)  medicine_menu();
  if (choice_in_mainmeun == 4)  weapon_menu();
  if (choice_in_mainmeun == 5)  other_menu();
}

//printing wateritem_menu, include number of card the player had and allow to proceed to use
void water_menu()
{
  int choice_in_useitem = 0;
  cout << "1. Clean Water: " << cleanwater_number << endl;
  cout << "2. Soda: " << soda_number << endl;
  cout << "3. Pee: " << pee_number << endl;
  cout << "4. Coconut: " << coconut_number << endl;
  cout << "5. Dirty water: " << dirtywater_number << endl;
  cout << "6. Back: " << endl;

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
    use_water(choice_in_useitem);
  }
  else
  {
    return item_menu();
  }
}

//printing fooditem_menu, include number of card the player had and allow to proceed to use
void food_menu()
{
  int choice_in_useitem = 0;
  cout << "1. Meat: " << meat_number << endl;
  cout << "2. Wild Berry: " << wildberry_number << endl;
  cout << "3. Worm: " << worm_number<< endl;
  cout << "4. Unknown Mushroom: " << mushroom_number << endl;
  cout << "5. Energy Bar: " << energybar_number << endl;
  cout << "6. Back: " << endl;

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
    use_food(choice_in_useitem);
  }
  else
  {
    return item_menu();
  }
}

//printing medicineitem_menu, include number of card the player had and allow to proceed to use
void medicine_menu()
{
  int choice_in_useitem = 0;
  cout << "1. Herb: " << herb_number << endl;
  cout << "2. Pill: " << pill_number << endl;
  cout << "3. Bandage: " << bandage_number<< endl;
  cout << "4. First Aid Kit: " << firstaidkit_number << endl;
  cout << "5. Sedative: " << sedative_number << endl;
  cout << "6. Back: " << endl;

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
    use_medicine(choice_in_useitem);
  }
  else
  {
    return item_menu();
  }
}

//printing weapon item_menu, include number of card the player had and allow to proceed to use
void weapon_menu()
{
  int choice_in_useitem = 0;
  cout << "1. Wooden Stick: " << woodenstick_number << endl;
  cout << "2. Rock: " << rock_number << endl;
  cout << "3. Knife: " << knife_number<< endl;
  cout << "4. Spear: " << spear_number << endl;
  cout << "5. Back: " << endl;
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
    use_weapon(choice_in_useitem);
  }
  else
  {
    return item_menu();
  }
}

//printing otheritem_menu
void other_menu()
{
  int choice_in_useitem = 0;
  cout << "1. Wilson the Volleyball: " << WilsontheVolleyball_number << endl;
  cout << "2. Newspaper: " << Newspaper_number << endl;
  cout << "3. Leaf: " << Leaf_number << endl;
  cout << "4. Flashlight: " << Flashlight_number << endl;
  cout << "5. Gameboy: " << Gameboy_number << endl;
  cout << "6. Shell: " << Shell_number << endl;
  cout << "7. Back: " << endl;

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
    use_other(choice_in_useitem);
  }
  else
  {
    return item_menu();
  }
}

int main()
{
  item_menu();
}

