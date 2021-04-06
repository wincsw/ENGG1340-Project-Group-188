# ENGG1340-Project-Group-188

## Contributing
Chan Sze Wing   (UID: 3035745063, Username: adhk852)

Chan Yuen Kwan  (UID: 3035781641, Username: jojochan09)

## Game Description
This is a text-based role-playing game which simulate a person surviving on an uninhabited island. You are a passenger of a cruise ship, due to a shipwreck you are now stranded this unknown island. On this island, you will collect resources that can help maintain your life. Meanwhile, different events may happen and can cause danger or bring surprises. In this game, everything is random, so good luck.


## Rules
 - Your status represented by:
   - **HP**: the value that represents health point, drop if you are 
     1. being attacked or getting hurt
     2. too hungry (*Hunger below 50*)
     3. mentally unstable (*Mental  below 50*)
   - **Hydration**: the value that represents your thirst, it will drop every day
   - **Hunger**: the value that represent your hunger, it will drop every day
   - **Mentality**: the value that represents your mental status
 - If **HP/hydration** go to **0**, you will die and **lose** the game 
 
 - Every day starts, you will find **3 resource item**
      
      Categories if resources you may obtain:
   - **Food**: increase your Hunger value
   - **Water**: increase your Hydration value
   - **Medicines**: increase your HP or Mentality value
   - **Weapons**: for fighting against attackers 
   - And some **Mystery** items 
 - All resources will be saved in the Item Pack, you can use them on the same day or later
 - Random events will happen every 3 days, which may affect your status
 - **How to Win**
   1. Survive for **50 days**, and
   2. Maintain your **HP** and **Hydration** **above 0**

## Quick Start

## Features 

- Draw Resource

  The player can draw 3 random resource items every day, and the cards they have drawn will be stored in the Item Pack for future use.
  
  Coding element:
  - Generation of random game sets or events
    
    The 3 cards drawn will be generated randomly using `rand()` and `srand(time(NULL))`.
    
  - Data structures for storing game status

    Self-defined data structure `Item` will be used to store the information of the items, while data structure `array` and data types `string` and `int` will be used in the data structure. Note that data structure `Item` is stored in `structures.h`.
     
  - Dynamic memory management
    
    The 3 drawn items will be stored in a dynamic array by `new[]`. The memory will then be freed after the cards are saved in the Item Pack by `delete[]`.
  
  - Program codes in multiple files
    
    Codes of all the items' information and the drawing mechanism will be stored in files `data_items.cpp` and `draw_item.cpp` respectively, seperated from `main.cpp`. Which `draw.cpp` will call the informations of the items from `data_items.cpp`.

- Random Event

  A random event will happen every 3 days.
  
  Coding element:
  - Generation of random game sets or events
  
    The events will be generated randomly using `rand()` and `srand(time(NULL))`.
  
  - Data structures for storing game status

    Self-defined data structure `Event` will be used to store the infomation of the events, which data structure `array` and data types `string` and `int` will be used in the data structure. Note that data structure `Event` is stored in `structures.h`.
    
- Fighting Attackers 
  
  The event of player being attack and need to fight back.
  
  Coding element:
  - Data structures for storing game status

    Self-defined data structure `Attacker` and `Item` will be used to store the infomation of the attackers and weapons, which data structure `array` data types `string` and `int` will be used in the data structures. Note that data structure `Attacker` and `Item` are stored in `structures.h`.
  
  - Dynamic memory management
 
    The quantity of weapons the player has will be stored in a dynamic array by `new[]`. The memory will then be freed after the fight ends by `delete[]`.
    
  - Program codes in multiple file
  
    Codes of the fighting mechanism and the attackers are stored in files `fight.cpp` and `data_attackers.cpp` respectively, seperated from `main.cpp`. Which `fight.cpp` will call the informations of attackers from `data_attacker.cpp`.

- Daily Decrease in Hydration and Hunger value

  The player's Hydration and Hunger value will decrease a certain amount when a new day started
  
  - Generation of random game sets or events
  
    The amount of decreation will be generated randomly using `rand()` and `srand(time(NULL))`.
    
  - Program codes in multiple files
    
    Codes of the function for reducing Hydration and Hunger value will be stored in file `player_status.cpp` (also the function for printing out player status), seperated from `main.cpp`. Which `main.cpp` will call this function from `player_status.cpp`.
  

- Save and Resume gameplay (dynamic)
  
  Player can quit and save the game and resume it later.
  
  Coding element:
  - Data structures for storing game status
    
    Data structure `array` will be used to store the game status components, including the player status and the quantity of items from different catagories in the item pack.
  
  - Dynamic memory management
    
    All the arrays used to store the game status components are dynamic arrays which are created by `new[]`. The memory will be freed after the player quit the game by `delete[]`.
    
  - File input/output
    
     When starting a new game, datas in the file `new_game.txt` will be inputed as the intial game status. After the player quit the game, `game_status.txt` file will be created (if it was a new game) and the game status will be outputed to this file. When the player resume the game, `game_status.txt` file will be loaded back to the game. If the player win/lose or started a new game, `game_status.txt` file will be removed.
    
## Non-Standard C/C++ Libaries

## Inspriation
- Game Mechanism: Draw Card Life https://www.taptap.com/app/35686
- Item: Survive - Wilderness survival https://play.google.com/store/apps/details?id=com.sandbaygames.survive
