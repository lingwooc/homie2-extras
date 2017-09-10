#include "ExtrasNode.hpp"
#include "Homie.hpp"

using namespace HomieInternals;

ExtrasNode::~ExtrasNode()
{
	Helpers::abort(F("✖✖ ~ExtrasNode(): Destruction of ExtrasNode object not possible\n  Hint: Don't create ExtrasNode objects as a local variable (e.g. in setup())"));
	return; // never reached, here for clarity
}