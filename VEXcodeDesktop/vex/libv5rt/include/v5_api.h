#ifndef V5_API_H_
#define V5_API_H_

#include "stdarg.h"
#include "stdbool.h"
#include "stdint.h"
#include <cstdio>
#include <cstdlib>

#include "v5_apitypes.h"
#include "v5_apiuser.h"
#include "v5_color.h"

#ifdef __cplusplus
extern "C" {
#endif
void vexBackgroundProcessing(void);

int32_t vexDebug(const char* fmt, ...);
int32_t vex_printf(const char* fmt, ...);
int32_t vex_sprintf(char* out, const char* format, ...);
int32_t vex_snprintf(char* out, uint32_t max_len, const char* format, ...);
int32_t vex_vsprintf(char* out, const char* format, va_list args);
int32_t vex_vsnprintf(char* out, uint32_t max_len, const char* format, va_list args);

uint32_t vexSystemTimeGet(void);
void vexGettime(struct time* pTime);
void vexGetdate(struct date* pDate);
void vexSystemMemoryDump(void);
void vexSystemDigitalIO(uint32_t pin, uint32_t value);
uint32_t vexSystemStartupOptions(void);
void vexSystemExitRequest(void);
uint64_t vexSystemHighResTimeGet(void);
uint64_t vexSystemPowerupTimeGet(void);
uint32_t vexSystemLinkAddrGet(void);
uint32_t vexSystemUsbStatus(void);

uint32_t vexDevicesGetNumber(void);
uint32_t vexDevicesGetNumberByType(V5_DeviceType type);
V5_DeviceT vexDevicesGet(void);
V5_DeviceT vexDeviceGetByIndex(uint32_t index);
int32_t vexDeviceGetStatus(V5_DeviceType* buffer);

#define VEX_DEVICE_GET(device, index) V5_DeviceT device = vexDeviceGetByIndex(index)

int32_t vexControllerGet(V5_ControllerId id, V5_ControllerIndex index);
V5_ControllerStatus vexControllerConnectionStatusGet(V5_ControllerId id);
bool vexControllerTextSet(V5_ControllerId id, uint32_t line, uint32_t col, const char* str);

void vexDeviceLedSet(V5_DeviceT device, V5_DeviceLedColor value);
void vexDeviceLedRgbSet(V5_DeviceT device, uint32_t color);
V5_DeviceLedColor vexDeviceLedGet(V5_DeviceT device);
uint32_t vexDeviceLedRgbGet(V5_DeviceT device);

void vexDeviceAdiPortConfigSet(V5_DeviceT device, uint32_t port, V5_AdiPortConfiguration type);
V5_AdiPortConfiguration vexDeviceAdiPortConfigGet(V5_DeviceT device, uint32_t port);
void vexDeviceAdiValueSet(V5_DeviceT device, uint32_t port, int32_t value);
int32_t vexDeviceAdiValueGet(V5_DeviceT device, uint32_t port);

V5_DeviceBumperState vexDeviceBumperGet(V5_DeviceT device);

void vexDeviceGyroReset(V5_DeviceT device);
double vexDeviceGyroHeadingGet(V5_DeviceT device);
double vexDeviceGyroDegreesGet(V5_DeviceT device);

int32_t vexDeviceSonarValueGet(V5_DeviceT device);

int32_t vexDeviceGenericValueGet(V5_DeviceT device);

void vexDeviceMotorVelocitySet(V5_DeviceT device, int32_t velocity);
void vexDeviceMotorVelocityUpdate(V5_DeviceT device, int32_t velocity);
void vexDeviceMotorVoltageSet(V5_DeviceT device, int32_t value);
int32_t vexDeviceMotorVelocityGet(V5_DeviceT device);
double vexDeviceMotorActualVelocityGet(V5_DeviceT device);
int32_t vexDeviceMotorDirectionGet(V5_DeviceT device);
void vexDeviceMotorModeSet(V5_DeviceT device, V5MotorControlMode mode);
V5MotorControlMode vexDeviceMotorModeGet(V5_DeviceT device);
void vexDeviceMotorPwmSet(V5_DeviceT device, int32_t value);
int32_t vexDeviceMotorPwmGet(V5_DeviceT device);
void vexDeviceMotorCurrentLimitSet(V5_DeviceT device, int32_t value);
int32_t vexDeviceMotorCurrentLimitGet(V5_DeviceT device);
void vexDeviceMotorVoltageLimitSet(V5_DeviceT device, int32_t value);
int32_t vexDeviceMotorVoltageLimitGet(V5_DeviceT device);
void vexDeviceMotorPositionPidSet(V5_DeviceT device, V5_DeviceMotorPid* pid);
void vexDeviceMotorVelocityPidSet(V5_DeviceT device, V5_DeviceMotorPid* pid);
int32_t vexDeviceMotorCurrentGet(V5_DeviceT device);
int32_t vexDeviceMotorVoltageGet(V5_DeviceT device);
double vexDeviceMotorPowerGet(V5_DeviceT device);
double vexDeviceMotorTorqueGet(V5_DeviceT device);
double vexDeviceMotorEfficiencyGet(V5_DeviceT device);
double vexDeviceMotorTemperatureGet(V5_DeviceT device);
bool vexDeviceMotorOverTempFlagGet(V5_DeviceT device);
bool vexDeviceMotorCurrentLimitFlagGet(V5_DeviceT device);
uint32_t vexDeviceMotorFaultsGet(V5_DeviceT device);
bool vexDeviceMotorZeroVelocityFlagGet(V5_DeviceT device);
bool vexDeviceMotorZeroPositionFlagGet(V5_DeviceT device);
uint32_t vexDeviceMotorFlagsGet(V5_DeviceT device);
void vexDeviceMotorReverseFlagSet(V5_DeviceT device, bool value);
bool vexDeviceMotorReverseFlagGet(V5_DeviceT device);
void vexDeviceMotorEncoderUnitsSet(V5_DeviceT device, V5MotorEncoderUnits units);
V5MotorEncoderUnits vexDeviceMotorEncoderUnitsGet(V5_DeviceT device);
void vexDeviceMotorBrakeModeSet(V5_DeviceT device, V5MotorBrakeMode mode);
V5MotorBrakeMode vexDeviceMotorBrakeModeGet(V5_DeviceT device);
void vexDeviceMotorPositionSet(V5_DeviceT device, double position);
double vexDeviceMotorPositionGet(V5_DeviceT device);
int32_t vexDeviceMotorPositionRawGet(V5_DeviceT device, uint32_t* timestamp);
void vexDeviceMotorPositionReset(V5_DeviceT device);
double vexDeviceMotorTargetGet(V5_DeviceT device);
void vexDeviceMotorServoTargetSet(V5_DeviceT device, double position);
void vexDeviceMotorAbsoluteTargetSet(V5_DeviceT device, double position, int32_t velocity);
void vexDeviceMotorRelativeTargetSet(V5_DeviceT device, double position, int32_t velocity);
void vexDeviceMotorGearingSet(V5_DeviceT device, V5MotorGearset value);
V5MotorGearset vexDeviceMotorGearingGet(V5_DeviceT device);

void vexDeviceVisionModeSet(V5_DeviceT device, V5VisionMode mode);
V5VisionMode vexDeviceVisionModeGet(V5_DeviceT device);
int32_t vexDeviceVisionObjectCountGet(V5_DeviceT device);
int32_t vexDeviceVisionObjectGet(V5_DeviceT device, uint32_t indexObj, V5_DeviceVisionObject* pObject);
void vexDeviceVisionSignatureSet(V5_DeviceT device, V5_DeviceVisionSignature* pSignature);
bool vexDeviceVisionSignatureGet(V5_DeviceT device, uint32_t id, V5_DeviceVisionSignature* pSignature);
void vexDeviceVisionBrightnessSet(V5_DeviceT device, uint8_t percent);
uint8_t vexDeviceVisionBrightnessGet(V5_DeviceT device);
void vexDeviceVisionWhiteBalanceModeSet(V5_DeviceT device, V5VisionWBMode mode);
V5VisionWBMode vexDeviceVisionWhiteBalanceModeGet(V5_DeviceT device);
void vexDeviceVisionWhiteBalanceSet(V5_DeviceT device, V5_DeviceVisionRgb color);
V5_DeviceVisionRgb vexDeviceVisionWhiteBalanceGet(V5_DeviceT device);
void vexDeviceVisionLedModeSet(V5_DeviceT device, V5VisionLedMode mode);
V5VisionLedMode vexDeviceVisionLedModeGet(V5_DeviceT device);
void vexDeviceVisionLedBrigntnessSet(V5_DeviceT device, uint8_t percent);
uint8_t vexDeviceVisionLedBrigntnessGet(V5_DeviceT device);
void vexDeviceVisionLedColorSet(V5_DeviceT device, V5_DeviceVisionRgb color);
V5_DeviceVisionRgb vexDeviceVisionLedColorGet(V5_DeviceT device);
void vexDeviceVisionWifiModeSet(V5_DeviceT device, V5VisionWifiMode mode);
V5VisionWifiMode vexDeviceVisionWifiModeGet(V5_DeviceT device);

void vexDeviceImuReset(V5_DeviceT device);
double vexDeviceImuHeadingGet(V5_DeviceT device);
double vexDeviceImuDegreesGet(V5_DeviceT device);
void vexDeviceImuQuaternionGet(V5_DeviceT device, V5_DeviceImuQuaternion* data);
void vexDeviceImuAttitudeGet(V5_DeviceT device, V5_DeviceImuAttitude* data);
void vexDeviceImuRawGyroGet(V5_DeviceT device, V5_DeviceImuRaw* data);
void vexDeviceImuRawAccelGet(V5_DeviceT device, V5_DeviceImuRaw* data);
uint32_t vexDeviceImuStatusGet(V5_DeviceT device);
void vexDeviceImuModeSet(V5_DeviceT device, uint32_t mode);
uint32_t vexDeviceImuModeGet(V5_DeviceT device);

int32_t vexDeviceRangeValueGet(V5_DeviceT device);

void vexDeviceAbsEncReset(V5_DeviceT device);
void vexDeviceAbsEncPositionSet(V5_DeviceT device, int32_t position);
int32_t vexDeviceAbsEncPositionGet(V5_DeviceT device);
int32_t vexDeviceAbsEncVelocityGet(V5_DeviceT device);
int32_t vexDeviceAbsEncAngleGet(V5_DeviceT device);
void vexDeviceAbsEncReverseFlagSet(V5_DeviceT device, bool value);
bool vexDeviceAbsEncReverseFlagGet(V5_DeviceT device);
uint32_t vexDeviceAbsEncStatusGet(V5_DeviceT device);

void vexDeviceGenericSerialEnable(V5_DeviceT device, int32_t options);
void vexDeviceGenericSerialBaudrate(V5_DeviceT device, int32_t baudrate);
int32_t vexDeviceGenericSerialWriteChar(V5_DeviceT device, uint8_t c);
int32_t vexDeviceGenericSerialWriteFree(V5_DeviceT device);
int32_t vexDeviceGenericSerialTransmit(V5_DeviceT device, uint8_t* buffer, int32_t length);
int32_t vexDeviceGenericSerialReadChar(V5_DeviceT device);
int32_t vexDeviceGenericSerialPeekChar(V5_DeviceT device);
int32_t vexDeviceGenericSerialReceiveAvail(V5_DeviceT device);
int32_t vexDeviceGenericSerialReceive(V5_DeviceT device, uint8_t* buffer, int32_t length);
void vexDeviceGenericSerialFlush(V5_DeviceT device);

void vexDisplayForegroundColor(uint32_t col);
void vexDisplayBackgroundColor(uint32_t col);
uint32_t vexDisplayForegroundColorGet(void);
uint32_t vexDisplayBackgroundColorGet(void);
void vexDisplayErase(void);
void vexDisplayScroll(int32_t nStartLine, int32_t nLines);
void vexDisplayScrollRect(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t nLines);
void vexDisplayCopyRect(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t* pSrc, int32_t srcStride);
void vexDisplayPixelSet(uint32_t x, uint32_t y);
void vexDisplayPixelClear(uint32_t x, uint32_t y);
void vexDisplayLineDraw(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
void vexDisplayLineClear(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
void vexDisplayRectDraw(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
void vexDisplayRectClear(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
void vexDisplayRectFill(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
void vexDisplayCircleDraw(int32_t xc, int32_t yc, int32_t radius);
void vexDisplayCircleClear(int32_t xc, int32_t yc, int32_t radius);
void vexDisplayCircleFill(int32_t xc, int32_t yc, int32_t radius);

void vexDisplayPrintf(int32_t xpos, int32_t ypos, uint32_t bOpaque, const char* format, ...);
void vexDisplayString(int32_t nLineNumber, const char* format, ...);
void vexDisplayStringAt(int32_t xpos, int32_t ypos, const char* format, ...);
void vexDisplayBigString(int32_t nLineNumber, const char* format, ...);
void vexDisplayBigStringAt(int32_t xpos, int32_t ypos, const char* format, ...);
void vexDisplaySmallStringAt(int32_t xpos, int32_t ypos, const char* format, ...);
void vexDisplayCenteredString(int32_t nLineNumber, const char* format, ...);
void vexDisplayBigCenteredString(int32_t nLineNumber, const char* format, ...);

void vexDisplayVPrintf(int32_t xpos, int32_t ypos, uint32_t bOpaque, const char* format, va_list args);
void vexDisplayVString(int32_t nLineNumber, const char* format, va_list args);
void vexDisplayVStringAt(int32_t xpos, int32_t ypos, const char* format, va_list args);
void vexDisplayVBigString(int32_t nLineNumber, const char* format, va_list args);
void vexDisplayVBigStringAt(int32_t xpos, int32_t ypos, const char* format, va_list args);
void vexDisplayVSmallStringAt(int32_t xpos, int32_t ypos, const char* format, va_list args);
void vexDisplayVCenteredString(int32_t nLineNumber, const char* format, va_list args);
void vexDisplayVBigCenteredString(int32_t nLineNumber, const char* format, va_list args);

void vexDisplayTextSize(uint32_t n, uint32_t d);
void vexDisplayFontNamedSet(const char* pFontName);
int32_t vexDisplayStringWidthGet(const char* pString);
int32_t vexDisplayStringHeightGet(const char* pString);

bool vexDisplayRender(bool bVsyncWait, bool bRunScheduler);
void vexDisplayDoubleBufferDisable(void);

void vexDisplayClipRegionSet(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
void vexDisplayClipRegionClear();

uint32_t vexImageBmpRead(const uint8_t* ibuf, v5_image* oBuf, uint32_t maxw, uint32_t maxh);
uint32_t vexImagePngRead(const uint8_t* ibuf, v5_image* oBuf, uint32_t maxw, uint32_t maxh, uint32_t ibuflen);

int32_t vexScratchMemoryPtr(void** ptr);

FRESULT vexFileMountSD(void);
FRESULT vexFileDirectoryGet(const char* path, char* buffer, uint32_t len);
FIL* vexFileOpen(const char* filename, const char* mode);
FIL* vexFileOpenWrite(const char* filename);
FIL* vexFileOpenCreate(const char* filename);
void vexFileClose(FIL* fdp);
int32_t vexFileRead(char* buf, uint32_t size, uint32_t nItems, FIL* fdp);
int32_t vexFileWrite(char* buf, uint32_t size, uint32_t nItems, FIL* fdp);
int32_t vexFileSize(FIL* fdp);
FRESULT vexFileSeek(FIL* fdp, uint32_t offset, int32_t whence);
bool vexFileDriveStatus(uint32_t drive);
int32_t vexFileTell(FIL* fdp);

int32_t vexSerialWriteChar(uint32_t channel, uint8_t c);
int32_t vexSerialWriteBuffer(uint32_t channel, uint8_t* data, uint32_t data_len);
int32_t vexSerialReadChar(uint32_t channel);
int32_t vexSerialPeekChar(uint32_t channel);
int32_t vexSerialWriteFree(uint32_t channel);

void vexSystemTimerStop();
void vexSystemTimerClearInterrupt();
int32_t vexSystemTimerReinitForRtos(uint32_t priority, void (*handler)(void* data));
void vexSystemApplicationIRQHandler(uint32_t ulICCIAR);
int32_t vexSystemWatchdogReinitRtos(void);
uint32_t vexSystemWatchdogGet(void);

void vexSystemBoot(void);
void vexSystemUndefinedException(void);
void vexSystemFIQInterrupt(void);
void vexSystemIQRQnterrupt(void);
void vexSystemSWInterrupt(void);
void vexSystemDataAbortInterrupt(void);
void vexSystemPrefetchAbortInterrupt(void);

void vexTouchUserCallbackSet(void (*callback)(V5_TouchEvent, int32_t, int32_t));
bool vexTouchDataGet(V5_TouchStatus* status);

uint32_t vexSystemVersion(void);
uint32_t vexStdlibVersion(void);

uint32_t vexSdkVersion(void);

uint32_t vexStdlibVersionLinked(void);
bool vexStdlibVersionVerify(void);

uint32_t vexCompetitionStatus(void);
void vexCompetitionControl(uint32_t data);

int32_t vexBatteryVoltageGet(void);
int32_t vexBatteryCurrentGet(void);
double vexBatteryTemperatureGet(void);
double vexBatteryCapacityGet(void);

#ifdef __cplusplus
}
#endif
#endif
