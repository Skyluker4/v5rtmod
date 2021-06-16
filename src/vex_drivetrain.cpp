#include "vex_drivetrain.h"

bool vex::drivetrain::_waitForCompletionAll() {
	bool dummy;

	return dummy;
}

double
vex::drivetrain::_distanceToRevs(double distance, distanceUnits units) {
	double dummy;

	return dummy;
}

double
vex::drivetrain::_angleToRevs(double angle, rotationUnits units) {
	double dummy;

	return dummy;
}

vex::drivetrain::drivetrain(motor_group& l, motor_group& r, double wheelTravel, double trackWidth, double wheelBase, distanceUnits unit, double externalGearRatio) {}

vex::drivetrain::drivetrain(motor& l, motor& r, double wheelTravel, double trackWidth, double wheelBase, distanceUnits unit, double externalGearRatio) {}

vex::drivetrain::~drivetrain() {}

void vex::drivetrain::setGearRatio(double ratio) {}

void vex::drivetrain::setDriveVelocity(double velocity, velocityUnits units) {}

void vex::drivetrain::setDriveVelocity(double velocity, percentUnits units) {}

void vex::drivetrain::setTurnVelocity(double velocity, velocityUnits units) {}

void vex::drivetrain::setTurnVelocity(double velocity, percentUnits units) {}

void vex::drivetrain::setTimeout(int32_t time, timeUnits units) {}

void vex::drivetrain::setStopping(brakeType mode) {}

void vex::drivetrain::drive(directionType dir) {}

void vex::drivetrain::drive(directionType dir, double velocity, velocityUnits units) {}

bool vex::drivetrain::driveFor(double distance, distanceUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::drivetrain::driveFor(directionType dir, double distance, distanceUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::drivetrain::driveFor(double distance, distanceUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::drivetrain::driveFor(directionType dir, double distance, distanceUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

void vex::drivetrain::turn(turnType dir) {}

void vex::drivetrain::turn(turnType dir, double velocity, velocityUnits units) {}

bool vex::drivetrain::turnFor(double angle, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::drivetrain::turnFor(turnType dir, double angle, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::drivetrain::turnFor(double angle, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::drivetrain::turnFor(turnType dir, double angle, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::drivetrain::isMoving(void) {
	bool dummy;

	return dummy;
}

bool vex::drivetrain::isDone(void) {
	bool dummy;

	return dummy;
}

void vex::drivetrain::stop() {}

void vex::drivetrain::stop(brakeType mode) {}

void vex::drivetrain::arcade(double drivePower, double turnPower, percentUnits units) {}

double
vex::drivetrain::velocity(velocityUnits units) {
	double dummy;

	return dummy;
}

double
vex::drivetrain::current(currentUnits units) {
	double dummy;

	return dummy;
}

double
vex::drivetrain::current(percentUnits units) {
	double dummy;

	return dummy;
}

double
vex::drivetrain::power(powerUnits units) {
	double dummy;

	return dummy;
}

double
vex::drivetrain::torque(torqueUnits units) {
	double dummy;

	return dummy;
}

double
vex::drivetrain::efficiency(percentUnits units) {
	double dummy;

	return dummy;
}

double
vex::drivetrain::temperature(percentUnits units) {
	double dummy;

	return dummy;
}

double
vex::drivetrain::distanceToMm(double distance, distanceUnits units) {
	double dummy;

	return dummy;
}

double
vex::drivetrain::angleToDeg(double angle, rotationUnits units) {
	double dummy;

	return dummy;
}

int32_t
vex::drivetrain::timeoutGet() {
	int32_t dummy;

	return dummy;
}
