#pragma once

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <time.h>
#include <sys/time.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
//#include <bcm_host.h>

#include <GL/glew.h>
#include <GL/glut.h>

#include <libxml/xmlreader.h>

#include <vector>
#include <map>
#include <string>

#include <dirent.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/ioctl.h>


#include "artrix-defines.h"
#include "SOIL.h"

struct Vector;
struct ProgramShader;

class View;
class SplashView;
class Renderable;
class ViewManager;
class Widget;
class UIWidget;
class TelemetryWidget;
class FlapsWidget;
class TXBatteryMeterWidget;
class AttitudeIndicatorWidget;
class ImageWidget;
class TimerWidget;
class RenderContext;
class WidgetFactory;
class TextureManager;
class TextWidget;
class SerialInterface;
class FontManager;
class StateManager;
class LogManager;
class IState;
class ISupportsStates;
class BMFontManager;
class SPIInterface;
class CircularGaugeWidget;

class ShaderManager;



/**Data types **/
#include "Vector.h"
#include "SharedAllocation.h"
#include "Attribute.h"

#include "View.h"
#include "Widget.h"



/** Some Views **/
#include "SplashView.h"

/** Widgets **/
#include "Widget.h"
#include "Renderable.h"
#include "UIWidget.h"
#include "TelemetryWidget.h"
#include "FlapsWidget.h"
#include "TxBatteryMeterWidget.h"
#include "AttitudeIndicatorWidget.h"
#include "ImageWidget.h"
#include "TimerWidget.h"
#include "RenderContext.h"
#include "ViewManager.h"

#include "WidgetFactory.h"
#include "TextureManager.h"
#include "LogManager.h"
#include "TextWidget.h"
#include "CircularGaugeWidget.h"
#include "SerialInterface.h"
#include "SPIInterface.h"
#include "FontManager.h"
#include "StateManager.h"
#include "SupportsStates.h"
#include "State.h"
#include "SupportsTelemetry.h"
#include "BMFontManager.h"
#include "ShaderManager.h"

#define RC RenderContext::getInstance()
#define VM ViewManager::getInstance()
#define TM TextureManager::getInstance()
#define SI SerialInterface::getInstance()
#define SPI SPIInterface::getInstance()
#define FM FontManager::getInstance()
#define SM StateManager::getInstance()
#define LM LogManager::getInstance()
#define BFM BMFontManager::getInstance()
#define SHM	ShaderManager::getInstance()

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]

