#pragma once

#include "HomieExtras.hpp"
#include "Homie.hpp"
#include "BroadcastNode.hpp"

class DigitalInBroadcastNode;

class DigitalInBroadcastNode : public BroadcastNode
{
public:
	DigitalInBroadcastNode(const char *id, const int interval, const uint8_t pin);
	float getValue();
	void setup();

protected:

private:
	const uint8_t _pin;
	Bounce *_debouncer; 	
};