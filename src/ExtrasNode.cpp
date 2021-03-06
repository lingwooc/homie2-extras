#include "ExtrasNode.hpp"
#include "Homie.hpp"
#include "HomieExtras.hpp"
using namespace HomieInternals;

ExtrasNode::ExtrasNode(const char *id, const char *type)
{
	_node = new HomieNode(id, type);
	init();
}

ExtrasNode::~ExtrasNode()
{
	Helpers::abort(F("✖✖ ~ExtrasNode(): Destruction of ExtrasNode object not possible\n  Hint: Don't create ExtrasNode objects as a local variable (e.g. in setup())"));
	return; // never reached, here for clarity
}

void ExtrasNode::init()
{
	HomieExtras::nodes.push_back(this);
}