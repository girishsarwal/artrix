CC = g++
INC = -Iinclude -I/opt/vc/include -I/usr/include/libxml2

SRC_DIR = src
SRC = afx.cpp FlapsWidget.cpp RenderContext.cpp artrix.cpp ImageWidget.cpp SplashView.cpp View.cpp Widget.cpp TxBatteryMeterWidget.cpp ViewManager.cpp WidgetFactory.cpp
OBJ = $(SRC:.cpp=.o)


TARGET = artrix
LIB = -lglut -lxml2 -lm

all: compile link 

compile:$(OBJ)
	
link:
	echo Linking $<
	$(CC) $(OBJ) -o $(TARGET) $(LIB)

%.o:src/%.cpp
	echo Compiling $<
	$(CC) -Wall -c $< -o $@ $(INC)
	
	
clean:
	rm -f *.o
	rm -f $(TARGET)

	


