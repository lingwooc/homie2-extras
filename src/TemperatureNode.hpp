#pragma once

#include "Homie.h"
#include "BroadcastNode.hpp"

class TemperatureNode;

class TemperatureNode : public BroadcastNode
{
public:
	TemperatureNode(const char *id, const int interval);
	virtual float getTemperature() {}
	float getValue();

protected:

private:

};