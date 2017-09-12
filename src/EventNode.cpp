#include "EventNode.hpp"

EventNode::EventNode(const char *id, const int interval, const char *unit) 
: BroadcastNode(id, interval, "temperature")
{
}

void EventNode::sendValue(float value)
{
	_node->setProperty(_node->getType()).send(String(value));
}