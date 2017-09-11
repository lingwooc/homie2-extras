#pragma once

#include "Homie.h"
#include "ExtrasNode.hpp"

class BroadcastNode;

class BroadcastNode : public ExtrasNode
{
public:
	BroadcastNode(const char *id, const int interval, const char *unit);
	virtual float getValue() {}
	void setupHandler();
	void loopHandler();	
	void setup();

protected:
	unsigned long _lastSent = 0;
	const int _interval;
	const char *_unit;

private:

};