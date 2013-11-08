CC = g++
TARGET = artrix
INCLUDES = -Iinclude -I/opt/vc/include -I/usr/include/libxml2
CFLAGS = -Wall -g 

LIBS = -lm -lglut -lxml2 -lSOIL -lGLU -lrt -lGLEW


RES_DIR = /usr/share/$(TARGET)
SRC_DIR = src
OBJ_DIR = obj
OUT_DIR = bin
SRC = afx.cpp VertexDeclarations.cpp FlapsWidget.cpp RenderContext.cpp artrix.cpp ImageWidget.cpp SplashView.cpp View.cpp Widget.cpp TxBatteryMeterWidget.cpp ViewManager.cpp WidgetFactory.cpp TextureManager.cpp AttitudeIndicatorWidget.cpp TextWidget.cpp SerialInterface.cpp FontManager.cpp StateManager.cpp TimerWidget.cpp TelemetryWidget.cpp UIWidget.cpp LogManager.cpp BMFontManager.cpp SPIInterface.cpp CircularGaugeWidget.cpp ShaderManager.cpp Shader.cpp Program.cpp ShadingProgramManager.cpp
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

.PHONY: depend clean	

all: $(OUT_DIR)/$(TARGET)
	@echo "Compiling..." 

$(OUT_DIR)/$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(OUT_DIR)/$(TARGET) $(OBJ) $(LIBS)
	
$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f -r $(OUT_DIR)
	mkdir -p $(OUT_DIR)
	rm -f -r $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)
	rm -f -r $(RES_DIR)
	mkdir -p $(RES_DIR)
	cp -r ./res/* $(RES_DIR)
	
depend: $(SRC)
	makedepend $(INCLUDES) S^
	



