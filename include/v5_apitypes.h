#ifndef V5_APITYPES_H_
#define V5_APITYPES_H_

#include "stdbool.h"
#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

using vcodesig = struct
#ifndef _MSVC
	__attribute__((__packed__))
#endif
	_vcodesig {
	uint32_t magic;
	uint32_t type;
	uint32_t owner;
	uint32_t options;
};

#define V5_SIG_MAGIC 0x35585658
#define V5_SIG_TYPE_USER 0
#define V5_SIG_OWNER_SYS 0
#define V5_SIG_OWNER_VEX 1
#define V5_SIG_OWNER_PARTNER 2
#define V5_SIG_OPTIONS_NONE 0
#define V5_SIG_OPTIONS_INDG (1 << 0)
#define V5_SIG_OPTIONS_EXIT (1 << 1)
#define V5_SIG_OPTIONS_THDG (1 << 2)

#define V5_CODE_SIG(type, owner, options)                        \
	vcodesig vexCodeSig __attribute__((section(".boot_data"))) = \
		{V5_SIG_MAGIC, type, owner, options};

struct time {
	uint8_t ti_hour;
	uint8_t ti_min;
	uint8_t ti_sec;
	uint8_t ti_hund;
};

struct date {
	uint16_t da_year;
	uint8_t da_day;
	uint8_t da_mon;
};

using V5_DeviceType = enum {
	kDeviceTypeNoSensor = 0,
	kDeviceTypeMotorSensor = 2,
	kDeviceTypeLedSensor = 3,
	kDeviceTypeAbsEncSensor = 4,
	kDeviceTypeCrMotorSensor = 5,
	kDeviceTypeImuSensor = 6,
	kDeviceTypeRangeSensor = 7,
	kDeviceTypeRadioSensor = 8,
	kDeviceTypeTetherSensor = 9,
	kDeviceTypeBrainSensor = 10,
	kDeviceTypeVisionSensor = 11,
	kDeviceTypeAdiSensor = 12,
	kDeviceTypeBumperSensor = 0x40,
	kDeviceTypeGyroSensor = 0x46,
	kDeviceTypeSonarSensor = 0x47,
	kDeviceTypeGenericSensor = 128,
	kDeviceTypeGenericSerial = 129,
	kDeviceTypeUndefinedSensor = 255
};

using V5_DeviceT = struct _V5_Device*;

#define V5_MAX_DEVICE_PORTS 32
using V5_DeviceTypeBuffer = V5_DeviceType[V5_MAX_DEVICE_PORTS];

using V5_ControllerIndex = enum _V5_ControllerIndex {
	AnaLeftX = 0,
	AnaLeftY,
	AnaRightX,
	AnaRightY,
	AnaSpare1,
	AnaSpare2,

	Button5U,
	Button5D,
	Button6U,
	Button6D,
	Button7U,
	Button7D,
	Button7L,
	Button7R,
	Button8U,
	Button8D,
	Button8L,
	Button8R,

	ButtonSEL,

	BatteryLevel,

	ButtonAll,
	Flags,
	BatteryCapacity,

	Axis1 = AnaRightX,
	Axis2 = AnaRightY,
	Axis3 = AnaLeftY,
	Axis4 = AnaLeftX,

	ButtonL1 = Button5U,
	ButtonL2 = Button5D,
	ButtonR1 = Button6U,
	ButtonR2 = Button6D,

	ButtonUp = Button7U,
	ButtonDown = Button7D,
	ButtonLeft = Button7L,
	ButtonRight = Button7R,

	ButtonX = Button8U,
	ButtonB = Button8D,
	ButtonY = Button8L,
	ButtonA = Button8R
};

using V5_ControllerStatus = enum _V5_ControllerStatus {
	kV5ControllerOffline = 0,
	kV5ControllerTethered,
	kV5ControllerVexnet
};

using V5_ControllerId = enum _V5_ControllerId {
	kControllerMaster = 0,
	kControllerPartner
};

using V5_DeviceLedColor = enum _V5_DeviceLedColor {
	kLedColorBlack = 0,
	kLedColorRed = 0xFF0000,
	kLedColorGreen = 0x00FF00,
	kLedColorBlue = 0x0000FF,
	kLedColorYellow = 0xFFFF00,
	kLedColorCyan = 0x00FFFF,
	kLedColorMagenta = 0xFF00FF,
	kLedColorWhite = 0xFFFFFF
};

using V5_AdiPortConfiguration = enum _V5_AdiPortConfiguration {
	kAdiPortTypeAnalogIn = 0,
	kAdiPortTypeAnalogOut,
	kAdiPortTypeDigitalIn,
	kAdiPortTypeDigitalOut,

	kAdiPortTypeSmartButton,
	kAdiPortTypeSmartPot,

	kAdiPortTypeLegacyButton,
	kAdiPortTypeLegacyPotentiometer,
	kAdiPortTypeLegacyLineSensor,
	kAdiPortTypeLegacyLightSensor,
	kAdiPortTypeLegacyGyro,
	kAdiPortTypeLegacyAccelerometer,

	kAdiPortTypeLegacyServo,
	kAdiPortTypeLegacyPwm,

	kAdiPortTypeQuadEncoder,
	kAdiPortTypeSonar,

	kAdiPortTypeLegacyPwmSlew,

	kAdiPortTypeUndefined = 255
};

#define V5_ADI_PORT_NUM 8

using V5_DeviceBumperState = enum _V5_DeviceBumperState {
	kBumperReleased = 0,
	kBumperPressed = 1
};

using V5MotorControlMode = enum {
	kMotorControlModeOFF = 0,
	kMotorControlModeBRAKE = 1,
	kMotorControlModeHOLD = 2,
	kMotorControlModeSERVO = 3,
	kMotorControlModePROFILE = 4,
	kMotorControlModeVELOCITY = 5,
	kMotorControlModeUNDEFINED = 6
};

using V5MotorBrakeMode = enum _V5_MotorBrakeMode {
	kV5MotorBrakeModeCoast = 0,
	kV5MotorBrakeModeBrake = 1,
	kV5MotorBrakeModeHold = 2
};

using V5MotorEncoderUnits = enum {
	kMotorEncoderDegrees = 0,
	kMotorEncoderRotations = 1,
	kMotorEncoderCounts = 2
};

using V5MotorGearset = enum _V5MotorGearset {
	kMotorGearSet_36 = 0,
	kMotorGearSet_18 = 1,
	kMotorGearSet_06 = 2
};

#define V5_MOTOR_COUNTS_PER_ROT 1800.0

using V5_DeviceMotorPid = struct
#ifndef _MSVC
	__attribute__((__packed__))
#endif
	_V5_DeviceMotorPid {
	uint8_t kf;
	uint8_t kp;
	uint8_t ki;
	uint8_t kd;
	uint8_t filter;
	uint8_t pad1;
	uint16_t limit;
	uint8_t threshold;
	uint8_t loopspeed;
	uint8_t pad2[2];
};

using V5VisionMode = enum {
	kVisionModeNormal = 0,
	kVisionModeMixed = 1,
	kVisionModeLineDetect = 2,
	kVisionTypeTest = 3
};

using V5VisionBlockType = enum {
	kVisionTypeNormal = 0,
	kVisionTypeColorCode = 1,
	kVisionTypeLineDetect = 2
};

using V5VisionWBMode = enum {
	kVisionWBNormal = 0,
	kVisionWBStart = 1,
	kVisionWBManual = 2
};

using V5VisionLedMode = enum {
	kVisionLedModeAuto = 0,
	kVisionLedModeManual = 1
};

using V5VisionWifiMode = enum {
	kVisionWifiModeOff = 0,
	kVisionWifiModeOn = 1
};

#define VISION_SIG_FLAG_STATUS (1 << 0)

using V5_DeviceVisionSignature = struct
#ifndef _MSVC
	__attribute__((__packed__))
#endif
	_V5_DeviceVisionSignature {
	uint8_t id;
	uint8_t flags;
	uint8_t pad[2];
	float range;
	int32_t uMin;
	int32_t uMax;
	int32_t uMean;
	int32_t vMin;
	int32_t vMax;
	int32_t vMean;
	uint32_t mRgb;
	uint32_t mType;
};

using V5_DeviceVisionObject = struct
#ifndef _MSVC
	__attribute__((__packed__))
#endif
	_V5_DeviceVisionObject {
	uint16_t signature;
	V5VisionBlockType type;
	uint16_t xoffset;
	uint16_t yoffset;
	uint16_t width;
	uint16_t height;
	uint16_t angle;
};

using V5_DeviceVisionRgb = struct
#ifndef _MSVC
	__attribute__((__packed__))
#endif
	_V5_DeviceVisionRgb {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t brightness;
};

using V5_DeviceImuQuaternion = struct
#ifndef _MSVC
	__attribute__((__packed__))
#endif
	_V5_DeviceImuQuaternion {
	double a;
	double b;
	double c;
	double d;
};

using V5_DeviceImuAttitude = struct
#ifndef _MSVC
	__attribute__((__packed__))
#endif
	_V5_DeviceImuAttitude {
	double pitch;
	double roll;
	double yaw;
};

using V5_DeviceImuRaw = struct
#ifndef _MSVC
	__attribute__((__packed__))
#endif
	_V5_DeviceImuRaw {
	double x;
	double y;
	double z;
	double w;
};

using _V5ImuHeadingnMode = enum _V5ImuHeadingnMode {
	kImuHeadingNative = 0x00,
	kImuHeadingIQ = 0x01
};

using V5ImuOrientationMode = enum _V5ImuOrientationMode {
	kImuOrientationZUp = 0x00,
	kImuOrientationZDown = 0x10,
	kImuOrientationXUp = 0x20,
	kImuOrientationXDown = 0x30,
	kImuOrientationYUp = 0x40,
	kImuOrientationYDown = 0x50,
	kImuOrientationAuto = 0x80
};

using V5ImuQuaternionMode = enum _V5ImuQuaternionMode {
	kImuQuaternionProcessed = 0x000,
	kImuQuaternionRaw = 0x100
};

using FIL = void;

#define FS_SEEK_SET 0
#define FS_SEEK_CUR 1
#define FS_SEEK_END 2

using FRESULT = enum {
	FR_OK = 0U,
	FR_DISK_ERR,
	FR_INT_ERR,
	FR_NOT_READY,
	FR_NO_FILE,
	FR_NO_PATH,
	FR_INVALID_NAME,
	FR_DENIED,
	FR_EXIST,
	FR_INVALID_OBJECT,
	FR_WRITE_PROTECTED,
	FR_INVALID_DRIVE,
	FR_NOT_ENABLED,
	FR_NO_FILESYSTEM,
	FR_MKFS_ABORTED,
	FR_TIMEOUT,
	FR_LOCKED,
	FR_NOT_ENOUGH_CORE,
	FR_TOO_MANY_OPEN_FILES,
	FR_INVALID_PARAMETER
};

using V5_TouchEvent = enum _touchEvent {
	kTouchEventRelease,
	kTouchEventPress,
	kTouchEventPressAuto
};

using V5_TouchStatus = struct _V5_TouchStatus {
	V5_TouchEvent lastEvent;
	int16_t lastXpos;
	int16_t lastYpos;
	int32_t pressCount;
	int32_t releaseCount;
};

#define V5_COMP_BIT_EBL 1
#define V5_COMP_BIT_MODE 2
#define V5_COMP_BIT_COMP 4
#define V5_COMP_BIT_GAME 8

using v5_image = struct
#ifndef _MSVC
	__attribute__((__packed__))
#endif
	_v5_image {
	uint16_t width;
	uint16_t height;
	uint32_t* data;
	uint32_t* p;
};

#define SYSTEM_DISPLAY_WIDTH 480
#define SYSTEM_DISPLAY_HEIGHT 272

#ifdef __cplusplus
}
#endif
#endif
