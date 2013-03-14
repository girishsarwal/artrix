#pragma once

#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <libxml/xmlreader.h>
#include "artrix-defines.h"
#include <vector>
#include <map>
#include <string>
struct Vector;

class View;
class SplashView;
class ViewManager;
class Widget;
class FlapsWidget;
class TXBatteryMeterWidget;
class ImageWidget;
class RenderContext;
class WidgetFactory;

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
#include "ImageWidget.h"
#include "RenderContext.h"
#include "ViewManager.h"

#include "WidgetFactory.h"

#define RC RenderContext::getInstance()
#define VM ViewManager::getInstance()
