#include "vex_smartdrive.h"

vex::smartdrive::smartdrive(motor_group& l, motor_group& r, gyro& g, double wheelTravel, double trackWidth, double wheelBase, distanceUnits unit, double externalGearRatio)
	: drivetrain{
		  l, r, wheelTravel, trackWidth, wheelBase, unit, externalGearRatio} {}

vex::smartdrive::smartdrive(motor& l, motor& r, gyro& g, double wheelTravel, double trackWidth, double wheelBase, distanceUnits unit, double externalGearRatio)
	: drivetrain{
		  l, r, wheelTravel, trackWidth, wheelBase, unit, externalGearRatio} {}

vex::smartdrive::smartdrive(motor_group& l, motor_group& r, inertial& g, double wheelTravel, double trackWidth, double wheelBase, distanceUnits unit, double externalGearRatio)
	: drivetrain{
		  l, r, wheelTravel, trackWidth, wheelBase, unit, externalGearRatio} {}

vex::smartdrive::smartdrive(motor& l, motor& r, inertial& g, double wheelTravel, double trackWidth, double wheelBase, distanceUnits unit, double externalGearRatio)
	: drivetrain{
		  l, r, wheelTravel, trackWidth, wheelBase, unit, externalGearRatio} {}

vex::smartdrive::~smartdrive() {}

void vex::smartdrive::setTurnThreshold(double t) {}

bool vex::smartdrive::turnToHeading(double angle, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::smartdrive::turnToHeading(double angle, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::smartdrive::turnToRotation(double angle, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::smartdrive::turnToRotation(double angle, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::smartdrive::turnFor(turnType dir, double angle, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::smartdrive::turnFor(double angle, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::smartdrive::turnFor(turnType dir, double angle, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::smartdrive::turnFor(double angle, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

void vex::smartdrive::setHeading(double value, rotationUnits units) {}

double
vex::smartdrive::heading(rotationUnits units) {
	double dummy;

	return dummy;
}

double
vex::smartdrive::rotation(rotationUnits units) {
	double dummy;

	return dummy;
}

void vex::smartdrive::setRotation(double value, rotationUnits units) {}

bool vex::smartdrive::isTurning() {
	bool dummy;

	return dummy;
}

bool vex::smartdrive::isMoving() {
	bool dummy;

	return dummy;
}

int vex::smartdrive::_gyrotask(void* arg) {
	int dummy;

	return dummy;
}

void vex::smartdrive::_initevents() {}

bool vex::smartdrive::_testForCompletionGyro() {
	bool dummy;

	return dummy;
}

bool vex::smartdrive::_waitForCompletionGyro() {
	bool dummy;

	return dummy;
}
