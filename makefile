CC = g++
TARGET = artrix
INC = -Iinclude -I/opt/vc/include -I/usr/include/libxml2
LIB = -lm -lglut -lxml2 -lSOIL

RES_DIR = /usr/share/$(TARGET)
SRC_DIR = src
SRC = afx.cpp FlapsWidget.cpp RenderContext.cpp artrix.cpp ImageWidget.cpp SplashView.cpp View.cpp Widget.cpp TxBatteryMeterWidget.cpp ViewManager.cpp WidgetFactory.cpp TextureManager.cpp AttitudeIndicatorWidget.cpp
OBJ = $(SRC:.cpp=.o)

all: precompile compile link 

precompile:
	mkdir -p $(RES_DIR)
	cp -r ./res/* $(RES_DIR)
	
compile: $(OBJ)
	
link:
	echo Linking $<
	$(CC) $(OBJ) -o $(TARGET) $(LIB)

%.o:src/%.cpp
	echo Compiling $<
	$(CC) -Wall -c $< -o $@ $(INC)
	
	
clean:
	rm -f *.o
	rm -f $(TARGET)

	


