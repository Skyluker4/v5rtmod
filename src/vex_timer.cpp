#include "vex_timer.h"

vex::timer::timer() {}

vex::timer::~timer() {}

void vex::timer::operator=(uint32_t value) {}

vex::timer::operator uint32_t() const { return _offset; }

uint32_t
vex::timer::time() const {
	uint32_t dummy;

	return dummy;
}

double
vex::timer::time(timeUnits units) const {
	double dummy;

	return dummy;
}

double
vex::timer::value() const {
	double dummy;

	return dummy;
}

void vex::timer::clear() {}

void vex::timer::reset() {}

uint32_t
vex::timer::system() {
	uint32_t dummy;

	return dummy;
}

uint64_t
vex::timer::systemHighResolution() {
	uint64_t dummy;

	return dummy;
}
