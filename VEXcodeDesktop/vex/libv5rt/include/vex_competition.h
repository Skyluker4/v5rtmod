#ifndef VEX_COMPETITION_CLASS_H
#define VEX_COMPETITION_CLASS_H

#include "vex_brain.h"
#include "vex_mevent.h"
#include <cstdint>

namespace vex {

	class competition {
	  private:
		int32_t _index;
		static bool _auton_pending;
		static bool _driver_pending;

		static void (*_initialize_callback)(void);
		static void (*_autonomous_callback)(void);
		static void (*_drivercontrol_callback)(void);

		static void _disable(void* arg);
		static void _autonomous(void);
		static void _drivercontrol(void);

		bool _globalInstance;

	  protected:
		int32_t _getIndex();

	  public:
		competition();
		~competition();

		enum class tEventType {
			EVENT_INITIALIZE = 8,
			EVENT_AUTONOMOUS = 9,
			EVENT_DRIVER_CTL = 10,
			EVENT_DISABLE = 11
		};

		void autonomous(void (*callback)(void));
		void drivercontrol(void (*callback)(void));
		bool isEnabled();
		bool isDriverControl();
		bool isAutonomous();
		bool isCompetitionSwitch();
		bool isFieldControl();

		void test_auton(void);
		void test_driver(void);
		void test_disable(void);

		mevent PRE_AUTONOMOUS = {static_cast<uint32_t>(brain::_getIndex()), static_cast<int32_t>(tEventType::EVENT_INITIALIZE)};
		mevent AUTONOMOUS = {static_cast<uint32_t>(brain::_getIndex()), static_cast<int32_t>(tEventType::EVENT_AUTONOMOUS)};
		mevent DRIVER_CONTROL = {static_cast<uint32_t>(brain::_getIndex()), static_cast<int32_t>(tEventType::EVENT_DRIVER_CTL)};
		mevent DISABLED = {static_cast<uint32_t>(brain::_getIndex()), static_cast<int32_t>(tEventType::EVENT_DISABLE)};

		static bool bStopTasksBetweenModes;

		static bool bStopAllTasksBetweenModes;
	};
}; // namespace vex

#endif
