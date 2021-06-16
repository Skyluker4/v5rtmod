#ifndef VEX_CONSOLE_CLASS_H
#define VEX_CONSOLE_CLASS_H

#include "vex_brain.h"
#include <cstdint>

namespace vex {
	class console : public brain {
	  public:
		console();
		~console();

		void init();

	  private:
		static int32_t write(int32_t fd, char* buf, int32_t nbytes);
	};
} // namespace vex

#endif
