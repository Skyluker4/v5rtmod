#include "vex_controller.h"

int32_t
vex::controller::value(V5_ControllerIndex channel) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::controller::_getIndex() {
	int32_t dummy;

	return dummy;
}

vex::controller::controller() {}

vex::controller::controller(controllerType id) {}

vex::controller::~controller() {}

bool vex::controller::installed() {
	bool dummy;

	return dummy;
}

void vex::controller::rumble(const char* str) {}

vex::controller::tEventType vex::controller::button::_buttonToPressedEvent() {
	tEventType dummy;

	return dummy;
}

vex::controller::tEventType vex::controller::button::_buttonToReleasedEvent() {
	tEventType dummy;

	return dummy;
}

bool vex::controller::button::pressing(void) {
	bool dummy;

	return dummy;
}

vex::controller::tEventType vex::controller::axis::_joystickToChangedEvent() {
	tEventType dummy;

	return dummy;
}

int32_t
vex::controller::axis::value(void) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::controller::axis::position(percentUnits units) {
	int32_t dummy;

	return dummy;
}

vex::controllerType
vex::controller::lcd::getControllerId() {
	controllerType dummy;

	return dummy;
}

vex::controller::lcd::lcd() {}

vex::controller::lcd::lcd(controller* parent) {}

void vex::controller::lcd::setCursor(int32_t row, int32_t col) {}

int32_t
vex::controller::lcd::column() {
	int32_t dummy;

	return dummy;
}

int32_t
vex::controller::lcd::row() {
	int32_t dummy;

	return dummy;
}

void vex::controller::lcd::print(const char* format, ...) {}

void vex::controller::lcd::print(char* format, ...) {}

void vex::controller::lcd::clearScreen(void) {}

void vex::controller::lcd::clearLine(int number) {}

void vex::controller::lcd::clearLine(void) {}

void vex::controller::lcd::newLine(void) {}
