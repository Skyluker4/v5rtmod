#ifndef VEX_IMU_CLASS_H
#define VEX_IMU_CLASS_H

#include "vex_device.h"

namespace vex {

	class inertial : public device, public guido {
	  private:
		double _offset_h;
		double _offset_r;
		uint32_t _cal_delay;

		double _scaleRotationValue(double value, rotationUnits units);

		static void _collisionEventHandler(void* arg);
		void (*_collisionCallback)(axisType, double, double, double);

	  public:
		inertial(int32_t index);
		~inertial() override;

		bool installed() override;
		int32_t value() override;

		class matrix {
		  public:
			matrix();
			~matrix();

			double data[4][4];

			void transform(double& x, double& y, double& z);
			void multiply(matrix& m);
			double inverse();
		};

		class quaternion {
		  public:
			quaternion();
			quaternion(double a, double b, double c, double d);
			~quaternion();

			double a;
			double b;
			double c;
			double d;

			quaternion& operator=(quaternion other);

			quaternion conjugate() const;

			quaternion normalized() const;

			quaternion operator*(const quaternion& rhs) const;

			quaternion& operator*=(const quaternion& rhs);

			void transform(double& x, double& y, double& z);

			static quaternion fromAngleX(double angle);
			static quaternion fromAngleY(double angle);
			static quaternion fromAngleZ(double angle);

			void matrix(matrix& m);
		};

		class attitude {
		  public:
			attitude();
			attitude(double roll, double pitch, double yaw);
			~attitude();

			double roll;
			double pitch;
			double yaw;

			double& x = roll;
			double& y = pitch;
			double& z = yaw;

			void transform(double& x, double& y, double& z);
		};

		void startCalibration(int32_t value = 0);

		void calibrate(int32_t value = 0) override { startCalibration(value); }

		bool isCalibrating(void) override;

		void resetHeading();

		void resetRotation();

		void setHeading(double value, rotationUnits units) override;

		void setRotation(double value, rotationUnits units) override;

		double angle(rotationUnits units = rotationUnits::deg) override;

		double roll(rotationUnits units = rotationUnits::deg);

		double pitch(rotationUnits units = rotationUnits::deg);

		double yaw(rotationUnits units = rotationUnits::deg);

		double orientation(orientationType axis, rotationUnits units);

		double heading(rotationUnits units = rotationUnits::deg) override;

		double rotation(rotationUnits units = rotationUnits::deg) override;

		void orientation(quaternion& q);

		quaternion orientation();

		void orientation(attitude& a);

		double gyroRate(axisType axis, velocityUnits units);

		double acceleration(axisType axis);

		enum class tEventType {
			EVENT_HEADING_CHANGED = 0,
			EVENT_COLLISION = 1,

			EVENT_COLLISION_AXIS_X = 8,
			EVENT_COLLISION_AXIS_Y = 9,
			EVENT_COLLISION_AXIS_Z = 10
		};

		void changed(void (*callback)(void));

		void collision(void (*callback)(axisType, double, double, double));

	  protected:
		int32_t status();

		double temperature();

		class gyro {
			friend inertial;

		  private:
			double _gx;
			double _gy;
			double _gz;

		  public:
			gyro();
			~gyro();

			gyro& operator=(gyro other);

			double& gx = _gx;
			double& gy = _gy;
			double& gz = _gz;
		};

		class accel {
			friend inertial;

		  private:
			double _ax;
			double _ay;
			double _az;

		  public:
			accel();
			~accel();

			accel& operator=(accel other);

			double& ax = _ax;
			double& ay = _ay;
			double& az = _az;
		};

		gyro gyroRate();

		accel acceleration();

		enum class orientationMode {
			ZUp,
			ZDown,
			XUp,
			XDown,
			YUp,
			YDown,
			Auto
		};

		void setOrientation(orientationMode orientation);

		void setAccelerometerRange(uint8_t value);
		void setCollisionThreshold(double value);
	};
}; // namespace vex

#endif
