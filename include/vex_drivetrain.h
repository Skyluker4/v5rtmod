#ifndef VEX_DRIVETRAIN_CLASS_H
#define VEX_DRIVETRAIN_CLASS_H

#include "vex_motorgroup.h"

namespace vex {

	class drivetrain {
	  private:
		motor_group lm;
		motor_group rm;

		double _wheel_circumference;
		double _wheel_track;
		double _wheel_base;
		double _wheel_motor_gear_ratio;

		int32_t _timeout;
		bool _waitForCompletionAll();
		double _distanceToRevs(double distance, distanceUnits units);
		double _angleToRevs(double angle, rotationUnits units);

	  public:
		drivetrain(motor_group& l, motor_group& r, double wheelTravel = 320, double trackWidth = 320, double wheelBase = 130, distanceUnits unit = distanceUnits::mm, double externalGearRatio = 1.0);
		drivetrain(motor& l, motor& r, double wheelTravel = 320, double trackWidth = 320, double wheelBase = 130, distanceUnits unit = distanceUnits::mm, double externalGearRatio = 1.0);

		virtual ~drivetrain();

		void setGearRatio(double ratio);

		void setDriveVelocity(double velocity, velocityUnits units);

		void setDriveVelocity(double velocity, percentUnits units);

		void setTurnVelocity(double velocity, velocityUnits units);

		void setTurnVelocity(double velocity, percentUnits units);

		void setTimeout(int32_t time, timeUnits units);

		void setStopping(brakeType mode);

		void drive(directionType dir);

		void drive(directionType dir, double velocity, velocityUnits units);
		bool driveFor(double distance, distanceUnits units, bool waitForCompletion = true);

		bool driveFor(directionType dir, double distance, distanceUnits units, bool waitForCompletion = true);
		bool driveFor(double distance, distanceUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);

		bool driveFor(directionType dir, double distance, distanceUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);

		void turn(turnType dir);

		void turn(turnType dir, double velocity, velocityUnits units);
		virtual bool turnFor(double angle, rotationUnits units, bool waitForCompletion = true);

		virtual bool turnFor(turnType dir, double angle, rotationUnits units, bool waitForCompletion = true);
		virtual bool turnFor(double angle, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);

		virtual bool turnFor(turnType dir, double angle, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);

		virtual bool isMoving(void);

		bool isDone(void);

		void stop();

		void stop(brakeType mode);

		void arcade(double drivePower, double turnPower, percentUnits units = percentUnits::pct);

		double velocity(velocityUnits units);

		double velocity(percentUnits units) { return velocity(static_cast<velocityUnits>(units)); };

		double current(currentUnits units = currentUnits::amp);

		double current(percentUnits units);

		double power(powerUnits units = powerUnits::watt);

		double torque(torqueUnits units = torqueUnits::Nm);

		double efficiency(percentUnits units = percentUnits::pct);

		double temperature(percentUnits units);

	  protected:
		double distanceToMm(double distance, distanceUnits units);
		double angleToDeg(double angle, rotationUnits units);
		int32_t timeoutGet();

		double _turnvelocity;
		velocityUnits _turnvelocityUnits;
		uint8_t _turnmode;
	};
}; // namespace vex

#endif
