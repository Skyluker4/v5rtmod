#ifndef VEX_DEVICE_CLASS_H
#define VEX_DEVICE_CLASS_H

#include "v5_apiprivate.h"
#include "vex_units.h"

namespace vex {

	class device {
	  private:
		V5_DeviceT _ptr;

	  protected:
		int32_t _index;
		int32_t _threadID;

	  public:
		device();
		device(int32_t index);
		virtual ~device();

		V5_DeviceType type();
		int32_t index();
		void init(int32_t index);
		virtual bool installed();
		virtual int32_t value();
	};
}; // namespace vex

namespace vex {
	template <class T, int len>
	class safearray {
	  private:
		int length;

	  protected:
		T arr[len];
		T outofbounds;

	  public:
		safearray() {
			length = len;
			outofbounds = 0;
		};
		~safearray(){};

		T& operator[](int i);
		int getLength() { return length; };
	};

	template <class T, int len>
	T& safearray<T, len>::operator[](int i) {
		if(i < 0 || i > (length - 1)) { return (outofbounds); }
		return (arr[i]);
	}
}; // namespace vex
namespace vex {
	class guido {
	  public:
		guido(){};
		virtual ~guido(){};

		virtual double angle(rotationUnits units = rotationUnits::deg) = 0;
		virtual double heading(rotationUnits units = rotationUnits::deg) = 0;
		virtual void calibrate(int32_t value) = 0;
		virtual bool isCalibrating(void) = 0;
		virtual void setHeading(double value, rotationUnits units) = 0;
		virtual double rotation(rotationUnits units = rotationUnits::deg) = 0;
		virtual void setRotation(double value, rotationUnits units) = 0;
	};
}; // namespace vex

namespace vex {

	class devices {
	  private:
		safearray<device, V5_MAX_DEVICE_PORTS> data;

	  public:
		devices();
		~devices();

		device& operator[](int i) { return (data[i]); }
		V5_DeviceType type(int32_t index);
		int32_t number();
		int32_t numberOf(V5_DeviceType type);
	};
}; // namespace vex

#endif
