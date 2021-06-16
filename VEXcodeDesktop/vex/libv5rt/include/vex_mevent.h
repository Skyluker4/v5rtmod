#ifndef VEX_MEVENT_CLASS_H
#define VEX_MEVENT_CLASS_H

#include <cstdint>

namespace vex {
	class mevent {
	  private:
		int _event_id;
		int _index;

	  public:
		mevent()
			: _event_id(-1){};
		mevent(uint32_t index, uint32_t id);
		~mevent(){};

		operator int();
		operator bool();
	};
} // namespace vex

#endif
