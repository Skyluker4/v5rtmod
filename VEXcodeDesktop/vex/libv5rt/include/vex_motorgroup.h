#ifndef VEX_MOTOR_GROUP_CLASS_H
#define VEX_MOTOR_GROUP_CLASS_H

#include "vex_device.h"
#include "vex_motor.h"
#include <cstdint>

namespace vex {

	class motor_group {
	  private:
		class motor_group_impl;

		class motor_group_motors {
			friend class motor_group;

		  private:
#define STATIC_MEMORY 16
			uintptr_t _memory[STATIC_MEMORY];
			motor_group_impl* pimpl;

		  public:
			motor_group_motors();
			~motor_group_motors();
		};

		int32_t _timeout;
		motor_group_motors _motors;

		void _addMotor();
		void _addMotor(motor& m);

		template <typename... Args>
		void _addMotor(motor& m1, Args&... m2) {
			_addMotor(m1);
			_addMotor(m2...);
		}

		bool waitForCompletionAll();

	  public:
		motor_group();
		~motor_group();

		template <typename... Args>
		motor_group(motor& m1, Args&... m2)
			: motor_group() {
			_addMotor(m1);
			_addMotor(m2...);
		}

		template <typename... Args>
		void operator()(motor& m1, Args&... m2) {
			_addMotor(m1);
			_addMotor(m2...);
		}

		int32_t count(void);

		void setVelocity(double velocity, velocityUnits units);

		void setVelocity(double velocity, percentUnits units) { setVelocity(velocity, static_cast<velocityUnits>(units)); };

		void setStopping(brakeType mode);

		void resetRotation(void);

		void resetPosition(void);

		void setRotation(double value, rotationUnits units);

		void setPosition(double value, rotationUnits units);

		void setTimeout(int32_t time, timeUnits units);

		void spin(directionType dir);

		void spin(directionType dir, double velocity, velocityUnits units);

		void spin(directionType dir, double velocity, percentUnits units) { spin(dir, velocity, static_cast<velocityUnits>(units)); };

		void spin(directionType dir, double voltage, voltageUnits units);

		bool rotateTo(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);

		bool spinTo(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);
		bool spinToPosition(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);

		bool rotateTo(double rotation, rotationUnits units, bool waitForCompletion = true);

		bool spinTo(double rotation, rotationUnits units, bool waitForCompletion = true);
		bool spinToPosition(double rotation, rotationUnits units, bool waitForCompletion = true);

		bool rotateFor(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);
		bool spinFor(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);

		bool rotateFor(directionType dir, double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);
		bool spinFor(directionType dir, double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);

		bool rotateFor(double rotation, rotationUnits units, bool waitForCompletion = true);
		bool spinFor(double rotation, rotationUnits units, bool waitForCompletion = true);

		bool rotateFor(directionType dir, double rotation, rotationUnits units, bool waitForCompletion = true);
		bool spinFor(directionType dir, double rotation, rotationUnits units, bool waitForCompletion = true);

		void rotateFor(double time, timeUnits units, double velocity, velocityUnits units_v);
		void spinFor(double time, timeUnits units, double velocity, velocityUnits units_v);

		void rotateFor(directionType dir, double time, timeUnits units, double velocity, velocityUnits units_v);
		void spinFor(directionType dir, double time, timeUnits units, double velocity, velocityUnits units_v);

		void rotateFor(double time, timeUnits units);
		void spinFor(double time, timeUnits units);

		void rotateFor(directionType dir, double time, timeUnits units);
		void spinFor(directionType dir, double time, timeUnits units);

		bool isSpinning(void);

		bool isDone(void);

		void stop(void);

		void stop(brakeType mode);

		void setMaxTorque(double value, percentUnits units);

		void setMaxTorque(double value, torqueUnits units);

		void setMaxTorque(double value, currentUnits units);

		directionType direction(void);

		double rotation(rotationUnits units);

		double position(rotationUnits units);

		double velocity(velocityUnits units);

		double velocity(percentUnits units) { return velocity(static_cast<velocityUnits>(units)); };

		double current(currentUnits units = currentUnits::amp);

		double current(percentUnits units);

		double power(powerUnits units = powerUnits::watt);

		double torque(torqueUnits units = torqueUnits::Nm);

		double efficiency(percentUnits units = percentUnits::pct);

		double temperature(percentUnits units = percentUnits::pct);

		double temperature(temperatureUnits units);
	};
} // namespace vex

#endif
