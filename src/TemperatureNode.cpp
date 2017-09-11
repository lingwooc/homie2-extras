#include "TemperatureNode.hpp"
#include "HomieExtras.hpp"

TemperatureNode::TemperatureNode(const char *id, const int interval)
: BroadcastNode(id,interval,"C")
{
}

float TemperatureNode::getValue()
{
	return getTemperature();
}