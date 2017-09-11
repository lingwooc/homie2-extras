#include "Homie.hpp"
#include "RelayNode.hpp"
#include <functional>

RelayNode::RelayNode(const char *id, const uint8_t pin, const uint8_t initialState)
		: _pin(pin), _initialState(initialState)
{
	_node = new HomieNode(id, "switch");
}

bool RelayNode::relayOnHandler(const HomieRange &range, const String &value)
{
	if (value != "true" && value != "false")
		return false;

	bool on = (value == "true");
	digitalWrite(_pin, on ? LOW : HIGH);
	_node->setProperty("on").send(value);

	Homie.getLogger() << _node->getId() << " is " << (on ? "on" : "off") << endl;
	return true;
}

void RelayNode::setup()
{
	_node->advertise("on").settable(
			[this](const HomieRange &range, const String &value) {
				return relayOnHandler(range, value);
			});
	pinMode(_pin, OUTPUT);
	digitalWrite(_pin, HIGH);
}