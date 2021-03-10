# include <iostream>
# include <string>
# include "data_items.h"

using namespace std;

void item_menu();
void water_menu();
void food_menu();
void use_water(int x);
void use_food(int x);

int cleanwater_number = 0, soda_number = 0, pee_number = 0, coconut_number = 0, dirtywater_number = 0;
int meat_number = 0, wildberry_number = 0, worm_number = 0, mushroom_number = 0, energybar_number = 0;

void use_water(int x)
{
  cout << "used" << endl;
  return water_menu();
}

void use_food(int x)
{

}

// item_menu() printing the main item menu
void item_menu()
{
  int choice_in_mainmeun = 0;
  //int cleanwater_number = 0, soda_number = 0, pee_number = 0, coconut_number = 0, dirtywater = 0;
  // printing out the meun for player to choose
  cout << "Item Pack" << endl;
  cout << "1. Water" << endl;
  cout << "2. Food " << endl;
  cout << "3. Medicine" << endl;
  cout << "4. Weapon" << endl;
  cout << "5. Other" << endl;
  cout << "6. Quit" << endl;

  //ensure that only with input 1-5 will proceed to next stage
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

}

//printing water_menu, include number of card the player had and allow to proceed to use
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
    if (choice_in_useitem != 6)
    {
      use_water(choice_in_useitem);
    }
    else
    {
      return item_menu();
    }
  }
}
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
    if (choice_in_useitem != 6)
    {
      use_food(choice_in_useitem);
    }
    else
    {
      return item_menu();
    }
  }
}

int main()
{
  item_menu();
}
