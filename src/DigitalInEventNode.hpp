#pragma once

#include "HomieExtras.hpp"
#include "Homie.hpp"
#include "EventNode.hpp"

class DigitalInEventNode;

class DigitalInEventNode : public EventNode
{
public:
	DigitalInEventNode(const char *id, const uint8_t pin);
	void loopHandler();
	void setup();

protected:

private:
	const uint8_t _pin;
	bool _state;
	Bounce *_debouncer; 
};