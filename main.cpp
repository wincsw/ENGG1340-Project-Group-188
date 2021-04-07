// main.cpp
// file for eixcution 

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio> // for remove file
#include <string>
#include <cstdlib>   // for system("clear")
#include <unistd.h>     // for sleep()
#include "structures.h"
#include "player_status.h"
#include "item_pack.h"
#include "data_items.h"
#include "draw.h"
#include "data_attackers.h"
#include "fight.h"
#include "data_events.h"

using namespace std;

// Function: free the memory storing game data
// Input: int *day: day count
//        int status[]: player status
//        int water_count[]: quantity of water items
//        int food_count[]: quantity of food items
//        int medicine_count[]: quantity of medicine items
//        int weapon_count[]: quantity of weapon items
//        int other_count[]: quantity of other items  
void freeMemory(int * day, int status[], int water_count[], int food_count[],
  int medicine_count[], int weapon_count[], int other_count[]) {
  delete day;
  day = 0;
  delete [] status;
  status = 0;
  delete [] water_count;
  water_count = 0;
  delete [] food_count;
  food_count = 0;
  delete [] medicine_count;
  medicine_count = 0;
  delete [] weapon_count;
  weapon_count = 0;
  delete [] other_count;
  other_count = 0;
    
  }

// Function: save game status and quit game
// Input: int *day: day count
//        int status[]: player status
//        int water_count[]: quantity of water items
//        int food_count[]: quantity of food items
//        int medicine_count[]: quantity of medicine items
//        int weapon_count[]: quantity of weapon items
//        int other_count[]: quantity of other items    
void quitGame(int *day, int status[], int water_count[], int food_count[],
  int medicine_count[], int weapon_count[], int other_count[]) {
  
  // open "game_status.txt" for output
  ofstream fout("game_status.txt");

  // error
  if (fout.fail()) {
    cout << "Error in saving game!" << endl;
    exit(1);    
  }

  // output day
  fout << "day" << endl << *day << endl;
  
  // output status value line by line
  fout << "status" << endl;
  for (int s = 0; s < 4; s++) {
    fout << status[s] << endl;
  }

  // output quantity items from different catagory line by line
  fout << "water" << endl;
  for (int wt = 0; wt < 5; wt++) {
    fout << water_count[wt] << endl;
  }

  fout << "food" << endl;
  for (int f = 0; f < 5; f++) {
    fout << food_count[f] << endl;
  }

  fout << "medicine" << endl;
  for (int md = 0; md < 5; md++) {
    fout << medicine_count[md] << endl;
  }

  fout << "weapon" << endl;
  for (int wp = 0; wp < 4; wp++) {
    fout << weapon_count[wp] << endl;
  }

  fout << "mystery" << endl;
  for (int my = 0; my < 6; my++) {
    fout << other_count[my] << endl;
  }

  // close file
  fout.close();

  system("clear");

  freeMemory(day, status, water_count, food_count, medicine_count, weapon_count, 
        other_count);


  // exit program
  exit(1);

}

// Function: extract game status for new game
// Input: int *day: day count
//        int status[]: player status
//        int water_count[]: quantity of water items
//        int food_count[]: quantity of food items
//        int medicine_count[]: quantity of medicine items
//        int weapon_count[]: quantity of weapon items
//        int other_count[]: quantity of other items 
void newStatus(int *day, int status[], int water_count[], int food_count[],
  int medicine_count[], int weapon_count[], int other_count[]) {
  // open "new_game.txt" for input
  ifstream fin("new_game.txt");

  // error
  if (fin.fail()) {
    cout << "Error in file opening!" << endl;
    exit(1);    
  }

  string line;

  // read the whole file
  while (getline(fin, line)) {

    // read day
    if (line == "day") {
      getline(fin, line);
      *day = stoi(line);
    }
    // read status
    else if (line == "status") {
      for (int i = 0; i < 4; i++) {
        getline(fin, line);
        status[i] = stoi(line);
      }
    }
    // read the quantity of items in different catagory
    else if (line == "water") {
      for (int i = 0; i < 5; i++) {
        getline(fin, line);
        water_count[i] = stoi(line);
      }
    }

    else if (line == "food") {
      for (int i = 0; i < 5; i++) {
        getline(fin, line);
        food_count[i] = stoi(line);
      }
    }

    else if (line == "medicine") {
      for (int i = 0; i < 5; i++) {
        getline(fin, line);
        medicine_count[i] = stoi(line);
      }
    }

    else if (line == "weapon") {
      for (int i = 0; i < 4; i++) {
        getline(fin, line);
        weapon_count[i] = stoi(line);
      }
    }

    else if (line == "mystery") {
      for (int i = 0; i < 6; i++) {
        getline(fin, line);
        other_count[i] = stoi(line);
      }
    }
  }

  // close file
  fin.close();

}

// Function: extract game status for continuig previous game
// Input: int *day: day count
//        int status[]: player status
//        int water_count[]: quantity of water items
//        int food_count[]: quantity of food items
//        int medicine_count[]: quantity of medicine items
//        int weapon_count[]: quantity of weapon items
//        int other_count[]: quantity of other items 
void resumeStatus(int *day, int status[], int water_count[], int food_count[],
  int medicine_count[], int weapon_count[], int other_count[]) {
  // open "resume_game.txt" for input
  ifstream fin("game_status.txt");
  //error
  if (fin.fail()) {
    cout << "Error in file opening!" << endl;
    exit(1);    
  }
  
  string line;
  // read the whole file
  while (getline(fin, line)) {
    // read day
    if (line == "day") {
      getline(fin, line);
      *day = stoi(line);
    }
    // read player status
    else if (line == "status") {
      for (int i = 0; i < 4; i++) {
        getline(fin, line);
        status[i] = stoi(line);
      }
    }
    // read the quantity of items in different catagory
    else if (line == "water") {
      for (int i = 0; i < 5; i++) {
        getline(fin, line);
        water_count[i] = stoi(line);
      }
    }

    else if (line == "food") {
      for (int i = 0; i < 5; i++) {
        getline(fin, line);
        food_count[i] = stoi(line);
      }
    }

    else if (line == "medicine") {
      for (int i = 0; i < 5; i++) {
        getline(fin, line);
        medicine_count[i] = stoi(line);
      }
    }

    else if (line == "weapon") {
      for (int i = 0; i < 4; i++) {
        getline(fin, line);
        weapon_count[i] = stoi(line);
      }
    }

    else if (line == "mystery") {
      for (int i = 0; i < 6; i++) {
        getline(fin, line);
        other_count[i] = stoi(line);
      }
    }
  }

  // close file
  fin.close();
}

// Function execute win
void win() {
  cout << "The rescue team FINALLY arrived" << endl;
  sleep(1);
  cout << "After you got rescued" << endl;
  sleep(1);
  cout << "You made a game base on your experience" << endl;
  sleep(1);
  cout << "And you earn a lot of money by this game" << endl;
  sleep(1);
  cout << "You spend those money by going on a cruise ship trip" << endl;
  sleep(1);
  cout << "I wonder what will happen next..." << endl;
  sleep(1);
  cout << "You WIN" << endl;
  sleep(2);

}

// Function: execute lose
void lose() {
  cout << "You LOSE" << endl;
  sleep(2);
}

// Function: determine win and lose
// Input: int *day: day count
//        int status[]: player status
void winLose(int *day, int status[], int water_count[], int food_count[],
  int medicine_count[], int weapon_count[], int other_count[]) {
  // win
  if (*day == 50 && status[0] > 0 && status[1] > 0) {
    freeMemory(day, status, water_count, food_count, medicine_count, weapon_count, 
        other_count);
    remove("game_status.txt");
    win();
    exit(1);
  }
  // lose
  else if (status[0] <= 0 || status[1] <= 0) {
    freeMemory(day, status, water_count, food_count, medicine_count, weapon_count, 
        other_count);
    remove("game_status.txt");
    
    if (status[0] <= 0) {
      cout << "Hydration 0" << endl;
      cout << "You thrist to death" << endl;
    }
    else {
      cout << "HP 0" << endl;
      cout << "You life comes to the end" << endl;
    }
    lose();
    exit(1);
  }
  else {
    return;
  }
}

// Function: print out the credit and allow win/lose shortcut
// Output: bool: used shortcut or not
void credit() {
  // credit text
  cout << "Producer/Designer/Programmer" << endl;
  cout << "---------------------------" << endl;
  cout << "Chan Sze Wing" << endl;
  cout << "Chan Yuen Kwan" << endl;
  cout << endl;
  cout << "Sponser" << endl;
  cout << "---------------------------" << endl;
  cout << "ENGG1340" << endl;
  cout << endl;
  cout << "Special Thanks to all the professors and TAs" << endl;
  cout << endl;

  char shortcut;

  cout << "Press any key to return" << endl;
  cin >> shortcut;

  // winshortcut
  if (shortcut == 'W') {
    system("clear");
    cout << "Developer shortcut: Win Ending" << endl;
    cout << "---------------------------" << endl;
    sleep(1);
    win();
    exit(1);
  }
  else {
    return;
  }

}

// Function: display game play menu
// Input: int *day: day count
//        int status[]: player status
//        int water_count[]: quantity of water items
//        int food_count[]: quantity of food items
//        int medicine_count[]: quantity of medicine items
//        int weapon_count[]: quantity of weapon items
//        int other_count[]: quantity of other items 
void playMenu(int *day, int status[], int water_count[], int food_count[],
  int medicine_count[], int weapon_count[], int other_count[]) {
  
  int choose;

  // print out game play menu
  cout << "Day " << *day << endl;
  cout << "---------------------------" << endl;
  printStatus(status);  // print out player status
  cout << "---------------------------" << endl;
  cout << "1. Next Day" << endl; 
  cout << "2. Item Pack" << endl;
  cout << "3. Quit Game" << endl;

  cin >> choose;
  switch (choose) {
    // Next Day
    case 1:
      // transfer to next day
      *day = *day + 1;

      // random event every 3 days
      if (*day % 3 == 0) {
        call_event(water_count, weapon_count, other_count, food_count, status);
        winLose(day, status, water_count, food_count, medicine_count, weapon_count, other_count);
      }

      //sleep(1);
      system("clear");
      
      dailyDrop(status);  // daily drop of Hydration and Hunger (and maybe HP)
      winLose(day, status, water_count, food_count, medicine_count, weapon_count, other_count);

      sleep(2);
      system("clear");

      dailyDraw(water_count, food_count, medicine_count, weapon_count, 
        other_count); // daily draw for 3 items
      break;
      
    // Item Pack
    case 2:
      item_menu(status, water_count, food_count, medicine_count, weapon_count, 
        other_count);   // access item menu
      break;
      
    case 3:
      quitGame(day, status, water_count, food_count, medicine_count, 
        weapon_count, other_count);   // save and quit game
      break;

    // invalid input
    default:
      cout << "Invalid input, please input again!" << endl;
      
  }
  system("clear");
  winLose(day, status, water_count, food_count, medicine_count, weapon_count, other_count);
  playMenu(day, status, water_count, food_count, medicine_count, weapon_count, other_count);
}

// Function: print out the intro story of the game
void intro() {
  cout << "You are a passenger of a cruise ship" << endl;
  sleep(1);
  cout << "However you're SO unlucky that you went into a shipwreck" << endl;
  sleep(1);
  cout << "Now you are on this uninhabited island" << endl;
  sleep(1);
  cout << "In your bag, there are some water and an energy bar" << endl;
  sleep(1);
  cout << "You pick up a wooden stick that will forever belongs to you" << endl;
  sleep(1);
  cout << "Try your best to survive for 50 days" << endl;
  sleep(1);
  cout << "Then the rescue team will come and save you" << endl;
  sleep(1);
  cout << endl;

  char * temp = new char;
  cout << "Press any key to start game" << endl;
  cin >> *temp;
  delete temp;
  *temp = 0;
  return;
}

// Function: print out the start page of the game
// Input: int *day: day count
//        int status[]: player status
//        int water_count[]: quantity of water items
//        int food_count[]: quantity of food items
//        int medicine_count[]: quantity of medicine items
//        int weapon_count[]: quantity of weapon items
//        int other_count[]: quantity of other items 
void startPage(int *day, int status[], int water_count[], int food_count[],
  int medicine_count[], int weapon_count[], int other_count[]) {

  // check are there a previous game
  ifstream fin("game_status.txt");
  int choose;

  if (fin) {
    // with previous game
    fin.close();

    cout << "The Survival Game" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Resume Game" << endl; // allow Resum Game option
    cout << "2. New Game" << endl;
    cout << "3. Credit" << endl;
    cout << "4. Quit Game" << endl;

    cin >> choose;    
  }
  else {
    // without previous game
    fin.close();
    
    cout << "The Survival Game" << endl;
    cout << "---------------------------" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Credit" << endl;
    cout << "3. Quit Game" << endl;

    cin >> choose;
    choose++;

  }
  
  switch (choose) {
    // Resume game
    case 1:
      // extract previous game status
      resumeStatus(day, status, water_count, food_count, medicine_count, 
        weapon_count, other_count);

      system("clear");
      // print out game play menu
      playMenu(day, status, water_count, food_count, medicine_count, 
        weapon_count, other_count);

      break;
    // New Game
    case 2:
      // remove previous game data (if exisit)
      remove("game_status.txt");
      
      // extract new game status
      newStatus(day, status, water_count, food_count, medicine_count, 
        weapon_count, other_count);
            
      system("clear");
      // game intro
      intro();
      
      system("clear");
      // print out game play menu
      playMenu(day, status, water_count, food_count, medicine_count, 
        weapon_count, other_count);

      break;
    // Credit
    case 3:
      system("clear");
      credit();
      system("clear");
      // back to start page
      startPage(day, status, water_count, food_count, medicine_count, weapon_count, other_count);
      break;
    // Quit Game
    case 4:
      //quitGame(day, status, water_count, food_count, medicine_count, weapon_count, other_count);
      exit(1);
      break;
    // invalid input
    default:
      cout << "Invalid input, please input again!" << endl;

      system("clear");
      startPage(day, status, water_count, food_count, medicine_count, weapon_count, other_count);
  }
}

// Function: main function
int main() {
  // dynamic variables for game play data
  int * day = new int;
  int * status = new int[4];
  int * water_count = new int[water_num];
  int * food_count = new int[food_num];
  int * medicine_count = new int[medicine_num];
  int * weapon_count = new int[weapon_num];
  int * other_count = new int[mystery_num];

  system("clear");
  // call start page
  startPage(day, status, water_count, food_count, medicine_count, weapon_count, other_count);
  
  return 0;
}
//g++ -pedantic-errors -std=c++11 main.cpp player_status.cpp fight.cpp data_attackers.cpp data_events.cpp draw.cpp item_pack.cpp data_items.cpp -o main
