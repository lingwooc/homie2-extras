#include <OneWireNode.hpp>

#include "HomieExtras.hpp"

DallasNode::DallasNode(const char *id, const uint8_t pin, const int interval)
	: TemperatureNode(id, interval)
{
	_onewire = new OneWire(pin);
	_dt = new DallasTemperature(_onewire);
}

float DallasNode::getTemperature()
{
	_dt->requestTemperatures();
	return _dt->getTempCByIndex(0);
}

void DallasNode::setup()
{
	TemperatureNode::setup();
	_dt->begin();
}