#include "vex_device.h"

vex::device::device() {}

vex::device::device(int32_t index) {}

vex::device::~device() {}

V5_DeviceType
vex::device::type() {
	V5_DeviceType dummy;

	return dummy;
}

int32_t
vex::device::index() {
	int32_t dummy;

	return dummy;
}

void vex::device::init(int32_t index) {}

bool vex::device::installed() {
	bool dummy;

	return dummy;
}

int32_t
vex::device::value() {
	int32_t dummy;

	return dummy;
}

vex::devices::devices() {}

vex::devices::~devices() {}

V5_DeviceType
vex::devices::type(int32_t index) {
	V5_DeviceType dummy;

	return dummy;
}

int32_t
vex::devices::number() {
	int32_t dummy;

	return dummy;
}

int32_t
vex::devices::numberOf(V5_DeviceType type) {
	int32_t dummy;

	return dummy;
}
