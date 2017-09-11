#include "DHTNode.hpp"
#include "HomieExtras.hpp"

DHTNode::DHTNode(const char *id, const uint8_t pin, const uint8_t type, const int interval) : _interval(interval), _pin(pin)
{
	_node = new HomieNode(id, "temperature");
	_dht = new DHT(pin, type);
}

void DHTNode::loopHandler()
{
	if (millis() - _lastTemperatureSent >= _interval * 1000UL || _lastTemperatureSent == 0)
	{
		float temperature = _dht->readTemperature();
		Homie.getLogger() << "Temperature: " << temperature << " °C" << endl;
		_node->setProperty("degrees").send(String(temperature));
		_lastTemperatureSent = millis();
	}
}

void DHTNode::setupHandler()
{
	_node->setProperty("unit").send("c");
}

void DHTNode::setup()
{
	_node->advertise("unit");
	_node->advertise("degrees");
	_node->setProperty("unit").send("c");

	_dht->begin();
}