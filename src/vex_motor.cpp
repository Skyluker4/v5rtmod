#include "vex_motor.h"

vex::motor::motor(int32_t index) {}

vex::motor::~motor() {}

bool vex::motor::installed() {
	bool dummy;

	return dummy;
}

int32_t
vex::motor::value() {
	int32_t dummy;

	return dummy;
}

vex::motor::motor(int32_t index, bool reverse) {}

vex::motor::motor(int32_t index, gearSetting gears) {}

vex::motor::motor(int32_t index, gearSetting gears, bool reverse) {}

void vex::motor::setReversed(bool value) {}

void vex::motor::setVelocity(double velocity, velocityUnits units) {}

void vex::motor::setBrake(brakeType mode) {}

void vex::motor::setStopping(brakeType mode) {}

void vex::motor::resetRotation(void) {}

void vex::motor::resetPosition(void) {}

void vex::motor::setRotation(double value, rotationUnits units) {}

void vex::motor::setPosition(double value, rotationUnits units) {}

void vex::motor::setTimeout(int32_t time, timeUnits units) {}

void vex::motor::spin(directionType dir) {}

void vex::motor::spin(directionType dir, double velocity, velocityUnits units) {}

void vex::motor::spin(directionType dir, double voltage, voltageUnits units) {}

bool vex::motor::rotateTo(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor::spinTo(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor::spinToPosition(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor::rotateTo(double rotation, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor::spinTo(double rotation, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor::spinToPosition(double rotation, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor::rotateFor(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor::spinFor(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor::rotateFor(directionType dir, double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor::spinFor(directionType dir, double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor::rotateFor(double rotation, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor::spinFor(double rotation, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor::rotateFor(directionType dir, double rotation, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor::spinFor(directionType dir, double rotation, rotationUnits units, bool waitForCompletion) {
	bool dummy;

	return dummy;
}

bool vex::motor::rotateFor(double time, timeUnits units, double velocity, velocityUnits units_v) {
	bool dummy;

	return dummy;
}

bool vex::motor::spinFor(double time, timeUnits units, double velocity, velocityUnits units_v) {
	bool dummy;

	return dummy;
}

bool vex::motor::rotateFor(directionType dir, double time, timeUnits units, double velocity, velocityUnits units_v) {
	bool dummy;

	return dummy;
}

bool vex::motor::spinFor(directionType dir, double time, timeUnits units, double velocity, velocityUnits units_v) {
	bool dummy;

	return dummy;
}

bool vex::motor::rotateFor(double time, timeUnits units) {
	bool dummy;

	return dummy;
}

bool vex::motor::spinFor(double time, timeUnits units) {
	bool dummy;

	return dummy;
}

bool vex::motor::rotateFor(directionType dir, double time, timeUnits units) {
	bool dummy;

	return dummy;
}

bool vex::motor::spinFor(directionType dir, double time, timeUnits units) {
	bool dummy;

	return dummy;
}

void vex::motor::startRotateTo(double rotation, rotationUnits units, double velocity, velocityUnits units_v) {}

void vex::motor::startSpinTo(double rotation, rotationUnits units, double velocity, velocityUnits units_v) {}

void vex::motor::startRotateTo(double rotation, rotationUnits units) {}

void vex::motor::startSpinTo(double rotation, rotationUnits units) {}

void vex::motor::startRotateFor(double rotation, rotationUnits units, double velocity, velocityUnits units_v) {}

void vex::motor::startSpinFor(double rotation, rotationUnits units, double velocity, velocityUnits units_v) {}

void vex::motor::startRotateFor(directionType dir, double rotation, rotationUnits units, double velocity, velocityUnits units_v) {}

void vex::motor::startSpinFor(directionType dir, double rotation, rotationUnits units, double velocity, velocityUnits units_v) {}

void vex::motor::startRotateFor(double rotation, rotationUnits units) {}

void vex::motor::startSpinFor(double rotation, rotationUnits units) {}

void vex::motor::startRotateFor(directionType dir, double rotation, rotationUnits units) {}

void vex::motor::startSpinFor(directionType dir, double rotation, rotationUnits units) {}

bool vex::motor::isSpinning(void) {
	bool dummy;

	return dummy;
}

bool vex::motor::isDone(void) {
	bool dummy;

	return dummy;
}

void vex::motor::stop(void) {}

void vex::motor::stop(brakeType mode) {}

void vex::motor::setMaxTorque(double value, percentUnits units) {}

void vex::motor::setMaxTorque(double value, torqueUnits units) {}

void vex::motor::setMaxTorque(double value, currentUnits units) {}

vex::directionType
vex::motor::direction(void) {
	directionType dummy;

	return dummy;
}

double
vex::motor::rotation(rotationUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor::position(rotationUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor::velocity(velocityUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor::current(currentUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor::current(percentUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor::power(powerUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor::torque(torqueUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor::efficiency(percentUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor::temperature(percentUnits units) {
	double dummy;

	return dummy;
}

double
vex::motor::temperature(temperatureUnits units) {
	double dummy;

	return dummy;
}

int32_t
vex::motor::getTimeout() {
	int32_t dummy;

	return dummy;
}

void vex::motor::defaultStopping(brakeType mode) {}

void vex::motor::setRotationUnits(rotationUnits units) {}

double
vex::motor::velocityToScaled(double velocity, velocityUnits units) {
	double dummy;

	return dummy;
}

int32_t
vex::motor::scaledToVelocity(double value, velocityUnits units) {
	int32_t dummy;

	return dummy;
}

double
vex::motor::torqueToCurrent(double torque) {
	double dummy;

	return dummy;
}
