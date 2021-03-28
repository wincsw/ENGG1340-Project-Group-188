#ifndef DRAW
#define DRAW

// general draw item
struct item draw(int &catagory, int &item_index);

// draw 3 item every day
void dailyDraw(int water_count[], int food_count[], int medicine_count[], 
                  int weapon_count[], int mystery_count[]);

#endif

