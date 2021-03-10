// item_pack.cpp
// printing item pack and allow using the items
// item_menu() can used to trigger all function
# include <iostream>
# include <string>
# include <stdlib.h>     // allow to use system ("clean")
# include <unistd.h>     // allow to use sleep()
# include "data_items.h"
# include "structures.h"
# include "player_status.h"

using namespace std;

// call all the function at the beginning
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
int WilsontheVolleyball_number = 0, Newspaper_number = 0, Leaf_number = 0, Flashlight_number = 0, Gameboy_number = 0, Seashell_number = 0;

//extract datas from data_items.cpp for water
struct item clean_water = water(0);
struct item soda = water(1);
struct item pee = water(2);
struct item coconut = water(3);
struct item dirty_water = water(4);

//extract datas from data_items.cpp for food
struct item meat = food(1);
struct item wildberry = food(2);
struct item worm = food(3);
struct item unknown_mushroom = food(4);
struct item energy_bar = food(0);

//extract datas from data_items.cpp for medicine
struct item herb = medicine(0);
struct item pill = medicine(1);
struct item bandage = medicine(2);
struct item first_aid_kit = medicine(3);
struct item sedative = medicine(4);

//extract datas from data_items.cpp for weapon
struct item wooden_stick = weapon(0);
struct item rock = weapon(1);
struct item knife = weapon(2);
struct item spear = weapon(3);

//extract datas from data_items.cpp for mystery item (others)
struct item leaf = mystery(0);
struct item newspaper = mystery(1);
struct item wilson_the_volleyball = mystery(2);
struct item flashlight = mystery(3);
struct item gameboy = mystery(4);
struct item seashell = mystery(5);

// call from player_status.cpp
//int temp_status[4];
// show details about the items and allow to use the selected items
void use_water(int x)
{
  char choose_use_or_not = 'x';
  switch (x)
  {
    case 1:
    system("clear");
    cout << clean_water.name << endl;
    cout << clean_water.des << endl;
    cout << "Effect: Hydration + 10" << endl;
    cout << "Do you want to use? (You have " << cleanwater_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (cleanwater_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        cleanwater_number -= 1;
        temp_status[1] += 10;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 2:
    system("clear");
    cout << soda.name << endl;
    cout << soda.des << endl;
    cout << "Effect: Hydration + 5 , Mental + 5" << endl;
    cout << "Do you want to use? (You have " << soda_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (soda_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        soda_number -= 1;
        temp_status[1] += 5;
        temp_status[3] += 5;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 3:
    system("clear");
    cout << pee.name << endl;
    cout << pee.des << endl;
    cout << "Effect: Hydration + 5 , Mental - 5" << endl;
    cout << "Do you want to use? (You have " << pee_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (pee_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        pee_number -= 1;
        temp_status[1] += 5;
        temp_status[3] -=5;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 4:
    system("clear");
    cout << coconut.name << endl;
    cout << coconut.des << endl;
    cout << "Effect: Hydration + 10" << endl;
    cout << "Do you want to use? (You have " << coconut_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (coconut_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        coconut_number -= 1;
        temp_status[1] += 10;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 5:
    system("clear");
    cout << dirty_water.name << endl;
    cout << dirty_water.des << endl;
    cout << "Effect: Hydration + 5 , HP - 5" << endl;
    cout << "Do you want to use? (You have " << dirtywater_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (dirtywater_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        dirtywater_number -= 1;
        temp_status[1] += 5;
        temp_status[0] -= 5;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 6:
    return item_menu();
    break;

  }
  cout << "Back to the menu!" << endl;
  sleep(1);
  system("clear");
  return water_menu();
}


void use_food(int x)
{
  char choose_use_or_not = 'x';
  switch (x)
  {
    case 1:
    system("clear");
    cout << meat.name << endl;
    cout << meat.des << endl;
    cout << "Effect: Hunger + 10" << endl;
    cout << "Do you want to use? (You have " << meat_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (meat_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        meat_number -= 1;
        temp_status[2] += 10;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 2:
    system("clear");
    cout << wildberry.name << endl;
    cout << wildberry.des << endl;
    cout << "Effect: Hunger + 5" << endl;
    cout << "Do you want to use? (You have " << wildberry_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (wildberry_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        wildberry_number -= 1;
        temp_status[2] += 5;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 3:
    system("clear");
    cout << worm.name << endl;
    cout << worm.des << endl;
    cout << "Effect: Hunger + 10 , Mental - 10" << endl;
    cout << "Do you want to use? (You have " << worm_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (worm_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        worm_number -= 1;
        temp_status[2] += 10;
        temp_status[3] += 10;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 4:
    system("clear");
    cout << unknown_mushroom.name << endl;
    cout << unknown_mushroom.des << endl;
    cout << "Effect: Hunger + 5 , HP - 5" << endl;
    cout << "Do you want to use? (You have " << mushroom_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (mushroom_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        mushroom_number -= 1;
        temp_status[2] += 5;
        temp_status[0] -= 5;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 5:
    system("clear");
    cout << energy_bar.name << endl;
    cout << energy_bar.des << endl;
    cout << "Effect: Hunger + 10" << endl;
    cout << "Do you want to use? (You have " << energybar_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (energybar_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        energybar_number -= 1;
        temp_status[2] += 10;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 6:
    return item_menu();
  }
  cout << "Back to the menu!" << endl;
  sleep(1);
  system("clear");
  return food_menu();
}

void use_medicine(int x)
{
  char choose_use_or_not = 'x';
  switch (x)
  {
    case 1:
    system("clear");
    cout << herb.name << endl;
    cout << herb.des << endl;
    cout << "Effect: HP + 5" << endl;
    cout << "Do you want to use? (You have " << herb_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (herb_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        herb_number -= 1;
        temp_status[0] += 5;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 2:
    system("clear");
    cout << pill.name << endl;
    cout << pill.des << endl;
    cout << "Effect: HP + 5" << endl;
    cout << "Do you want to use? (You have " << pill_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (pill_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        pill_number -= 1;
        temp_status[0] += 10;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 3:
    system("clear");
    cout << bandage.name << endl;
    cout << bandage.des << endl;
    cout << "Effect: HP + 15" << endl;
    cout << "Do you want to use? (You have " << bandage_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (bandage_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        bandage_number -= 1;
        temp_status[0] += 15;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 4:
    system("clear");
    cout << first_aid_kit.name << endl;
    cout << first_aid_kit.des << endl;
    cout << "Effect: HP + 50" << endl;
    cout << "Do you want to use? (You have " << firstaidkit_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (firstaidkit_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        firstaidkit_number -= 1;
        temp_status[0] += 50;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 5:
    system("clear");
    cout << sedative.name << endl;
    cout << sedative.des << endl;
    cout << "Effect: mental" << endl;
    cout << "Do you want to use? (You have " << sedative_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (sedative_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        sedative_number -= 1;
        temp_status[3] += 20;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 6:
    return item_menu();
  }
  cout << "Back to the menu!" << endl;
  sleep(1);
  system("clear");
  return medicine_menu();
}

void use_weapon(int x)
{
  char choose_use_or_not = 'x';
  switch (x)
  {
    case 1:
    system("clear");
    cout << wooden_stick.name << endl;
    cout << wooden_stick.des << endl;
    cout << "Effect: ATK = 5" << endl;
    cout << "You have " << woodenstick_number << endl;
    cout << "Enter any key to back" << endl;

    // allow the other to choose when to leave
    cin >> choose_use_or_not;

    break;

    case 2:
    system("clear");
    cout << rock.name << endl;
    cout << rock.des << endl;
    cout << "Effect: ATK = 15" << endl;
    cout << "You have " << rock_number << endl;
    cout << "Enter any key to back" << endl;

    // allow the other to choose when to leave
    cin >> choose_use_or_not;

    break;

    case 3:
    system("clear");
    cout << knife.name << endl;
    cout << knife.des << endl;
    cout << "Effect: ATK = 15" << endl;
    cout << "You have " << knife_number << endl;
    cout << "Enter any key to back" << endl;

    // allow the other to choose when to leave
    cin >> choose_use_or_not;

    break;

    case 4:
    system("clear");
    cout << spear.name << endl;
    cout << spear.des << endl;
    cout << "Effect: ATK : 20" << endl;
    cout << "You have " << spear_number << endl;
    cout << "Enter any key to back" << endl;

    // allow the other to choose when to leave
    cin >> choose_use_or_not;

    break;

    case 5:
    return item_menu();
  }
  system("clear");
  return weapon_menu();
}

void use_other(int x)
{
  char choose_use_or_not = 'x';
  switch (x)
  {
    case 1:
    system("clear");
    cout << wilson_the_volleyball.name << endl;
    cout << wilson_the_volleyball.des << endl;
    cout << "Effect: Mental + 5" << endl;
    cout << "Do you want to use? (You have " << WilsontheVolleyball_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (WilsontheVolleyball_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        WilsontheVolleyball_number -= 1;
        temp_status[3] += 5;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 2:
    system("clear");
    cout << newspaper.name << endl;
    cout << newspaper.des << endl;
    cout << "Effect: No use" << endl;
    cout << "You have " << Newspaper_number << endl;
    cout << "Enter any key to back" << endl;

    cin >> choose_use_or_not;

    break;

    case 3:
    system("clear");
    cout << leaf.name << endl;
    cout << leaf.des << endl;
    cout << "Effect: No use" << endl;
    cout << "You have " << Leaf_number << endl;
    cout << "Enter any key to back" << endl;

    cin >> choose_use_or_not;
    break;

    case 4:
    system("clear");
    cout << flashlight.name << endl;
    cout << flashlight.des << endl;
    cout << "Effect: mystery" << endl;
    cout << "You have " << Flashlight_number << endl;
    cout << "You cannot use it right now" << endl;
    cout << "Enter any key to back" << endl;

    cin >> choose_use_or_not;

    break;

    case 5:
    system("clear");
    cout << gameboy.name << endl;
    cout << gameboy.des << endl;
    cout << "Effect: mental + 10" << endl;
    cout << "Do you want to use? (You have " << Gameboy_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (Gameboy_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        Gameboy_number -= 1;
        temp_status[3] += 10;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 6:
    system("clear");
    cout << seashell.name << endl;
    cout << seashell.des << endl;
    cout << "Effect: mental + 5" << endl;
    cout << "Do you want to use? (You have " << Seashell_number << ")"<< endl;
    cout << "Y for use, any key to back" << endl;

    cin >> choose_use_or_not;

    if (choose_use_or_not == 'Y' | choose_use_or_not == 'y')
    {
      if (Seashell_number > 0)
      {
        sleep(1);
        cout << "used!" << endl;
        Seashell_number -= 1;
        temp_status[3] += 10;
      }
      else
      {
        cout << "You do not have it!" << endl;
      }
    }
    break;

    case 7:
    return item_menu();
  }
  cout << "Back to the menu!" << endl;
  sleep(1);
  system("clear");
  return other_menu();
}

// all the function below are for the menu
// item_menu() printing the main item menu
void item_menu()
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
  cout << "Water Menu" << endl;
  cout << "1. Clean Water: " << cleanwater_number << endl;
  cout << "2. Soda: " << soda_number << endl;
  cout << "3. Pee: " << pee_number << endl;
  cout << "4. Coconut: " << coconut_number << endl;
  cout << "5. Dirty water: " << dirtywater_number << endl;
  cout << "6. Back " << endl;

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
  cout << "Food Menu" << endl;
  cout << "1. Meat: " << meat_number << endl;
  cout << "2. Wild Berry: " << wildberry_number << endl;
  cout << "3. Worm: " << worm_number<< endl;
  cout << "4. Unknown Mushroom: " << mushroom_number << endl;
  cout << "5. Energy Bar: " << energybar_number << endl;
  cout << "6. Back " << endl;

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
  cout << "Medicine Menu" << endl;
  cout << "1. Herb: " << herb_number << endl;
  cout << "2. Pill: " << pill_number << endl;
  cout << "3. Bandage: " << bandage_number<< endl;
  cout << "4. First Aid Kit: " << firstaidkit_number << endl;
  cout << "5. Sedative: " << sedative_number << endl;
  cout << "6. Back " << endl;

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
  cout << "Weapon Menu" << endl;
  cout << "1. Wooden Stick: " << woodenstick_number << endl;
  cout << "2. Rock: " << rock_number << endl;
  cout << "3. Knife: " << knife_number<< endl;
  cout << "4. Spear: " << spear_number << endl;
  cout << "5. Back " << endl;
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
  cout << "Other Menu" << endl;
  cout << "1. Wilson the Volleyball: " << WilsontheVolleyball_number << endl;
  cout << "2. Newspaper: " << Newspaper_number << endl;
  cout << "3. Leaf: " << Leaf_number << endl;
  cout << "4. Flashlight: " << Flashlight_number << endl;
  cout << "5. Gameboy: " << Gameboy_number << endl;
  cout << "6. Seashell: " << Seashell_number << endl;
  cout << "7. Back " << endl;

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

