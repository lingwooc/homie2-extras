#include "Homie.hpp"
#include "DigitalInEventNode.hpp"
#include <functional>
#define BOUNCE_LOCK_OUT

DigitalInEventNode::DigitalInEventNode(const char *id, const uint8_t pin)
	: EventNode(id, 0, "digital")
	,_pin(pin)
	,_state(false)
{
	_debouncer = new Bounce();
}

void DigitalInEventNode::loopHandler()
{
	bool value = _debouncer->read();
	if (value != _state)
	{
		sendValue(value ? 1.0 : 0.0);
		_state = value;
	}
}

void DigitalInEventNode::setup()
{
	pinMode(_pin, INPUT);
	_debouncer->attach(_pin);
	_debouncer->interval(50);
}