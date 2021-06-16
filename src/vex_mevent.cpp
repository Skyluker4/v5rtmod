#include "vex_mevent.h"

vex::mevent::mevent(uint32_t index, uint32_t id) {}

vex::mevent::operator int() { return _event_id; }

vex::mevent::operator bool() { return _event_id; }
