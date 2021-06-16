#include "v5_apiuser.h"

void vexDelay(uint32_t timems) {}

void vexLedSet(uint32_t index, V5_DeviceLedColor value) {}

void vexLedRgbSet(uint32_t index, uint32_t color) {}

V5_DeviceLedColor
vexLedGet(uint32_t index) {
	V5_DeviceLedColor dummy;

	return dummy;
}

uint32_t
vexLedRgbGet(uint32_t index) {
	uint32_t dummy;

	return dummy;
}

void vexAdiPortConfigSet(uint32_t index, uint32_t port, V5_AdiPortConfiguration type) {}

V5_AdiPortConfiguration
vexAdiPortConfigGet(uint32_t index, uint32_t port) {
	V5_AdiPortConfiguration dummy;

	return dummy;
}

void vexAdiValueSet(uint32_t index, uint32_t port, int32_t value) {}

int32_t
vexAdiValueGet(uint32_t index, uint32_t port) {
	int32_t dummy;

	return dummy;
}

V5_DeviceBumperState
vexBumperGet(uint32_t index) {
	V5_DeviceBumperState dummy;

	return dummy;
}

void vexGyroReset(uint32_t index) {}

double
vexGyroHeadingGet(uint32_t index) {
	double dummy;

	return dummy;
}

double
vexGyroDegreesGet(uint32_t index) {
	double dummy;

	return dummy;
}

int32_t
vexSonarValueGet(uint32_t index) {
	int32_t dummy;

	return dummy;
}

int32_t
vexGenericValueGet(uint32_t index) {
	int32_t dummy;

	return dummy;
}

void vexMotorVelocitySet(uint32_t index, int32_t velocity) {}

void vexMotorVelocityUpdate(uint32_t index, int32_t velocity) {}

void vexMotorVoltageSet(uint32_t index, int32_t value) {}

int32_t
vexMotorVelocityGet(uint32_t index) {
	int32_t dummy;

	return dummy;
}

int32_t
vexMotorDirectionGet(uint32_t index) {
	int32_t dummy;

	return dummy;
}

double
vexMotorActualVelocityGet(uint32_t index) {
	double dummy;

	return dummy;
}

void vexMotorModeSet(uint32_t index, V5MotorControlMode mode) {}

V5MotorControlMode
vexMotorModeGet(uint32_t index) {
	V5MotorControlMode dummy;

	return dummy;
}

void vexMotorPwmSet(uint32_t index, int32_t value) {}

int32_t
vexMotorPwmGet(uint32_t index) {
	int32_t dummy;

	return dummy;
}

void vexMotorCurrentLimitSet(uint32_t index, int32_t value) {}

int32_t
vexMotorCurrentLimitGet(uint32_t index) {
	int32_t dummy;

	return dummy;
}

void vexMotorVoltageLimitSet(uint32_t index, int32_t value) {}

int32_t
vexMotorVoltageLimitGet(uint32_t index) {
	int32_t dummy;

	return dummy;
}

void vexMotorPositionPidSet(uint32_t index, V5_DeviceMotorPid* pid) {}

void vexMotorVelocityPidSet(uint32_t index, V5_DeviceMotorPid* pid) {}

int32_t
vexMotorCurrentGet(uint32_t index) {
	int32_t dummy;

	return dummy;
}

int32_t
vexMotorVoltageGet(uint32_t index) {
	int32_t dummy;

	return dummy;
}

double
vexMotorPowerGet(uint32_t index) {
	double dummy;

	return dummy;
}

double
vexMotorTorqueGet(uint32_t index) {
	double dummy;

	return dummy;
}

double
vexMotorEfficiencyGet(uint32_t index) {
	double dummy;

	return dummy;
}

double
vexMotorTemperatureGet(uint32_t index) {
	double dummy;

	return dummy;
}

bool vexMotorOverTempFlagGet(uint32_t index) {
	bool dummy;

	return dummy;
}

bool vexMotorCurrentLimitFlagGet(uint32_t index) {
	bool dummy;

	return dummy;
}

uint32_t
vexMotorFaultsGet(uint32_t index) {
	uint32_t dummy;

	return dummy;
}

bool vexMotorZeroVelocityFlagGet(uint32_t index) {
	bool dummy;

	return dummy;
}

bool vexMotorZeroPositionFlagGet(uint32_t index) {
	bool dummy;

	return dummy;
}

uint32_t
vexMotorFlagsGet(uint32_t index) {
	uint32_t dummy;

	return dummy;
}

void vexMotorReverseFlagSet(uint32_t index, bool value) {}

bool vexMotorReverseFlagGet(uint32_t index) {
	bool dummy;

	return dummy;
}

void vexMotorEncoderUnitsSet(uint32_t index, V5MotorEncoderUnits units) {}

V5MotorEncoderUnits
vexMotorEncoderUnitsGet(uint32_t index) {
	V5MotorEncoderUnits dummy;

	return dummy;
}

void vexMotorBrakeModeSet(uint32_t index, V5MotorBrakeMode mode) {}

V5MotorBrakeMode
vexMotorBrakeModeGet(uint32_t index) {
	V5MotorBrakeMode dummy;

	return dummy;
}

void vexMotorPositionSet(uint32_t index, double position) {}

double
vexMotorPositionGet(uint32_t index) {
	double dummy;

	return dummy;
}

int32_t
vexMotorPositionRawGet(uint32_t index, uint32_t* timestamp) {
	int32_t dummy;

	return dummy;
}

void vexMotorPositionReset(uint32_t index) {}

double
vexMotorTargetGet(uint32_t index) {
	double dummy;

	return dummy;
}

void vexMotorServoTargetSet(uint32_t index, double position) {}

void vexMotorAbsoluteTargetSet(uint32_t index, double position, int32_t velocity) {}

void vexMotorRelativeTargetSet(uint32_t index, double position, int32_t velocity) {}

void vexMotorGearingSet(uint32_t index, V5MotorGearset value) {}

V5MotorGearset
vexMotorGearingGet(uint32_t index) {
	V5MotorGearset dummy;

	return dummy;
}

void vexVisionModeSet(uint32_t index, V5VisionMode mode) {}

V5VisionMode
vexVisionModeGet(uint32_t index) {
	V5VisionMode dummy;

	return dummy;
}

int32_t
vexVisionObjectCountGet(uint32_t index) {
	int32_t dummy;

	return dummy;
}

int32_t
vexVisionObjectGet(uint32_t index, uint32_t indexObj, V5_DeviceVisionObject* pObject) {
	int32_t dummy;

	return dummy;
}

void vexVisionSignatureSet(uint32_t index, V5_DeviceVisionSignature* pSignature) {}

bool vexVisionSignatureGet(uint32_t index, uint32_t id, V5_DeviceVisionSignature* pSignature) {
	bool dummy;

	return dummy;
}

void vexVisionBrightnessSet(uint32_t index, uint8_t percent) {}

uint8_t
vexVisionBrightnessGet(uint32_t index) {
	uint8_t dummy;

	return dummy;
}

void vexVisionWhiteBalanceModeSet(uint32_t index, V5VisionWBMode mode) {}

V5VisionWBMode
vexVisionWhiteBalanceModeGet(uint32_t index) {
	V5VisionWBMode dummy;

	return dummy;
}

void vexVisionWhiteBalanceSet(uint32_t index, V5_DeviceVisionRgb color) {}

V5_DeviceVisionRgb
vexVisionWhiteBalanceGet(uint32_t index) {
	V5_DeviceVisionRgb dummy;

	return dummy;
}

void vexVisionLedModeSet(uint32_t index, V5VisionLedMode mode) {}

V5VisionLedMode
vexVisionLedModeGet(uint32_t index) {
	V5VisionLedMode dummy;

	return dummy;
}

void vexVisionLedBrigntnessSet(uint32_t index, uint8_t percent) {}

uint8_t
vexVisionLedBrigntnessGet(uint32_t index) {
	uint8_t dummy;

	return dummy;
}

void vexVisionLedColorSet(uint32_t index, V5_DeviceVisionRgb color) {}

V5_DeviceVisionRgb
vexVisionLedColorGet(uint32_t index) {
	V5_DeviceVisionRgb dummy;

	return dummy;
}

void vexVisionWifiModeSet(uint32_t index, V5VisionWifiMode mode) {}

V5VisionWifiMode
vexVisionWifiModeGet(uint32_t index) {
	V5VisionWifiMode dummy;

	return dummy;
}

void vexImuReset(uint32_t index) {}

double
vexImuHeadingGet(uint32_t index) {
	double dummy;

	return dummy;
}

double
vexImuDegreesGet(uint32_t index) {
	double dummy;

	return dummy;
}

void vexImuQuaternionGet(uint32_t index, V5_DeviceImuQuaternion* data) {}

void vexImuAttitudeGet(uint32_t index, V5_DeviceImuAttitude* data) {}

void vexImuRawGyroGet(uint32_t index, V5_DeviceImuRaw* data) {}

void vexImuRawAccelGet(uint32_t index, V5_DeviceImuRaw* data) {}

uint32_t
vexImuStatusGet(uint32_t index) {
	uint32_t dummy;

	return dummy;
}

void vexImuModeSet(uint32_t index, uint32_t mode) {}

uint32_t
vexImuModeGet(uint32_t index) {
	uint32_t dummy;

	return dummy;
}

int32_t
vexRangeValueGet(uint32_t index) {
	int32_t dummy;

	return dummy;
}

void vexAbsEncReset(uint32_t index) {}

void vexAbsEncPositionSet(uint32_t index, int32_t position) {}

int32_t
vexAbsEncPositionGet(uint32_t index) {
	int32_t dummy;

	return dummy;
}

int32_t
vexAbsEncVelocityGet(uint32_t index) {
	int32_t dummy;

	return dummy;
}

int32_t
vexAbsEncAngleGet(uint32_t index) {
	int32_t dummy;

	return dummy;
}

void vexAbsEncReverseFlagSet(uint32_t index, bool value) {}

bool vexAbsEncReverseFlagGet(uint32_t index) {
	bool dummy;

	return dummy;
}

uint32_t
vexAbsEncStatusGet(uint32_t index) {
	uint32_t dummy;

	return dummy;
}

void vexGenericSerialEnable(uint32_t index, int32_t options) {}

void vexGenericSerialBaudrate(uint32_t index, int32_t baudrate) {}

int32_t
vexGenericSerialWriteChar(uint32_t index, uint8_t c) {
	int32_t dummy;

	return dummy;
}

int32_t
vexGenericSerialWriteFree(uint32_t index) {
	int32_t dummy;

	return dummy;
}

int32_t
vexGenericSerialTransmit(uint32_t index, uint8_t* buffer, int32_t length) {
	int32_t dummy;

	return dummy;
}

int32_t
vexGenericSerialReadChar(uint32_t index) {
	int32_t dummy;

	return dummy;
}

int32_t
vexGenericSerialPeekChar(uint32_t index) {
	int32_t dummy;

	return dummy;
}

int32_t
vexGenericSerialReceiveAvail(uint32_t index) {
	int32_t dummy;

	return dummy;
}

int32_t
vexGenericSerialReceive(uint32_t index, uint8_t* buffer, int32_t length) {
	int32_t dummy;

	return dummy;
}

void vexGenericSerialFlush(uint32_t index) {}
