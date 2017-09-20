#include "DigitalInBroadcastNode.hpp"
#include <functional>

DigitalInBroadcastNode::DigitalInBroadcastNode(const char *id, const int interval, const uint8_t pin)
		: BroadcastNode(id, interval, "digital")
		,_pin(pin)
{
	_debouncer = new Bounce(); 	
}

float DigitalInBroadcastNode::getValue()
{
	_debouncer->update();
	return (float)_debouncer->read();
}

void DigitalInBroadcastNode::setup() {
	pinMode(_pin, INPUT_PULLUP);
	_debouncer->attach(_pin);
	_debouncer->interval(50);	
}
