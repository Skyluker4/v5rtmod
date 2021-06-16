#include "vex_brain.h"

int32_t
vex::brain::_getIndex() {
	int32_t dummy;

	return dummy;
}

vex::brain::brain() {}

vex::brain::~brain() {}

int32_t
vex::brain::lcd::rowToPixel(int32_t row) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::brain::lcd::colToPixel(int32_t col) {
	int32_t dummy;

	return dummy;
}

vex::brain::lcd::lcd() {}

void vex::brain::lcd::setCursor(int32_t row, int32_t col) {}

void vex::brain::lcd::setFont(fontType font) {}

void vex::brain::lcd::setPenWidth(uint32_t width) {}

void vex::brain::lcd::setOrigin(int32_t x, int32_t y) {}

int32_t
vex::brain::lcd::column() {
	int32_t dummy;

	return dummy;
}

int32_t
vex::brain::lcd::row() {
	int32_t dummy;

	return dummy;
}

void vex::brain::lcd::setPenColor(const color& color) {}

void vex::brain::lcd::setPenColor(const char* color) {}

void vex::brain::lcd::setPenColor(int hue) {}

void vex::brain::lcd::setFillColor(const color& color) {}

void vex::brain::lcd::setFillColor(const char* color) {}

void vex::brain::lcd::setFillColor(int hue) {}

int32_t
vex::brain::lcd::getStringWidth(const char* cstr) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::brain::lcd::getStringHeight(const char* cstr) {
	int32_t dummy;

	return dummy;
}

void vex::brain::lcd::print(const char* format, ...) {}

void vex::brain::lcd::print(char* format, ...) {}

void vex::brain::lcd::printAt(int32_t x, int32_t y, const char* format, ...) {}

void vex::brain::lcd::printAt(int32_t x, int32_t y, bool bOpaque, const char* format, ...) {}

void vex::brain::lcd::clearScreen(void) {}

void vex::brain::lcd::clearScreen(const color& color) {}

void vex::brain::lcd::clearScreen(const char* color) {}

void vex::brain::lcd::clearScreen(int hue) {}

void vex::brain::lcd::clearLine(int number, const color& color) {}

void vex::brain::lcd::clearLine(int number, const char* color) {}

void vex::brain::lcd::clearLine(int number, int hue) {}

void vex::brain::lcd::clearLine(int number) {}

void vex::brain::lcd::clearLine(void) {}

void vex::brain::lcd::newLine(void) {}

void vex::brain::lcd::drawPixel(int x, int y) {}

void vex::brain::lcd::drawLine(int x1, int y1, int x2, int y2) {}

void vex::brain::lcd::drawRectangle(int x, int y, int width, int height) {}

void vex::brain::lcd::drawRectangle(int x, int y, int width, int height, const color& color) {}

void vex::brain::lcd::drawRectangle(int x, int y, int width, int height, const char* color) {}

void vex::brain::lcd::drawRectangle(int x, int y, int width, int height, int hue) {}

void vex::brain::lcd::drawCircle(int x, int y, int radius) {}

void vex::brain::lcd::drawCircle(int x, int y, int radius, const color& color) {}

void vex::brain::lcd::drawCircle(int x, int y, int radius, const char* color) {}

void vex::brain::lcd::drawCircle(int x, int y, int radius, int hue) {}

int32_t
vex::brain::lcd::xPosition() {
	int32_t dummy;

	return dummy;
}

int32_t
vex::brain::lcd::yPosition() {
	int32_t dummy;

	return dummy;
}

bool vex::brain::lcd::pressing() {
	bool dummy;

	return dummy;
}

bool vex::brain::lcd::render() {
	bool dummy;

	return dummy;
}

bool vex::brain::lcd::render(bool bVsyncWait, bool bRunScheduler) {
	bool dummy;

	return dummy;
}

void vex::brain::lcd::setClipRegion(int x, int y, int width, int height) {}

bool vex::brain::lcd::drawImageFromBuffer(uint8_t* buffer, int x, int y, int bufferLen) {
	bool dummy;

	return dummy;
}

bool vex::brain::lcd::drawImageFromBuffer(uint32_t* buffer, int x, int y, int width, int height) {
	bool dummy;

	return dummy;
}

bool vex::brain::lcd::drawImageFromFile(const char* name, int x, int y) {
	bool dummy;

	return dummy;
}

void vex::brain::lcd::waitForRefresh() {}

void vex::brain::lcd::renderDisable() {}

void vex::brain::lcd::_setPenColor(uint32_t rgb) {}

void vex::brain::lcd::_setFillColor(uint32_t rgb) {}

void vex::brain::lcd::_clearScreen(uint32_t rgb) {}

void vex::brain::lcd::_clearLine(int number, uint32_t rgb) {}

void vex::brain::lcd::_drawRectangle(int x, int y, int width, int height, uint32_t rgb) {}

void vex::brain::lcd::_drawCircle(int x, int y, int radius, uint32_t rgb) {}

vex::brain::lcd::tImageBufferType
vex::brain::lcd::_validateImageBuffer(uint8_t* buffer) {
	tImageBufferType dummy;

	return dummy;
}

uint32_t
vex::brain::lcd::webColorToRgb(const char* color) {
	uint32_t dummy;

	return dummy;
}

uint32_t
vex::brain::lcd::hueToRgb(uint32_t color) {
	uint32_t dummy;

	return dummy;
}

double
vex::brain::timer(timeUnits units) {
	double dummy;

	return dummy;
}

void vex::brain::resetTimer() {}

void vex::brain::setTimer(double value, timeUnits units) {}

uint32_t
vex::brain::battery::capacity(percentUnits units) {
	uint32_t dummy;

	return dummy;
}

double
vex::brain::battery::temperature(percentUnits units) {
	double dummy;

	return dummy;
}

double
vex::brain::battery::temperature(temperatureUnits units) {
	double dummy;

	return dummy;
}

double
vex::brain::battery::voltage(voltageUnits units) {
	double dummy;

	return dummy;
}

double
vex::brain::battery::current(currentUnits units) {
	double dummy;

	return dummy;
}

vex::brain::sdcard::sdcard() {}

vex::brain::sdcard::~sdcard() {}

bool vex::brain::sdcard::isInserted() {
	bool dummy;

	return dummy;
}

int32_t
vex::brain::sdcard::loadfile(const char* name, uint8_t* buffer, int32_t len) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::brain::sdcard::savefile(const char* name, uint8_t* buffer, int32_t len) {
	int32_t dummy;

	return dummy;
}

int32_t
vex::brain::sdcard::appendfile(const char* name, uint8_t* buffer, int32_t len) {
	int32_t dummy;

	return dummy;
}
