#ifndef SUPPORTSTELEMETRY_H
#define SUPPORTSTELEMETRY_H
#include "afx.h"
class SupportsTelemetry {
	public:
		virtual void InitializeSensors() = 0;
		virtual void GetValuesFromSensors() = 0;
};
#endif
