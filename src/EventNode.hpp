#pragma once

#include "Homie.h"
#include "BroadcastNode.hpp"

class EventNode;

class EventNode : public BroadcastNode
{
public:
	EventNode(const char *id, const int interval, const char *unit);
	void sendValue(float value);
	void loopHandler() {};	

protected:

private:

};