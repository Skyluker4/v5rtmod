#include "vex_motorgroup.h"

void vex::motor_group::_addMotor() {}

void vex::motor_group::_addMotor(motor& m) {}

bool vex::motor_group::waitForCompletionAll() {
	bool dummy;

	return dummy;
}

vex::motor_group::motor_group() {}

vex::motor_group::~motor_group() {}

int32_t
vex::motor_group::count(void) {
	int32_t dummy;

	return dummy;
}

void vex::motor_group::setVelocity(double velocity, velocityUnits units) {}

void vex::motor_group::setStopping(brakeType mode) {}

void vex::motor_group::resetRotation(void) {}

void vex::motor_group::resetPosition(void) {}

void vex::motor_group::setRotation(double value, rotationUnits units) {}

void vex::motor_group::setPosition(double value, rotationUnits units) {}

void vex::motor_group::setTimeout(int32_t time, timeUnits units) {}

void vex::motor_group::spin(directionType dir) {}

void vex::motor_group::spin(directionType dir, double velocity, velocityUnits units) {}

void vex::motor_group::spin(directionType dir, double voltage, voltageUnits units) {}

bool vex::motor_group::rotateTo(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor_group::spinTo(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor_group::spinToPosition(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor_group::rotateTo(double rotation, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor_group::spinTo(double rotation, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor_group::spinToPosition(double rotation, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor_group::rotateFor(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor_group::spinFor(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor_group::rotateFor(directionType dir, double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor_group::spinFor(directionType dir, double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor_group::rotateFor(double rotation, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor_group::spinFor(double rotation, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor_group::rotateFor(directionType dir, double rotation, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor_group::spinFor(directionType dir, double rotation, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

void vex::motor_group::rotateFor(double time, timeUnits units, double velocity, velocityUnits units_v) {}

void vex::motor_group::spinFor(double time, timeUnits units, double velocity, velocityUnits units_v) {}

void vex::motor_group::rotateFor(directionType dir, double time, timeUnits units, double velocity, velocityUnits units_v) {}

void vex::motor_group::spinFor(directionType dir, double time, timeUnits units, double velocity, velocityUnits units_v) {}

void vex::motor_group::rotateFor(double time, timeUnits units) {}

void vex::motor_group::spinFor(double time, timeUnits units) {}

void vex::motor_group::rotateFor(directionType dir, double time, timeUnits units) {}

void vex::motor_group::spinFor(directionType dir, double time, timeUnits units) {}

bool vex::motor_group::isSpinning(void) {
	bool dummy;

	return dummy;
}

bool vex::motor_group::isDone(void) {
	bool dummy;

	return dummy;
}

void vex::motor_group::stop(void) {}

void vex::motor_group::stop(brakeType mode) {}

void vex::motor_group::setMaxTorque(double value, percentUnits units) {}

void vex::motor_group::setMaxTorque(double value, torqueUnits units) {}

void vex::motor_group::setMaxTorque(double value, currentUnits units) {}

vex::directionType
vex::motor_group::direction(void) {
	directionType dummy;

	return dummy;
}

double
vex::motor_group::rotation(rotationUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor_group::position(rotationUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor_group::velocity(velocityUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor_group::current(currentUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor_group::current(percentUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor_group::power(powerUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor_group::torque(torqueUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor_group::efficiency(percentUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor_group::temperature(percentUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor_group::temperature(temperatureUnits units) {
	double dummy;

	return dummy;
}
