#ifndef VEX_DRIVETRAIN_EXT_CLASS_H
#define VEX_DRIVETRAIN_EXT_CLASS_H

#include "vex_drivetrain.h"
#include "vex_imu.h"
#include "vex_triport.h"

namespace vex {

	class smartdrive : public drivetrain {
	  public:
		smartdrive(motor_group& l, motor_group& r, gyro& g, double wheelTravel = 320, double trackWidth = 320, double wheelBase = 130, distanceUnits unit = distanceUnits::mm, double externalGearRatio = 1.0);
		smartdrive(motor& l, motor& r, gyro& g, double wheelTravel = 320, double trackWidth = 320, double wheelBase = 130, distanceUnits unit = distanceUnits::mm, double externalGearRatio = 1.0);
		smartdrive(motor_group& l, motor_group& r, inertial& g, double wheelTravel = 320, double trackWidth = 320, double wheelBase = 130, distanceUnits unit = distanceUnits::mm, double externalGearRatio = 1.0);
		smartdrive(motor& l, motor& r, inertial& g, double wheelTravel = 320, double trackWidth = 320, double wheelBase = 130, distanceUnits unit = distanceUnits::mm, double externalGearRatio = 1.0);

		~smartdrive() override;

		void setTurnThreshold(double t);
		bool turnToHeading(double angle, rotationUnits units, bool waitForCompletion = true);
		bool turnToHeading(double angle, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);
		bool turnToRotation(double angle, rotationUnits units, bool waitForCompletion = true);
		bool turnToRotation(double angle, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);
		bool turnFor(turnType dir, double angle, rotationUnits units, bool waitForCompletion = true) override;

		bool turnFor(double angle, rotationUnits units, bool waitForCompletion = true) override;
		bool turnFor(turnType dir, double angle, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true) override;

		bool turnFor(double angle, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true) override;

		void setHeading(double value, rotationUnits units);

		double heading(rotationUnits units = rotationUnits::deg);

		double rotation(rotationUnits units = rotationUnits::deg);

		void setRotation(double value, rotationUnits units);

		bool isTurning();

		bool isMoving() override;

	  private:
		guido* g;
		double _targetAngle;
		turnType _targetDir;
		int32_t _timeout;
		bool _turning;
		bool _blocked;
		bool _slow;
		int32_t _gyroTaskId;
		double _turnThreshold;

		static int _gyrotask(void* arg);
		void _initevents();
		bool _testForCompletionGyro();
		bool _waitForCompletionGyro();

		enum class tEventType {
			EVENT_GYRO_POLL = 4
		};
	};
} // namespace vex

#endif
