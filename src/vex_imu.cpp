#include "vex_imu.h"

namespace vex {
	class gyro;
}

double
vex::inertial::_scaleRotationValue(double value, rotationUnits units) {
	double dummy;

	return dummy;
}

void vex::inertial::_collisionEventHandler(void* arg) {}

vex::inertial::inertial(int32_t index) {}

vex::inertial::~inertial() {}

bool vex::inertial::installed() {
	bool dummy;

	return dummy;
}

int32_t
vex::inertial::value() {
	int32_t dummy;

	return dummy;
}

vex::inertial::matrix::matrix() {}

vex::inertial::matrix::~matrix() {}

void vex::inertial::matrix::transform(double& x, double& y, double& z) {}

void vex::inertial::matrix::multiply(matrix& m) {}

double
vex::inertial::matrix::inverse() {
	double dummy;

	return dummy;
}

vex::inertial::quaternion::quaternion() {}

vex::inertial::quaternion::quaternion(double a, double b, double c, double d) {}

vex::inertial::quaternion::~quaternion() {}

vex::inertial::quaternion&
vex::inertial::quaternion::operator=(const quaternion other) { return *this; }

vex::inertial::quaternion
vex::inertial::quaternion::conjugate() const {
	quaternion dummy;

	return dummy;
}

vex::inertial::quaternion
vex::inertial::quaternion::normalized() const {
	quaternion dummy;

	return dummy;
}

vex::inertial::quaternion
vex::inertial::quaternion::operator*(const quaternion& rhs) const {
	quaternion dummy;

	return dummy;
}

vex::inertial::quaternion&
vex::inertial::quaternion::operator*=(const quaternion& rhs) {
	auto dummy = new quaternion;
	return *dummy;
}

void vex::inertial::quaternion::transform(double& x, double& y, double& z) {}

vex::inertial::quaternion
vex::inertial::quaternion::fromAngleX(double angle) {
	quaternion dummy;

	return dummy;
}

vex::inertial::quaternion
vex::inertial::quaternion::fromAngleY(double angle) {
	quaternion dummy;

	return dummy;
}

vex::inertial::quaternion
vex::inertial::quaternion::fromAngleZ(double angle) {
	quaternion dummy;

	return dummy;
}

void vex::inertial::quaternion::matrix(inertial::matrix& m) {}

vex::inertial::attitude::attitude() {}

vex::inertial::attitude::attitude(double roll, double pitch, double yaw) {}

vex::inertial::attitude::~attitude() {}

void vex::inertial::attitude::transform(double& x, double& y, double& z) {}

void vex::inertial::startCalibration(int32_t value) {}

bool vex::inertial::isCalibrating(void) {
	bool dummy;

	return dummy;
}

void vex::inertial::resetHeading() {}

void vex::inertial::resetRotation() {}

void vex::inertial::setHeading(double value, rotationUnits units) {}

void vex::inertial::setRotation(double value, rotationUnits units) {}

double
vex::inertial::angle(rotationUnits units) {
	double dummy;

	return dummy;
}

double
vex::inertial::roll(rotationUnits units) {
	double dummy;

	return dummy;
}

double
vex::inertial::pitch(rotationUnits units) {
	double dummy;

	return dummy;
}

double
vex::inertial::yaw(rotationUnits units) {
	double dummy;

	return dummy;
}

double
vex::inertial::orientation(orientationType axis, rotationUnits units) {
	double dummy;

	return dummy;
}

double
vex::inertial::heading(rotationUnits units) {
	double dummy;

	return dummy;
}

double
vex::inertial::rotation(rotationUnits units) {
	double dummy;

	return dummy;
}

void vex::inertial::orientation(quaternion& q) {}

vex::inertial::quaternion
vex::inertial::orientation() {
	quaternion dummy;

	return dummy;
}

void vex::inertial::orientation(attitude& a) {}

double
vex::inertial::gyroRate(axisType axis, velocityUnits units) {
	double dummy;

	return dummy;
}

double
vex::inertial::acceleration(axisType axis) {
	double dummy;

	return dummy;
}

int32_t
vex::inertial::status() {
	int32_t dummy;

	return dummy;
}

double
vex::inertial::temperature() {
	double dummy;

	return dummy;
}

vex::inertial::gyro::gyro() {}

vex::inertial::gyro::~gyro() {}

vex::inertial::gyro& vex::inertial::gyro::
operator=(const gyro other) { return *this; }

vex::inertial::accel::accel() {}

vex::inertial::accel::~accel() {}

vex::inertial::accel&
vex::inertial::accel::operator=(const accel other) { return *this; }

vex::inertial::gyro
vex::inertial::gyroRate() {
	gyro dummy;

	return dummy;
}

vex::inertial::accel
vex::inertial::acceleration() {
	accel dummy;

	return dummy;
}

void vex::inertial::setOrientation(orientationMode orientation) {}

void vex::inertial::setAccelerometerRange(uint8_t value) {}

void vex::inertial::setCollisionThreshold(double value) {}
