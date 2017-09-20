#include "DigitalInEventNode.hpp"
#include <functional>

DigitalInEventNode::DigitalInEventNode(const char *id, const uint8_t pin)
	: EventNode(id, 0, "digital")
	,_pin(pin)
	,_state(false)
{
	_debouncer = new Bounce();
}

void DigitalInEventNode::loopHandler()
{
	_debouncer->update();
	bool value = _debouncer->read();
	
	if (value != _state)
	{
		Homie.getLogger() << "Button is now" << (value ? "pressed" : "not pressed") << endl;
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