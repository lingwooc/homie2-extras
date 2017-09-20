// #include "Homie.hpp"
// #include "RFIDNode.hpp"

// RFIDNode::RFIDNode(const char *id, const uint8_t SS_PIN, const uint8_t RST_PIN)
// 	: ExtrasNode(id, "switch")
// {
// 	_mfrc522 = new MFFRC522(SS_PIN, RST_PIN);
// }

// bool RFIDNode::relayOnHandler(const HomieRange &range, const String &value)
// {
// 	if (value != "true" && value != "false")
// 		return false;

// 	bool on = (value == "true");
// 	digitalWrite(_pin, on ? LOW : HIGH);
// 	_node->setProperty("on").send(value);

// 	Homie.getLogger() << _node->getId() << " is " << (on ? "on" : "off") << endl;
// 	return true;
// }

// void RFIDNode::setup()
// {
// 	SPI.begin();		// MFRC522 Hardware uses SPI protocol
// 	mfrc522.PCD_Init(); // Initialize MFRC522 Hardware

// 	//If you set Antenna Gain to Max it will increase reading distance
// 	mfrc522.PCD_SetAntennaGain(mfrc522.RxGain_max);
// }

// void RFIDNode::loopHandler()
// {
// 	if (!mfrc522.PICC_IsNewCardPresent())
// 		return;

// 	if (!mfrc522.PICC_ReadCardSerial())
// 		return;

// 	Serial.println(F("Scanned PICC's UID:"));
// 	for (uint8_t i = 0; i < 4; i++)
// 	{
// 		readCard[i] = mfrc522.uid.uidByte[i];
// 		Serial.print(readCard[i], HEX);
// 	}
// 	mfrc522.PICC_HaltA(); // Stop reading
// }