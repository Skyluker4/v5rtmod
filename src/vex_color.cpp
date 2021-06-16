#include "vex_color.h"

vex::color::color(int value, bool transparent) {}

vex::color::color() {}

vex::color::color(int value) {}

vex::color::color(uint8_t r, uint8_t g, uint8_t b) {}

vex::color::~color() {}

uint32_t
vex::color::rgb(uint32_t value) {
	uint32_t dummy;

	return dummy;
}

uint32_t
vex::color::rgb(uint8_t r, uint8_t g, uint8_t b) {
	uint32_t dummy;

	return dummy;
}

void vex::color::operator=(uint32_t value) {}

uint32_t
vex::color::rgb() const {
	uint32_t dummy;

	return dummy;
}

vex::color::operator uint32_t() const { return _argb; }

bool vex::color::isTransparent() const {
	bool dummy;

	return dummy;
}

vex::color&
vex::color::hsv(uint32_t hue, double sat, double value) {
	auto dummy = new color(0, 0, 0);
	return *dummy;
}

vex::color&
vex::color::web(const char* color) {
	auto dummy = new vex::color(0, 0, 0);
	return *dummy;
}
