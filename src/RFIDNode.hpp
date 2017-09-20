// #pragma once

// #include "HomieExtras.hpp"
// #include "ExtrasNode.hpp"
// #include "SPI.h"
// #include "MFRC522.h"

// class RFIDNode;

// class RFIDNode : public ExtrasNode
// {
// public:
// 	RFIDNode(const char *id, const uint8_t pin, const uint8_t initialState);
// 	virtual void setup();
// 	void loopHandler();

// protected:
// 	virtual bool relayOnHandler(const HomieRange &range, const String &value);

// private:
// 	MFRC522 *_mfrc522;
// 	byte readCard[4]; 
// };