CC = g++
INC = -I/home/rpi/artrix/include -I/opt/vc/include

SRC_DIR = src
SRC = afx.cpp FlapsWidget.cpp RenderContext.cpp artrix.cpp ImageWidget.cpp SplashView.cpp View.cpp Widget.cpp TxBatteryMeterWidget.cpp
OBJ = $(SRC:.cpp=.o)


TARGET = artrix
LIB = glut

all: compile link 

compile:$(OBJ)
	
link:
	echo Linking $<
	$(CC) $(OBJ) -o $(TARGET).bin -l $(LIB)

%.o:src/%.cpp
	echo Compiling $<
	$(CC) -Wall -c $< -o $@ $(INC)
	
	
clean:
	rm *.o
	rm *.bin

	


