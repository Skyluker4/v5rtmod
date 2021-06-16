#ifndef VEX_VISION_CLASS_H
#define VEX_VISION_CLASS_H

#include "vex_device.h"

namespace vex {

	class vision : public device {
	  private:
#define VISION_MAX_OBJECTS 16
#define VISION_DEFAULT_SNAPSHOT_OBJECTS 8

		void _setsig(){};

		template <typename signature, typename... Args>
		void _setsig(signature& sig, Args&... args) {
			setSignature(sig);
			_setsig(args...);
		}

	  public:
		vision(int32_t index);
		~vision() override;

		template <typename... Args>
		vision(int32_t index, uint8_t bright, Args&... sigs)
			: vision(index) {
			setBrightness(bright);
			_setsig(sigs...);
		}

		bool installed() override;
		int32_t value() override;

		enum class detectionMode {
			objectDetect = kVisionModeNormal,
			mixedDetect = kVisionModeMixed,
			lineDetect = kVisionModeLineDetect,
			test = kVisionTypeTest
		};

		enum class whiteBalanceMode {
			automatic = kVisionWBNormal,
			start = kVisionWBStart,
			manual = kVisionWBManual
		};

		enum class ledMode {
			automatic = kVisionLedModeAuto,
			manual = kVisionLedModeManual
		};

		enum class wifiMode {
			off = kVisionWifiModeOff,
			on = kVisionWifiModeOn
		};

		class object {
			int _id;
			int _originX;
			int _originY;
			int _centerX;
			int _centerY;
			int _width;
			int _height;
			double _angle;
			bool _exists;

		  public:
			object();
			~object();

			void set(V5_DeviceVisionObject obj);

			void flipAngle();

			void clear();

			object& operator=(const object& obj);
			object& operator=(int32_t signatureId);

			const int& id;

			const int& originX;

			const int& originY;

			const int& centerX;

			const int& centerY;

			const int& width;

			const int& height;

			const double& angle;

			const bool& exists;
		};

		class signature {
			friend class vision;

		  private:
#define MAX_MAME 32

			int32_t _id;
			int32_t _uMin;
			int32_t _uMax;
			int32_t _uMean;
			int32_t _vMin;
			int32_t _vMax;
			int32_t _vMean;
			float _range;
			uint32_t _rgb;
			uint32_t _type;

			void clear();

			static void setTypeColorCode(){};

			template <typename signature, typename... Args>
			static void setTypeColorCode(signature& sig, Args&... args) {
				sig._type = 1;
				setTypeColorCode(args...);
			}

		  public:
			signature();
			~signature();
			signature(int32_t id, int32_t uMin, int32_t uMax, int32_t uMean, int32_t vMin, int32_t vMax, int32_t vMean, float range, int32_t type);

			const int32_t& id;
			const int32_t& uMin;
			const int32_t& uMax;
			const int32_t& uMean;
			const int32_t& vMin;
			const int32_t& vMax;
			const int32_t& vMean;
			const float& range;
			const uint32_t& rgb;
			const uint32_t& type;
		};

		class code {
		  private:
			uint32_t _code;
			bool _flipped = false;

		  public:
			code(int32_t sig1, int32_t sig2);
			code(int32_t sig1, int32_t sig2, int32_t sig3);
			code(int32_t sig1, int32_t sig2, int32_t sig3, int32_t sig4);
			code(int32_t sig1, int32_t sig2, int32_t sig3, int32_t sig4, int32_t sig5);
			code(signature& s1, signature& s2);
			code(signature& s1, signature& s2, signature& s3);
			code(signature& s1, signature& s2, signature& s3, signature& s4);
			code(signature& s1, signature& s2, signature& s3, signature& s4, signature& s5);

			uint32_t getCode() { return _code; }
			bool isFlipped() { return _flipped; }
		};

		int32_t takeSnapshot(uint32_t id);
		int32_t takeSnapshot(code& cc);
		int32_t takeSnapshot(signature& sig);
		int32_t takeSnapshot(uint32_t id, uint32_t count);
		int32_t takeSnapshot(code& cc, uint32_t count);
		int32_t takeSnapshot(signature& sig, uint32_t count);

		int32_t objectCount;

		object largestObject;
		safearray<object, VISION_MAX_OBJECTS> objects;

		bool setSignature(V5_DeviceVisionSignature* pSignature);
		bool getSignature(uint32_t id, V5_DeviceVisionSignature* pSignature);
		bool setSignature(signature& sig);
		bool getSignature(uint32_t id, signature& sig);
		bool setMode(detectionMode mode);
		detectionMode getMode(void);
		bool setBrightness(uint8_t value);
		uint8_t getBrightness(void);
		bool setWhiteBalanceMode(whiteBalanceMode mode);
		whiteBalanceMode getWhiteBalanceMode(void);
		bool setWhiteBalanceValues(uint8_t red, uint8_t green, uint8_t blue);
		bool getWhiteBalanceValues(uint8_t* red, uint8_t* green, uint8_t* blue);
		bool setLedMode(ledMode mode);
		ledMode getLedMode(void);
		bool setLedBrightness(uint8_t percent);
		uint8_t getLedBrightness(void);
		bool setLedColor(uint8_t red, uint8_t green, uint8_t blue);
		bool getLedColor(uint8_t* red, uint8_t* green, uint8_t* blue);

		bool setWifiMode(wifiMode mode);
		wifiMode getWifiMode(void);

	  private:
		V5_DeviceVisionObject _objects[VISION_MAX_OBJECTS];

		void _clearObjects(void);
	};
}; // namespace vex

using VexVisionObject = vex::vision::object;
using VisionCode = vex::vision::code;

#endif
