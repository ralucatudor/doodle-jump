flags_all = -c

SCR_PARAMS = src/*.cpp
OBJ_PARAMS = *.o

LIB_PARAMS = sfml-app -lsfml-graphics -lsfml-window -lsfml-system

all:
	g++ $(flags_all) -std=c++11 $(SCR_PARAMS) 
	g++ $(OBJ_PARAMS) -o $(LIB_PARAMS) 
	./sfml-app

help:
	g++ $(flags_all) $(SCR_PARAMS) 
	g++ $(OBJ_PARAMS) -o $(LIB_PARAMS) 
	./sfml-app --help