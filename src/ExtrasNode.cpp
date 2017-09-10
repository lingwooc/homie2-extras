#include "ExtrasNode.hpp"
#include "Homie.hpp"

using namespace HomieInternals;

ExtrasNode::~ExtrasNode()
{
	Helpers::abort(F("✖✖ ~HomieNode(): Destruction of HomieNode object not possible\n  Hint: Don't create HomieNode objects as a local variable (e.g. in setup())"));
	return; // never reached, here for clarity
}