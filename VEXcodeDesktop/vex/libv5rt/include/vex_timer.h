#ifndef VEX_TIMER_CLASS_H
#define VEX_TIMER_CLASS_H

#include "vex_units.h"
#include <cstdint>

namespace vex {

	class timer {
	  private:
		uint32_t _offset;
		uint32_t _initial;

	  public:
		timer();
		~timer();

		void operator=(uint32_t value);

		operator uint32_t() const;

		uint32_t time() const;
		double time(timeUnits units) const;

		double value() const;

		void clear();

		void reset();

		static uint32_t system();

		static uint64_t systemHighResolution();
		static void event(void (*callback)(void*), uint32_t value);
		static void event(void (*callback)(void), uint32_t value);
	};
} // namespace vex

#endif
