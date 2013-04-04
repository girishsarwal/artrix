CC = g++
TARGET = frsky-emu
INC = -Iinclude -I/opt/vc/include
LIB = -lm -lglib-2.0

RES_DIR = /usr/share/$(TARGET)
SRC_DIR = src
SRC = frsky-emu.cpp
OBJ = $(SRC:.cpp=.o)

all: compile link 

compile: $(OBJ)
	
link:
	echo Linking $<
	$(CC) $(OBJ) -o $(TARGET) $(LIB) 

%.o:%.cpp
	echo Compiling $<
	$(CC) -Wall -c $< -o $@ $(INC) `pkg-config --libs --cflags glib-2.0`
	
	
clean:
	rm -f *.o
	rm -f $(TARGET)
