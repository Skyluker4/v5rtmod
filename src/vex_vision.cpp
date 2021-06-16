#include "vex_vision.h"

vex::vision::vision(int32_t index) {}

vex::vision::~vision() {}

bool vex::vision::installed() {
	bool dummy;

	return dummy;
}

int32_t
vex::vision::value() {
	int32_t dummy;

	return dummy;
}

vex::vision::object::object()
	: id{_id},
	  originX{_originX},
	  originY{_originY},
	  centerX{_centerX},
	  centerY{_centerY},
	  width{_width},
	  height{_height},
	  angle{_angle},
	  exists{_exists} {}

vex::vision::object::~object() {}

void vex::vision::object::set(V5_DeviceVisionObject obj) {}

void vex::vision::object::flipAngle() {}

void vex::vision::object::clear() {}

vex::vision::object&
vex::vision::object::operator=(const object& obj) { return *this; }

vex::vision::object&
vex::vision::object::operator=(int32_t signatureId) { return *this; }

void vex::vision::signature::clear() {}

vex::vision::signature::signature()
	: id{_id},
	  uMin{_uMin},
	  uMax{_uMax},
	  uMean{_uMean},
	  vMin{_vMin},
	  vMax{_vMax},
	  vMean{_vMean},
	  range{_range},
	  rgb{_rgb},
	  type{_type} {}

vex::vision::signature::~signature() {}

vex::vision::signature::signature(int32_t id, int32_t uMin, int32_t uMax, int32_t uMean, int32_t vMin, int32_t vMax, int32_t vMean, float range, int32_t type)
	: id{_id},
	  uMin{_uMin},
	  uMax{_uMax},
	  uMean{_uMean},
	  vMin{_vMin},
	  vMax{_vMax},
	  vMean{_vMean},
	  range{_range},
	  rgb{_rgb},
	  type{_type} {}

vex::vision::code::code(int32_t sig1, int32_t sig2) {}

vex::vision::code::code(int32_t sig1, int32_t sig2, int32_t sig3) {}

vex::vision::code::code(int32_t sig1, int32_t sig2, int32_t sig3, int32_t sig4) {}

vex::vision::code::code(int32_t sig1, int32_t sig2, int32_t sig3, int32_t sig4, int32_t sig5) {}

vex::vision::code::code(signature& s1, signature& s2) {}

vex::vision::code::code(signature& s1, signature& s2, signature& s3) {}

vex::vision::code::code(signature& s1, signature& s2, signature& s3, signature& s4) {}

vex::vision::code::code(signature& s1, signature& s2, signature& s3, signature& s4, signature& s5) {}

int32_t
vex::vision::takeSnapshot(uint32_t id) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::vision::takeSnapshot(code& cc) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::vision::takeSnapshot(signature& sig) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::vision::takeSnapshot(uint32_t id, uint32_t count) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::vision::takeSnapshot(code& cc, uint32_t count) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::vision::takeSnapshot(signature& sig, uint32_t count) {
	int32_t dummy;

	return dummy;
}

bool vex::vision::setSignature(V5_DeviceVisionSignature* pSignature) {
	bool dummy;

	return dummy;
}

bool vex::vision::getSignature(uint32_t id, V5_DeviceVisionSignature* pSignature) {
	bool dummy;

	return dummy;
}

bool vex::vision::setSignature(signature& sig) {
	bool dummy;

	return dummy;
}

bool vex::vision::getSignature(uint32_t id, signature& sig) {
	bool dummy;

	return dummy;
}

bool vex::vision::setMode(detectionMode mode) {
	bool dummy;

	return dummy;
}

vex::vision::detectionMode
vex::vision::getMode(void) {
	detectionMode dummy;

	return dummy;
}

bool vex::vision::setBrightness(uint8_t value) {
	bool dummy;

	return dummy;
}

uint8_t
vex::vision::getBrightness(void) {
	uint8_t dummy;

	return dummy;
}

bool vex::vision::setWhiteBalanceMode(whiteBalanceMode mode) {
	bool dummy;

	return dummy;
}

vex::vision::whiteBalanceMode
vex::vision::getWhiteBalanceMode(void) {
	whiteBalanceMode dummy;

	return dummy;
}

bool vex::vision::setWhiteBalanceValues(uint8_t red, uint8_t green, uint8_t blue) {
	bool dummy;

	return dummy;
}

bool vex::vision::getWhiteBalanceValues(uint8_t* red, uint8_t* green, uint8_t* blue) {
	bool dummy;

	return dummy;
}

bool vex::vision::setLedMode(ledMode mode) {
	bool dummy;

	return dummy;
}

vex::vision::ledMode
vex::vision::getLedMode(void) {
	ledMode dummy;

	return dummy;
}

bool vex::vision::setLedBrightness(uint8_t percent) {
	bool dummy;

	return dummy;
}

uint8_t
vex::vision::getLedBrightness(void) {
	uint8_t dummy;

	return dummy;
}

bool vex::vision::setLedColor(uint8_t red, uint8_t green, uint8_t blue) {
	bool dummy;

	return dummy;
}

bool vex::vision::getLedColor(uint8_t* red, uint8_t* green, uint8_t* blue) {
	bool dummy;

	return dummy;
}

bool vex::vision::setWifiMode(wifiMode mode) {
	bool dummy;

	return dummy;
}

vex::vision::wifiMode
vex::vision::getWifiMode(void) {
	wifiMode dummy;

	return dummy;
}

void vex::vision::_clearObjects(void) {}
