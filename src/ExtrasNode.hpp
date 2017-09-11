#pragma once

#include "Homie.h"

class ExtrasNode;

class ExtrasNode
{
public:
	ExtrasNode(const char *id, const char *style);
	~ExtrasNode();
	virtual void setup() {}
	virtual void loop() {}
	virtual void loopHandler() {}
	virtual void setupHandler() {}

protected:
	HomieNode *_node;

private:
	void init();
};