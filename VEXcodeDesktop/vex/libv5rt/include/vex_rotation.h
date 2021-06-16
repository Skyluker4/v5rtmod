#ifndef VEX_ABSENC_CLASS_H
#define VEX_ABSENC_CLASS_H

#include "vex_device.h"

namespace vex {

	class rotation : public device {
	  public:
		rotation(int32_t index, bool reverse = false);
		~rotation() override;

		bool installed() override;
		int32_t value() override;

		void setReversed(bool value);

		double angle(rotationUnits units = rotationUnits::deg);

		void resetPosition(void);

		void setPosition(double value, rotationUnits units);

		double position(rotationUnits units);

		double velocity(velocityUnits units);

		enum class tEventType {
			EVENT_ANGLE_CHANGED = 0
		};

		void changed(void (*callback)(void));

	  protected:
		int32_t status();

		double temperature();
	};
}; // namespace vex

#endif
