#pragma once

#include "HomieExtras.hpp"
#include "Homie.hpp"
#include "ExtrasNode.hpp"

class RelayNode;

class RelayNode : public ExtrasNode
{
public:
	RelayNode(const char *id, const uint8_t pinHomieNode, const uint8_t initialState);
	virtual void setup();

protected:
	virtual bool relayOnHandler(const HomieRange &range, const String &value);

private:
	const uint8_t _pin;
	HomieNode *_node;
	const uint8_t _initialState;
};