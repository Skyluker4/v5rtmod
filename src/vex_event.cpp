#include "vex_event.h"

vex::event::event() {}

vex::event::~event() {}

int32_t
vex::event::userindex(void) {
	int32_t dummy;

	return dummy;
}

void vex::event::broadcast() {}

void vex::event::broadcastAndWait(int32_t timeout) {}

void vex::event::broadcast(uint32_t index) {}

void vex::event::broadcastAndWait(uint32_t index, int32_t timeout) {}
