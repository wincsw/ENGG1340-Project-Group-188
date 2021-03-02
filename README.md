# ENGG1340-Project-Group-188

## Contributing
Chan Sze Wing   (UID: 3035745063, Username: adhk852)
Chan Yuen Kwan  (UID: 3035781641, Username: jojochan09)

## Game Description
Our game is a text-based role-playing game that tries to simulate a person surviving on an uninhabited island. You are a passenger of a cruise ship who is stranded on an uninhabited island after the shipwreck.

On this island, there will be different unexpected events that may cause danger or surprises. Random resources will be found to help maintain your life. You must survive for 100 days until the rescue team comes to save you.


## Rules
 - Your status represented by:
   - **HP**: health point, drop if you are being attacked or you are hungry 
   - **hydration**: the value that represents your thirst, it will drop every day
   - **mentality**: the value that represents your mental status. If it goes too low, you may do something uncontrollable, even may kill yourself!
   - **health**: the value that represent your physical health, if it goes too low, your **HP value** may drop in a high proportion
 - If **HP/hydration** go to **0**, you will die and **lose** the game 
 
 - Every day starts, you will find some resources
      
      Resources you may obtain:
   - **Food**: increase your HP value
   - **Water**: increase your hydration value
   - **Mecidines**: heal you if you are suffering with diseases and increase your health or mentality value
   - **Weapons**: you can use them to protect yourself if you involve in some special events
   - And some **Mystery** items
 - After finding the resources, the resources will be saved in the Item Pack, you can use them immediately, or you can straightly pass to the next day and use them later
 - Random events may happen, and they may affect your status as well
 - *How to Win*: Survive for **100 days** 


## Features 

- Draw Cards

  The player can draw 3 random resource cards every day, and the cards they have drawn will be stored in the Item Pack for future use.
  
  Coding element:
  - Generation of random game sets or events
    
    The cards drawn will be generated randomly using `rand()` and `srand(time(NULL))`.
    
  - Dynamic memory management
    
    The drawn cards will be stored in dynamic memory by `new[]`. The memory used to store the drawn cards will be freed after the cards are saved in the Item Pack by `delete[]`.
  
  - Program codes in multiple files
    
    The cards' information and function will be stored in separate files (e.g. `food_card.cpp`)according to their type and access by respecting header files (e.g. `food_cards.h`). 

- Random Event

  A random event will happen every 2 or 3 days.
  
  Coding element:
  - Generation of random game sets or events
  
     The events and the number of days will be chosen randomly using `rand()` and `srand(time(NULL))`.
    
  - Program codes in multiple files
    
    The information of the events and their effects on the player will be stored in a separate file `events.cpp`, and access by the header file `events.h`.
    
- Save and Resume gameplay
  
  Coding element:
  - Data structures for storing game status
    
    Data structures will be used to store the game status components (e.g. the player status, the cards in the item pack).
    
  - File input/output
    
    The user can save the game status and resume the game later. The game status will be output to a `game_status.txt` file, and the `game_status.txt` file will be inputted to the game program when the game is resumed.
