#pragma once

#include "Arduino.h"
#include "Homie.h"

#include "DHTNode.hpp"
#include "DigitalOutNode.hpp"
#include "DigitalOutNode.hpp"
#include "DallasNode.hpp"

class HomieExtras;

class HomieExtras
{
friend class ExtrasNode;
public:
	static void setup();
	static void loop();
	static void setupHandler();
	static void loopHandler();

protected:
	static std::vector<ExtrasNode*> nodes;	
	
private:
};