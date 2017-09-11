#pragma once

#include "Homie.h"
#include "OneWire.h"
#include <DallasTemperature.h>
#include "TemperatureNode.hpp"

class DallasNode;

class DallasNode : public TemperatureNode
{
public:
	DallasNode(const char *id, const uint8_t pin, const int interval);
	void setupHandler();
	void loopHandler();	
	void setup();
	float getTemperature();

protected:
private:
	OneWire *_onewire;
	DallasTemperature *_dt;
};