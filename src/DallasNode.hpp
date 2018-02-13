#pragma once

#include "Homie.h"
#include "OneWire.h"
#include "DallasTemperature.h"
#include "TemperatureNode.hpp"

class DallasNode : public TemperatureNode
{
public:
	DallasNode(const char *id, const int interval, const uint8_t pin);
	void setup();
	float getTemperature();

protected:
private:
	OneWire *_onewire;
	DallasTemperature *_dt;
};