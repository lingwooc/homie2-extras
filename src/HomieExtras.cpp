#include "HomieExtras.hpp"

std::vector<ExtrasNode *> HomieExtras::nodes;

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
	//Homie.getLogger() << "Loop" << endl;
	for (ExtrasNode *iNode : HomieExtras::nodes)
	{
		iNode->loopHandler();
	}
}