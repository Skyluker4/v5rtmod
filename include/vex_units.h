#ifndef VEX_UNITS_H
#define VEX_UNITS_H

#include "v5_apitypes.h"

namespace vex {

	enum class percentUnits {

		pct = 0
	};

	enum class timeUnits {

		sec,

		msec
	};

	enum class currentUnits {

		amp
	};

	enum class voltageUnits {

		volt,

		mV
	};

	enum class powerUnits {

		watt
	};

	enum class torqueUnits {

		Nm,

		InLb
	};

	enum class rotationUnits {

		deg,

		rev,

		raw = 99
	};

	enum class velocityUnits {

		pct = static_cast<int>(percentUnits::pct),

		rpm,

		dps
	};

	enum class distanceUnits {

		mm,

		in,

		cm
	};

	enum class analogUnits {

		pct = static_cast<int>(percentUnits::pct),

		range8bit,

		range10bit,

		range12bit,

		mV
	};

	enum class temperatureUnits {

		celsius,

		fahrenheit
	};

	enum class directionType {

		fwd = 0,

		rev,
		undefined
	};

	enum class turnType {

		left,

		right
	};

	enum class brakeType {

		coast = kV5MotorBrakeModeCoast,

		brake = kV5MotorBrakeModeBrake,

		hold = kV5MotorBrakeModeHold,
		undefined
	};

	enum class gearSetting {

		ratio36_1 = kMotorGearSet_36,

		ratio18_1 = kMotorGearSet_18,

		ratio6_1 = kMotorGearSet_06
	};

	enum class fontType {

		mono20 = 0,

		mono30,

		mono40,

		mono60,

		prop20,

		prop30,

		prop40,

		prop60,

		mono15,

		mono12,

		cjk16
	};

	enum class triportType {

		analogInput,

		analogOutput,

		digitalInput,

		digitalOutput,

		button,

		potentiometer,

		lineSensor,

		lightSensor,

		gyro,

		accelerometer,

		motor,

		servo,

		quadEncoder,

		sonar,

		motorS,
	};

	enum class controllerType {

		primary = kControllerMaster,

		partner = kControllerPartner
	};

	enum class axisType {
		xaxis,
		yaxis,
		zaxis
	};

	enum class orientationType {
		roll,
		pitch,
		yaw
	};

	enum class linkType {
		undefined,

		master,

		slave,

		raw
	};
}; // namespace vex

#endif
