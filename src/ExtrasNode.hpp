#pragma once

#include "Homie.h"

class ExtrasNode;

class ExtrasNode
{
  public:
		~ExtrasNode();
		virtual void setup();
		virtual void loop();
  protected:
		HomieNode *_node;
  private:
};