#include "DHTNode.hpp"
#include "HomieExtras.hpp"

DHTNode::DHTNode(const char *id, const uint8_t pin, const uint8_t type, const int interval)
	: TemperatureNode(id, interval)
{
	_dht = new DHT(pin, type);
}

float DHTNode::getTemperature()
{
	return _dht->readTemperature();
}

void DHTNode::setup()
{
	TemperatureNode::setup();
	_dht->begin();
}