#include "DHTNode.hpp"

DHTNode::DHTNode(const char *id, const int interval, const uint8_t type, const uint8_t pin)
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