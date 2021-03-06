flags_all = -c -std=c++2a -lstdc++fs

SCR_PARAMS = main.cpp src/*.cpp
INC_PARAMS = inc/
OBJ_PARAMS = *.o

LIB_PARAMS = sfml-app -lsfml-graphics -lsfml-window -lsfml-system 

SANITIZER = -fsanitize=address

all:
	g++ $(flags_all) -I$(INC_PARAMS) $(SCR_PARAMS) 
	g++ $(OBJ_PARAMS) -o $(LIB_PARAMS) 
	./sfml-app

help:
	g++ $(flags_all) -I$(INC_PARAMS) $(SCR_PARAMS) 
	g++ $(OBJ_PARAMS) -o $(LIB_PARAMS) 
	./sfml-app --help