#Pastas
INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
DATA_DIR = ./data

#Variaveis
CC = g++
CFLAGS = -Wall -std=c++11

output: $(OBJ_DIR)/main.o $(OBJ_DIR)/PC.o $(OBJ_DIR)/REGS.o $(OBJ_DIR)/ULA.o 
	mkdir -p bin
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/PC.o $(OBJ_DIR)/REGS.o $(OBJ_DIR)/ULA.o -o $(BIN_DIR)/SquareRoot

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/main.cpp -I $(INC_DIR) -o $(OBJ_DIR)/main.o $(CFLAGS)

$(OBJ_DIR)/PC.o: $(SRC_DIR)/PC.cpp $(INC_DIR)/PC.h
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/PC.cpp -I $(INC_DIR) -o $(OBJ_DIR)/PC.o $(CFLAGS)

$(OBJ_DIR)/REGS.o: $(SRC_DIR)/REGS.cpp $(INC_DIR)/REGS.h
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/REGS.cpp -I $(INC_DIR) -o $(OBJ_DIR)/REGS.o $(CFLAGS)

$(OBJ_DIR)/ULA.o: $(SRC_DIR)/ULA.cpp $(INC_DIR)/ULA.h
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/ULA.cpp -I $(INC_DIR) -o $(OBJ_DIR)/ULA.o $(CFLAGS)
