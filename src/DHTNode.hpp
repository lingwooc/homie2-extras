#pragma once

#include "Homie.h"
#include "DHT_U.h"
#include "ExtrasNode.hpp"

class DHTNode;

class DHTNode : public ExtrasNode
{
public:
	DHTNode(const char *id, const uint8_t pin, const uint8_t type, const int interval);
	void setupHandler();
	void loopHandler();	
	void setup();

protected:
private:
	const uint8_t _pin;
	DHT *_dht;
	unsigned long _lastTemperatureSent = 0;
	const int _interval;
};