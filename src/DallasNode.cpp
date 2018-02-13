#include <DallasNode.hpp>

DallasNode::DallasNode(const char *id, const int interval, const uint8_t pin)
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
	_dt->setResolution(12);
}