#ifndef VEX_MOTOR_CLASS_H
#define VEX_MOTOR_CLASS_H

#include "vex_device.h"

namespace vex {

	class motor : public device {
	  public:
		motor(int32_t index);
		~motor() override;

		bool installed() override;
		int32_t value() override;
		motor(int32_t index, bool reverse);
		motor(int32_t index, gearSetting gears);
		motor(int32_t index, gearSetting gears, bool reverse);
		void setReversed(bool value);
		void setVelocity(double velocity, velocityUnits units);
		void setVelocity(double velocity, percentUnits units) { setVelocity(velocity, static_cast<velocityUnits>(units)); };

		void setBrake(brakeType mode);
		void setStopping(brakeType mode);

		void resetRotation(void);

		void resetPosition(void);
		void setRotation(double value, rotationUnits units);
		void setPosition(double value, rotationUnits units);
		void setTimeout(int32_t time, timeUnits units);
		void spin(directionType dir);
		void spin(directionType dir, double velocity, velocityUnits units);

		void spin(directionType dir, double velocity, percentUnits units) { spin(dir, velocity, static_cast<velocityUnits>(units)); }
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
		bool rotateFor(double time, timeUnits units, double velocity, velocityUnits units_v);
		bool spinFor(double time, timeUnits units, double velocity, velocityUnits units_v);

		bool rotateFor(directionType dir, double time, timeUnits units, double velocity, velocityUnits units_v);
		bool spinFor(directionType dir, double time, timeUnits units, double velocity, velocityUnits units_v);
		bool rotateFor(double time, timeUnits units);
		bool spinFor(double time, timeUnits units);

		bool rotateFor(directionType dir, double time, timeUnits units);
		bool spinFor(directionType dir, double time, timeUnits units);
		void startRotateTo(double rotation, rotationUnits units, double velocity, velocityUnits units_v);
		void startSpinTo(double rotation, rotationUnits units, double velocity, velocityUnits units_v);
		void startRotateTo(double rotation, rotationUnits units);
		void startSpinTo(double rotation, rotationUnits units);
		void startRotateFor(double rotation, rotationUnits units, double velocity, velocityUnits units_v);
		void startSpinFor(double rotation, rotationUnits units, double velocity, velocityUnits units_v);

		void startRotateFor(directionType dir, double rotation, rotationUnits units, double velocity, velocityUnits units_v);
		void startSpinFor(directionType dir, double rotation, rotationUnits units, double velocity, velocityUnits units_v);
		void startRotateFor(double rotation, rotationUnits units);
		void startSpinFor(double rotation, rotationUnits units);

		void startRotateFor(directionType dir, double rotation, rotationUnits units);
		void startSpinFor(directionType dir, double rotation, rotationUnits units);
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

	  protected:
		int32_t getTimeout();

	  private:
		int32_t _timeout;
		int32_t _velocity;
		brakeType _mode;
		brakeType _brakeMode;
		bool _spinMode;

		void defaultStopping(brakeType mode);

		void setRotationUnits(rotationUnits units);
		double velocityToScaled(double velocity, velocityUnits units);
		int32_t scaledToVelocity(double value, velocityUnits units);
		double torqueToCurrent(double torque);
	};
}; // namespace vex

#endif
