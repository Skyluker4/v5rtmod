#include "vex_triport.h"

void vex::triport::_configPort(uint32_t id, triportType type) {}

int32_t
vex::triport::_getIndex() {
	int32_t dummy;

	return dummy;
}

V5_AdiPortConfiguration
vex::triport::_internalType(triportType type) {
	V5_AdiPortConfiguration dummy;

	return dummy;
}

vex::triportType
vex::triport::_externalType(V5_AdiPortConfiguration type) {
	triportType dummy;

	return dummy;
}

vex::triport::triport(int32_t index) {}

vex::triport::~triport() {}

bool vex::triport::installed() {
	bool dummy;

	return dummy;
}

int32_t
vex::triport::port::_convertAnalog(analogUnits units) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::triport::port::_virtual_value(int32_t virtual_port) {
	int32_t dummy;

	return dummy;
}

vex::triport::port::port(const int32_t id, triport* parent) {}

vex::triport::port::port(const int32_t id, const triportType type, triport* parent) {}

void vex::triport::port::type(const triportType type) {}

vex::triportType
vex::triport::port::type() {
	triportType dummy;

	return dummy;
}

void vex::triport::port::value(int32_t value) {}

int32_t
vex::triport::port::value() {
	int32_t dummy;

	return dummy;
}

void vex::triport::port::set(bool value) {}

void vex::triport::port::resetRotation(void) {}

void vex::triport::port::setRotation(double val, rotationUnits units) {}

double
vex::triport::port::rotation(rotationUnits units) {
	double dummy;

	return dummy;
}

double
vex::triport::port::velocity(velocityUnits units) {
	double dummy;

	return dummy;
}

double
vex::triport::port::distance(distanceUnits units) {
	double dummy;

	return dummy;
}

int32_t
vex::__tridevice::_convertAnalog(analogUnits units) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::__tridevice::_virtual_value(int32_t virtual_port) {
	int32_t dummy;

	return dummy;
}

vex::__tridevice::__tridevice(triport::port& port, triportType type)
	: _port(port) {}

vex::__tridevice::~__tridevice() {}

vex::limit::limit(triport::port& port)
	: __tridevice{port, triportType::button} {}

vex::limit::~limit() {}

int32_t
vex::limit::value() {
	int32_t dummy;

	return dummy;
}

vex::limit::operator int() { return _PRESSED; }

vex::limit::operator bool() { return _PRESSED; }

vex::bumper::bumper(triport::port& port)
	: __tridevice{port, triportType::button} {}

vex::bumper::~bumper() {}

int32_t
vex::bumper::value() {
	int32_t dummy;

	return dummy;
}

vex::bumper::operator int() { return value(); }

vex::bumper::operator bool() { return value(); }

vex::digital_in::digital_in(triport::port& port)
	: __tridevice{port, triportType::digitalInput} {}

vex::digital_in::~digital_in() {}

int32_t
vex::digital_in::value() {
	int32_t dummy;

	return dummy;
}

vex::digital_in::operator int() { return value(); }

vex::digital_in::operator bool() { return value(); }

vex::digital_out::digital_out(triport::port& port)
	: __tridevice{port, triportType::digitalOutput} {}

vex::digital_out::~digital_out() {}

int32_t
vex::digital_out::value() {
	int32_t dummy;

	return dummy;
}

void vex::digital_out::set(bool value) {}

vex::digital_out::operator int() { return value(); }

vex::digital_out::operator bool() { return value(); }

void vex::digital_out::operator=(const int32_t value) {}

vex::led::led(triport::port& port)
	: digital_out{port} {}

vex::led::~led() {}

void vex::led::on() {}

void vex::led::off() {}

vex::pneumatics::pneumatics(triport::port& port)
	: digital_out{port} {}

vex::pneumatics::~pneumatics() {}

void vex::pneumatics::open() {}

void vex::pneumatics::close() {}

vex::pot::pot(triport::port& port)
	: __tridevice{port, triportType::potentiometer} {}

vex::pot::~pot() {}

int32_t
vex::pot::value(analogUnits units) {
	int32_t dummy;

	return dummy;
}

double
vex::pot::value(rotationUnits units) {
	double dummy;

	return dummy;
}

vex::line::line(triport::port& port)
	: __tridevice{port, triportType::lineSensor} {}

vex::line::~line() {}

int32_t
vex::line::value(analogUnits units) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::line::reflectivity(percentUnits units) {
	int32_t dummy;

	return dummy;
}

vex::light::light(triport::port& port)
	: __tridevice{port, triportType::lightSensor} {}

vex::light::~light() {}

int32_t
vex::light::value(analogUnits units) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::light::brightness(percentUnits units) {
	int32_t dummy;

	return dummy;
}

vex::gyro::gyro(triport::port& port)
	: __tridevice{port, triportType::gyro} {}

vex::gyro::~gyro() {}

int32_t
vex::gyro::value(analogUnits units) {
	int32_t dummy;

	return dummy;
}

double
vex::gyro::value(rotationUnits units) {
	double dummy;

	return dummy;
}

void vex::gyro::startCalibration(int32_t value) {}

bool vex::gyro::isCalibrating() {
	bool dummy;

	return dummy;
}

void vex::gyro::resetAngle() {}

void vex::gyro::resetHeading() {}

void vex::gyro::resetRotation() {}

void vex::gyro::resetAngle(double value, rotationUnits units) {}

void vex::gyro::setHeading(double value, rotationUnits units) {}

double
vex::gyro::angle(rotationUnits units) {
	double dummy;

	return dummy;
}

double
vex::gyro::heading(rotationUnits units) {
	double dummy;

	return dummy;
}

double
vex::gyro::rotation(rotationUnits units) {
	double dummy;

	return dummy;
}

void vex::gyro::setRotation(double value, rotationUnits units) {}

vex::accelerometer::accelerometer(triport::port& port, bool bHighSensitivity)
	: __tridevice{
		  port, triportType::accelerometer} {}

vex::accelerometer::~accelerometer() {}

int32_t
vex::accelerometer::value(analogUnits units) {
	int32_t dummy;

	return dummy;
}

double
vex::accelerometer::acceleration() {
	double dummy;

	return dummy;
}

vex::analog_in::analog_in(triport::port& port)
	: __tridevice{port, triportType::analogInput} {}

vex::analog_in::~analog_in() {}

int32_t
vex::analog_in::value(analogUnits units) {
	int32_t dummy;

	return dummy;
}

vex::encoder::encoder(triport::port& port)
	: __tridevice{port, triportType::analogOutput} {}

vex::encoder::~encoder() {}

int32_t
vex::encoder::value() {
	int32_t dummy;

	return dummy;
}

vex::encoder::operator int() { return value(); }

void vex::encoder::resetRotation(void) {}

void vex::encoder::setRotation(double val, rotationUnits units) {}

void vex::encoder::setPosition(double val, rotationUnits units) {}

double
vex::encoder::rotation(rotationUnits units) {
	double dummy;

	return dummy;
}

double
vex::encoder::position(rotationUnits units) {
	double dummy;

	return dummy;
}

double
vex::encoder::velocity(velocityUnits units) {
	double dummy;

	return dummy;
}

vex::sonar::sonar(triport::port& port)
	: __tridevice{port, triportType::sonar} {}

vex::sonar::~sonar() {}

int32_t
vex::sonar::value() {
	int32_t dummy;

	return dummy;
}

vex::sonar::operator int() { return value(); }

double
vex::sonar::distance(distanceUnits units) {
	double dummy;

	return dummy;
}

void vex::sonar::setMaximum(double distance, distanceUnits units) {}

bool vex::sonar::foundObject() {
	bool dummy;

	return dummy;
}

void vex::sonar::setMinimum(double distance, distanceUnits units) {}

vex::pwm_out::pwm_out(triport::port& port)
	: __tridevice{port, triportType::digitalOutput} {}

vex::pwm_out::~pwm_out() {}

void vex::pwm_out::state(int32_t value, percentUnits units) {}

vex::servo::servo(triport::port& port)
	: __tridevice{port, triportType::motorS} {}

vex::servo::~servo() {}

void vex::servo::setPosition(int32_t value, percentUnits units) {}

void vex::servo::setPosition(double value, rotationUnits units) {}

vex::motor29::motor29(triport::port& port)
	: __tridevice{port, triportType::motor} {}

vex::motor29::motor29(triport::port& port, bool reverse)
	: __tridevice{port, triportType::motor} {}

vex::motor29::~motor29() {}

void vex::motor29::setVelocity(double velocity, percentUnits units) {}

void vex::motor29::setReversed(bool value) {}

void vex::motor29::spin(directionType dir) {}

void vex::motor29::spin(directionType dir, double velocity, velocityUnits units) {}

void vex::motor29::stop(void) {}

vex::motor_victor::motor_victor(triport::port& port)
	: __tridevice{port, triportType::motor} {}

vex::motor_victor::motor_victor(triport::port& port, bool reverse)
	: __tridevice{port, triportType::motor} {}

vex::motor_victor::~motor_victor() {}

void vex::motor_victor::setVelocity(double velocity, percentUnits units) {}

void vex::motor_victor::setReversed(bool value) {}

void vex::motor_victor::spin(directionType dir) {}

void vex::motor_victor::spin(directionType dir, double velocity, velocityUnits units) {}

void vex::motor_victor::stop(void) {}
