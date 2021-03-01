# ENGG1340-Project-Group-188
```
Group Members : Chan Sze Wing   (3035745063)
                Chan Yuen Kwan  (3035781641)
Game Idea     : Card Based Survival Simulator 
```

## Game Discription
You play as **Joe**, an average and cannot be more average, who is so unlucky had gone into a shipwreck, but also lucky enough to find yourself surviving on an **uninhabited island**. Joe must survive for **100 days** until the rescue team arrives to save him (~~don't ask why 100 days~~). 

On this island, there will be different **unexpected events** that may cause danger or surprises. Random resources (*in the form of cards*) will be found to maintain your life. Remember, IT IS **ALL RANDOM**! So good luck.


## Rules
 - Your status represented by:
   - **HP**: health point, drop if you are being attacked or you are hungry 
   - **hydration**: the value that represent your thrist, it will drop everyday
   - **mentality**: the value that represent your mental status, if it goes too low, you may do something uncontrollable, even KILL YOURSELF!
   - **health**: the value that represent your physical health, if it goes too low, your **HP value** may drop in a high proportion
 - If **HP/hydration** go to **0** , you will die and **lose** the game 
 
 - Every day starts, you will have a chance to draw cards
      
      Cards you may obtain:
   - **Food card**: increase your HP value
   - **Water card**: increase your hydration value
   - **Mecidine card**: heal you if you are suffering with diseases and increase your health or mentality value
   - **Weapons card**: you can use them to protect yourself if you involve in some special events
   - AND SOME **MYSTERY CARDS**
 - After drawing cards, the cards will be saved in the Item Pack, you can use them immediately or you can straightly pass to the next day and use them later
 - Random events may happen and they may affect your status as well
 - *Target*: Survive for **100 days** !


## Features 
- Draw Cards

  The player can draw 3 random resource cards every day, and the cards they have drawn will be stored in the Item Pack for future use.
  
  Coding element:
  - Generation of random game sets or events
    
    The cards drawn will be generated randomly using `int rand()`.
    
  - Dynamic memory management
    
    The drawn cards will be stored in dynamic memory by `new[]`. The memory used to store the drawn cards will be freed after the cards are saved in the item pack by `delete[]`.
  
  - Program codes in multiple files
    
    The cards' information and function will be stored in different files (e.g. `food_card.cpp`)according to their type and access by respecting header files (e.g. `food_cards.h`). 

- Random Event
  
  Coding element:
  - Generation of random game sets or events
  
    One event will happen every 2 or 3 days. The events and the number of days will be chosen randomly using `int rand()`.
    
  - Program codes in multiple files
    
    The information of the events will be stored in a different file `events.cpp`, and access by the header file `events.h`.
    
- Save and Resume gameplay
  
  Coding element:
  - Data structures for storing game status
    
    Different data structures will be used to store the components of the game status (e.g. the player's status, the cards in the item pack).
    
  - File input/output
    
    The user can save the game status and resume the game later. The game status will be output to a `game_status.txt` file, and the `game_status.txt` file will be inputted to the game program when the game is resumed.
