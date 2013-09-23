CC = g++
TARGET = artrix
INC = -Iinclude -I/opt/vc/include -I/usr/include/libxml2
LIB = -lm -lglut -lxml2 -lSOIL -lGLU -lrt -lGLEW

RES_DIR = /usr/share/$(TARGET)
SRC_DIR = src
SRC = afx.cpp VertexDeclarations.cpp FlapsWidget.cpp RenderContext.cpp artrix.cpp ImageWidget.cpp SplashView.cpp View.cpp Widget.cpp TxBatteryMeterWidget.cpp ViewManager.cpp WidgetFactory.cpp TextureManager.cpp AttitudeIndicatorWidget.cpp TextWidget.cpp SerialInterface.cpp FontManager.cpp StateManager.cpp TimerWidget.cpp TelemetryWidget.cpp UIWidget.cpp LogManager.cpp BMFontManager.cpp SPIInterface.cpp CircularGaugeWidget.cpp ShaderManager.cpp Shader.cpp Program.cpp ShadingProgramManager.cpp
OBJ = $(SRC:.cpp=.o)

all: precompile compile link 

precompile:
	rm -f -r $(RES_DIR)
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

	

