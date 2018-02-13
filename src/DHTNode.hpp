#pragma once

#include "Homie.h"
#include "DHT_U.h"
#include "TemperatureNode.hpp"

class DHTNode;

class DHTNode : public TemperatureNode
{
public:
	DHTNode(const char *id, const int interval, const uint8_t type, const uint8_t pin);
	float getTemperature();	
	void setup();

protected:
private:
	DHT *_dht;
};