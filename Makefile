FLAGS = -pedantic-errors -std=c++11

data_items.o: data_items.cpp data_items.h structures.h
	g++ $(FLAGS) -c $<

data_attackers.o: data_attackers.cpp data_attackers.h structures.h
	g++ $(FLAGS) -c $<

player_status.o: player_status.cpp player_status.h
	g++ $(FLAGS) -c $<

item_pack.o: item_pack.cpp item_pack.h data_items.h structures.h
	g++ $(FLAGS) -c $<

draw.o: draw.cpp draw.h item_pack.h structures.h
	g++ $(FLAGS) -c $<

fight.o: fight.cpp fight.h data_items.h data_attackers.h item_pack.h structures.h
	g++ $(FLAGS) -c $<

data_events.o: data_events.cpp data_events.h data_items.h item_pack.h fight.h structures.h
	g++ $(FLAGS) -c $<

main.o: main.cpp data_items.h data_attackers.h player_status.h item_pack.h draw.h fight.h data_events.h structures.h
	g++ $(FLAGS) -c $<

survival: data_items.o data_attackers.o player_status.o item_pack.o draw.o fight.o data_events.o structures.h main.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f *.o

.PHONY: clean
