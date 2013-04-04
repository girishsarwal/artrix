#pragma once

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <time.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

#include <GL/glut.h>
#include <libxml/xmlreader.h>

#include <vector>
#include <map>
#include <string>

#include <dirent.h>


#include "artrix-defines.h"
#include "SOIL.h"

struct Vector;

class View;
class SplashView;
class ViewManager;
class Widget;
class FlapsWidget;
class TXBatteryMeterWidget;
class AttitudeIndicatorWidget;
class ImageWidget;
class RenderContext;
class WidgetFactory;
class TextureManager;
class TextWidget;
class SerialInterface;
class FontManager;

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
#include "FlapsWidget.h"
#include "TxBatteryMeterWidget.h"
#include "AttitudeIndicatorWidget.h"
#include "ImageWidget.h"
#include "RenderContext.h"
#include "ViewManager.h"

#include "WidgetFactory.h"
#include "TextureManager.h"
#include "TextWidget.h"
#include "SerialInterface.h"
#include "FontManager.h"

#define RC RenderContext::getInstance()
#define VM ViewManager::getInstance()
#define TM TextureManager::getInstance()
#define SI SerialInterface::getInstance()
#define FM FontManager::getInstance()


