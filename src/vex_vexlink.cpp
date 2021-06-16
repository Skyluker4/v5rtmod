#include "vex_vexlink.h"

vex::vexlink::vexlink(int32_t index, const char* name, linkType type, bool isWired) {}

vex::vexlink::~vexlink() {}

bool vex::vexlink::installed() {
	bool dummy;

	return dummy;
}

bool vex::vexlink::isLinked() {
	bool dummy;

	return dummy;
}

bool vex::vexlink::isReceiving() {
	bool dummy;

	return dummy;
}

vex::vexlink::vexlink(int32_t index) {}

int32_t
vex::vexlink::debug(int32_t id) {
	int32_t dummy;

	return dummy;
}

void vex::vexlink::baud(int32_t baudrate) {}

uint32_t
vex::vexlink::crc32(uint8_t* pData, uint32_t numberOfBytes, uint32_t accumulator) {
	uint32_t dummy;

	return dummy;
}

uint32_t
vex::vexlink::strcrc32(const char* str) {
	uint32_t dummy;

	return dummy;
}

vex::serial_link::serial_link(int32_t index, const char* name, linkType type, bool isWired)
	: vexlink{
		  index, name, type, isWired} {}

vex::serial_link::~serial_link() {}

int32_t
vex::serial_link::send(uint8_t* buffer, int32_t length) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::serial_link::receive(uint8_t* buffer, int32_t length, int32_t timeoutMs) {
	int32_t dummy;

	return dummy;
}

void vex::serial_link::_eventHandler(void* arg) {}

void vex::serial_link::_eventHandler() {}

vex::message_link::message_link(int32_t index, const char* name, linkType type, bool isWired)
	: vexlink{
		  index, name, type, isWired} {}

vex::message_link::~message_link() {}

int32_t
vex::message_link::send(const char* message) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::message_link::send(const char* message, double value) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::message_link::send(const char* message, int32_t index, double value) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::message_link::receive(char* message, int32_t length, int32_t timeoutMs) {
	int32_t dummy;

	return dummy;
}

void vex::message_link::_eventHandler(void* arg) {}

void vex::message_link::_eventHandler() {}

void vex::message_link::_addMessageHandler(const char* message, void* callback, int32_t type) {}
