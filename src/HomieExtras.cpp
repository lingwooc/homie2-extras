#include "HomieExtras.hpp"

std::vector<ExtrasNode *> HomieExtras::nodes;

void HomieExtras::loop()
{
	for (ExtrasNode *iNode : HomieExtras::nodes)
	{
		iNode->loop();
	}
}

void HomieExtras::setup()
{
	Homie.setSetupFunction(HomieExtras::setupHandler).setLoopFunction(HomieExtras::loopHandler);	
	for (ExtrasNode *iNode : HomieExtras::nodes)
	{
		iNode->setup();
	}
}

void HomieExtras::setupHandler()
{
	for (ExtrasNode *iNode : HomieExtras::nodes)
	{
		iNode->setupHandler();
	}
}

void HomieExtras::loopHandler()
{
	for (ExtrasNode *iNode : HomieExtras::nodes)
	{
		iNode->loopHandler();
	}
}