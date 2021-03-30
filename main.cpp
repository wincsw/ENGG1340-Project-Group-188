#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio> // for remove file
#include <string>
#include <stdlib.h>   // for system("clear")
#include <unistd.h>     // for sleep()
#include "structures.h"
#include "player_status.h"
#include "item_pack.h"
#include "data_items.h"
#include "draw.h"

using namespace std;

// Function: save game status and quit game
// Input: int day: day number
//        int status[]: player status
//        int water_count[]: quantity of water items
//        int food_count[]: quantity of food items
//        int medicine_count[]: quantity of medicine items
//        int weapon_count[]: quantity of weapon items
//        int other_count[]: quantity of other items    
void quitGame(int day, int status[], int water_count[], int food_count[],
  int medicine_count[], int weapon_count[], int other_count[]) {
  
  // open "game_status.txt" for output
  ofstream fout("game_status.txt");

  // error
  if (fout.fail()) {
    cout << "Error in saving game!" << endl;
    exit(1);    
  }

  // output day
  fout << "day" << endl << day << endl;
  
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

  // exit program
  exit(1);

}

// Function: extract game status for new game
// Input: int &day: day number
//        int status[]: player status
//        int water_count[]: quantity of water items
//        int food_count[]: quantity of food items
//        int medicine_count[]: quantity of medicine items
//        int weapon_count[]: quantity of weapon items
//        int other_count[]: quantity of other items 
void newStatus(int &day, int status[], int water_count[], int food_count[],
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
      day = stoi(line);
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
  fin.close()

}

// Function: extract game status for continuig previous game
// Input: int &day: day number
//        int status[]: player status
//        int water_count[]: quantity of water items
//        int food_count[]: quantity of food items
//        int medicine_count[]: quantity of medicine items
//        int weapon_count[]: quantity of weapon items
//        int other_count[]: quantity of other items 
void resumeStatus(int &day, int status[], int water_count[], int food_count[],
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
      day = stoi(line);
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
  fin.close()
}

// Function: execute win and lose
// Input: int &day: day number
//        int status[]: player status
void winLose(int day, int status[]) {
  // win
  // lose
}

// Function: display game play menu
// Input: int &day: day number
//        int status[]: player status
//        int water_count[]: quantity of water items
//        int food_count[]: quantity of food items
//        int medicine_count[]: quantity of medicine items
//        int weapon_count[]: quantity of weapon items
//        int other_count[]: quantity of other items 
void playMenu(int &day, int status[], int water_count[], int food_count[],
  int medicine_count[], int weapon_count[], int other_count[]) {
  
  int choose;

  // print out game play menu
  cout << "Day " << day << endl;
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
      day++;
      // event
      dailyDrop(status);  // daily drop of Hydration and Hunger (and maybe HP)

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
  playMenu(day, status, water_count, food_count, medicine_count, weapon_count, other_count);
}

// Function: print out the start page of the game
// Input: int &day: day number
//        int status[]: player status
//        int water_count[]: quantity of water items
//        int food_count[]: quantity of food items
//        int medicine_count[]: quantity of medicine items
//        int weapon_count[]: quantity of weapon items
//        int other_count[]: quantity of other items 
void startPage(int &day, int status[], int water_count[], int food_count[],
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
      quitGame(day, status, water_count, food_count, medicine_count, weapon_count, other_count);
      break;
    // invalid input
    default:
      cout << "Invalid input, please input again!" << endl;

      system("clear");
      startPage(day, status, water_count, food_count, medicine_count, weapon_count, other_count);
  }
}

// Function: print out the intro story of the game
void intro() {
  // intro text
  return;
}

// Function: print out the credit and allow win/lose shortcut
void credit() {
  // credit text
  // win/lose shortcut
  return;
}

int main() {
  // variables for game play data
  int day;
  int status[4];
  int water_count[5];
  int food_count[5];
  int medicine_count[5];
  int weapon_count[4];
  int other_count[6];

  system("clear");
  // call start page
  startPage(day, status, water_count, food_count, medicine_count, weapon_count, other_count);

}
g++ -pedantic-errors -std=c++11 main.cpp player_status.cpp draw.cpp item_pack.cpp data_items.cpp -o main