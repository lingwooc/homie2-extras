#include "TemperatureNode.hpp"
#include "HomieExtras.hpp"

BroadcastNode::BroadcastNode(const char *id, const int interval, const char *unit) 
: ExtrasNode(id, "temperature")
,_interval(interval)
,_unit(unit)
{
}

void BroadcastNode::loopHandler()
{
	if (millis() - _lastSent >= _interval * 1000UL || _lastSent == 0)
	{
		float value = getValue();
		Homie.getLogger() << _node->getId() << ": " << value << " " << _unit << endl;
		_node->setProperty(_node->getType()).send(String(value));
		_lastSent = millis();
	}
}

void BroadcastNode::setupHandler()
{
	_node->setProperty("unit").send(_unit);
}

void BroadcastNode::setup()
{
	_node->advertise("unit");
	_node->advertise(_node->getType());
}