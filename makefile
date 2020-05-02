flags_all = -c -std=c++17

SCR_PARAMS = main.cpp src/*.cpp
INC_PARAMS = inc/
OBJ_PARAMS = *.o

LIB_PARAMS = sfml-app -lsfml-graphics -lsfml-window -lsfml-system

all:
	g++ $(flags_all) -I$(INC_PARAMS) $(SCR_PARAMS) 
	g++ $(OBJ_PARAMS) -o $(LIB_PARAMS) 
	./sfml-app

help:
	g++ $(flags_all) -I$(INC_PARAMS) $(SCR_PARAMS) 
	g++ $(OBJ_PARAMS) -o $(LIB_PARAMS) 
	./sfml-app --help