#pragma once

#include "Homie.h"
#include "DHT_U.h"
#include "TemperatureNode.hpp"

class DHTNode;

class DHTNode : public TemperatureNode
{
public:
	DHTNode(const char *id, const uint8_t pin, const uint8_t type, const int interval);
	float getTemperature();	
	void setup();

protected:
private:
	DHT *_dht;
};