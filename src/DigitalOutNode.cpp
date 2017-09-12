#include "Homie.hpp"
#include "DigitalOutNode.hpp"
#include <functional>

DigitalOutNode::DigitalOutNode(const char *id, const uint8_t pin, const uint8_t initialState)
		: ExtrasNode(id, "switch")
		,_pin(pin)
		,_initialState(initialState)
{
}

bool DigitalOutNode::outOnHandler(const HomieRange &range, const String &value)
{
	if (value != "true" && value != "false")
		return false;

	bool on = (value == "true");
	digitalWrite(_pin, on ? LOW : HIGH);
	_node->setProperty("on").send(value);

	Homie.getLogger() << _node->getId() << " is " << (on ? "on" : "off") << endl;
	return true;
}

void DigitalOutNode::setup()
{
	_node->advertise("on").settable(
			[this](const HomieRange &range, const String &value) {
				return outOnHandler(range, value);
			});
	pinMode(_pin, OUTPUT);
	digitalWrite(_pin, _initialState);
}