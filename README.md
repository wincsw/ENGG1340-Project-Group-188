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
      
      Resources you may obtain:
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


## Features 

- Draw Resource

  The player can draw 3 random resource items every day, and the cards they have drawn will be stored in the Item Pack for future use.
  
  Coding element:
  - Generation of random game sets or events
    
    The 3 cards drawn will be generated randomly using `rand()` and `srand(time(NULL))`.
    
  - Data structures for storing game status

    Self-defined data structure `Item` will be used to store the information of the items, while data structure of `array` and data types of `string` and `int` will be used in the `Item` data structure. Note that data structure `Item` is stored in `structures.h`.
     
  - Dynamic memory management
    
    The 3 drawn items will be stored in a dynamic array by `new[]`. The memory used to store the drawn cards will be freed after the cards are saved in the Item Pack by `delete[]`.
  
  - Program codes in multiple files
    
    Codes of all the items' information and the drawing mechanism will be stored in files of `data_items.cpp` and `draw_item.cpp` respectively, seperated from `main.cpp`. 

- Random Event

  A random event will happen every 3 days.
  
  Coding element:
  - Generation of random game sets or events
  
    The events and the number of days will be generated randomly using `rand()` and `srand(time(NULL))`.
  
  - Data structures for storing game status

    Self-defined data structure `event` will be used to store the infomation of the items, which data structure of `array` and data types of `string` and `int` will be used in the `event` data structure. 
    
- Fighting Attackers (dynamic)
  
  The event of player being attack and need to fight back.
  
  Coding element:
  - Data structures for storing game status

    Self-defined data structure `attacker` will be used to store the infomation of the items, which data types of `string` and `int` will be used in the `attacker` data structure. 
  
  - Dynamic memory management
 
    The fighting status (e.g. the tempory HP) will be stored by `new`. The memory used to store the fighting status will be freed after the fight ends by `delete`.
    
  - Program codes in multiple file
  
    Codes of the fighting mechanism and the attackers are stored in seperate files of `fight.cpp` and `data_attackers.cpp`.

- Daily Decreas in Player Status

- Save and Resume gameplay (dynamic)
  
  Coding element:
  - Data structures for storing game status
    
    Data structure of `array` will be used to store the game status components (e.g. the player status, the number of a specific item in the item pack).
    
  - File input/output
    
    The user can save the game status and resume the game later. The game status will be output to a `game_status.txt` file, and the `game_status.txt` file will be inputted to the game program when the game is resumed.
    

## Inspriation
- Game Mechanism: Draw Card Life https://www.taptap.com/app/35686
- Item: Survive - Wilderness survival https://play.google.com/store/apps/details?id=com.sandbaygames.survive
