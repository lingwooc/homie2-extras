#pragma once

#include "HomieExtras.hpp"
#include "Homie.hpp"
#include "ExtrasNode.hpp"

class DigitalOutNode;

class DigitalOutNode : public ExtrasNode
{
public:
	DigitalOutNode(const char *id, const uint8_t pin, const uint8_t initialState);
	virtual void setup();

protected:
	virtual bool outOnHandler(const HomieRange &range, const String &value);

private:
	const uint8_t _pin;
	const bool _initialState;
};