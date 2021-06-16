#ifndef VEX_TRIPORT_CLASS_H
#define VEX_TRIPORT_CLASS_H

#include "vex_device.h"
#include "vex_mevent.h"
#include <cstddef>

namespace vex {

	class triport : public device {
	  public:
		enum class tEventType {
			EVENT_DIN_HIGH = 0,
			EVENT_DIN_LOW = 1,
			EVENT_AIN_CHANGED = 2
		};

	  private:
		uint32_t _id = 0;

		void _setport(){};
		void _configPort(uint32_t id, triportType type);

		template <typename first, typename... Args>
		void _setport(first port, Args... args) {
			_configPort(_id++, port);
			_setport(args...);
		}

		int32_t _getIndex();

		V5_AdiPortConfiguration _internalType(triportType type);
		triportType _externalType(V5_AdiPortConfiguration type);

	  public:
		triport(int32_t index);
		~triport() override;

		template <typename... Args>
		triport(int32_t index, Args... args)
			: triport(index) { _setport(args...); }

		bool installed() override;

		class port {
			friend class __tridevice;

		  private:
			int32_t _id;
			triport* _parent;
			int32_t _convertAnalog(analogUnits units);
			int32_t _virtual_value(int32_t virtual_port);

		  public:
			port()
				: _id(-1),
				  _parent(NULL){};
			port(int32_t id, triport* parent);
			port(int32_t id, triportType type, triport* parent);
			~port(){};

			void type(triportType type);

			triportType type();

			void value(int32_t value);

			int32_t value();

			void set(bool value);
			void pressed(void (*callback)(void));

			void released(void (*callback)(void));

			void changed(void (*callback)(void));

			void operator()(const triportType type) { this->type(type); }
			void operator=(const int32_t value) { this->value(value); }
			operator int() { return this->value(); }
			operator bool() { return (this->value() > 0) ? true : false; }

			void resetRotation(void);
			void setRotation(double val, rotationUnits units);
			double rotation(rotationUnits units);
			double velocity(velocityUnits units);
			double distance(distanceUnits units);

			mevent PRESSED = {static_cast<uint32_t>(_parent->_getIndex()), (static_cast<uint32_t>(tEventType::EVENT_DIN_HIGH) + (_id << 2))};
			mevent RELEASED = {static_cast<uint32_t>(_parent->_getIndex()), (static_cast<uint32_t>(tEventType::EVENT_DIN_LOW) + (_id << 2))};
			mevent CHANGED = {static_cast<uint32_t>(_parent->_getIndex()), (static_cast<uint32_t>(tEventType::EVENT_AIN_CHANGED) + (_id << 2))};

			mevent& HIGH = PRESSED;
			mevent& LOW = RELEASED;
		};

		port Port[8] = {{0, this},
						{1, this},
						{2, this},
						{3, this},
						{4, this},
						{5, this},
						{6, this},
						{7, this}};
		port& A = Port[0];
		port& B = Port[1];
		port& C = Port[2];
		port& D = Port[3];
		port& E = Port[4];
		port& F = Port[5];
		port& G = Port[6];
		port& H = Port[7];
	};

	class __tridevice {
	  protected:
		triport::port& _port;

		int32_t _convertAnalog(analogUnits units);
		int32_t _virtual_value(int32_t virtual_port);

		mevent& _PRESSED = _port.PRESSED;
		mevent& _RELEASED = _port.RELEASED;
		mevent& _CHANGED = _port.CHANGED;
		mevent& _HIGH = _port.HIGH;
		mevent& _LOW = _port.LOW;

	  public:
		__tridevice(triport::port& port, triportType type);

	  protected:
		~__tridevice();
	};

	class limit : private __tridevice {
	  public:
		limit(triport::port& port);
		~limit();
		int32_t value();
		int32_t pressing() { return value(); };
		void pressed(void (*callback)(void));
		void released(void (*callback)(void));

		operator int();
		operator bool();

		mevent& PRESSED = _PRESSED;
		mevent& RELEASED = _RELEASED;
	};

	class bumper : private __tridevice {
	  public:
		bumper(triport::port& port);
		~bumper();
		int32_t value();
		int32_t pressing() { return value(); };
		void pressed(void (*callback)(void));
		void released(void (*callback)(void));

		operator int();
		operator bool();

		mevent& PRESSED = _PRESSED;
		mevent& RELEASED = _RELEASED;
	};

	class digital_in : private __tridevice {
	  public:
		digital_in(triport::port& port);
		~digital_in();
		int32_t value();
		void high(void (*callback)(void));
		void low(void (*callback)(void));

		operator int();
		operator bool();

		mevent& HIGH = _LOW;
		mevent& LOW = _HIGH;
	};

	class digital_out : private __tridevice {
	  public:
		digital_out(triport::port& port);
		~digital_out();
		int32_t value();
		void set(bool value);
		operator int();
		operator bool();
		void operator=(int32_t value);
	};

	class led : public digital_out {
	  public:
		led(triport::port& port);
		~led();

		void on();

		void off();
	};

	class pneumatics : public digital_out {
	  public:
		pneumatics(triport::port& port);
		~pneumatics();

		void open();

		void close();
	};

	class pot : private __tridevice {
	  public:
		pot(triport::port& port);
		~pot();
		int32_t value(analogUnits units);
		int32_t value(percentUnits units) { return value(analogUnits::pct); };

		int32_t angle(percentUnits units = percentUnits::pct) { return value(units); };
		double value(rotationUnits units);

		double angle(rotationUnits units) { return value(units); };
		void changed(void (*callback)(void));

		mevent& CHANGED = _CHANGED;
	};

	class line : private __tridevice {
	  public:
		line(triport::port& port);
		~line();
		int32_t value(analogUnits units);

		int32_t reflectivity(percentUnits units = percentUnits::pct);
		int32_t value(percentUnits units) { return value(analogUnits::pct); };
		void changed(void (*callback)(void));

		mevent& CHANGED = _CHANGED;
	};

	class light : private __tridevice {
	  public:
		light(triport::port& port);
		~light();
		int32_t value(analogUnits units);

		int32_t brightness(percentUnits units = percentUnits::pct);
		int32_t value(percentUnits units) { return value(analogUnits::pct); };
		void changed(void (*callback)(void));

		mevent& CHANGED = _CHANGED;
	};

	class gyro : private __tridevice, public guido {
	  private:
		int32_t _offset_h;
		int32_t _offset_r;
		uint32_t _cal_delay;

	  public:
		gyro(triport::port& port);
		~gyro() override;
		int32_t value(analogUnits units);
		double value(rotationUnits units);
		int32_t value(percentUnits units) { return value(analogUnits::pct); };
		void startCalibration(int32_t value = 0);

		void calibrate(int32_t value = 0) override { startCalibration(value); }
		bool isCalibrating() override;
		void changed(void (*callback)(void));

		void resetAngle();

		void resetHeading();

		void resetRotation();

		void resetAngle(double value, rotationUnits units);

		void setHeading(double value, rotationUnits units) override;

		double angle(rotationUnits units = rotationUnits::deg) override;

		double heading(rotationUnits units = rotationUnits::deg) override;

		double rotation(rotationUnits units = rotationUnits::deg) override;

		void setRotation(double value, rotationUnits units) override;

		mevent& CHANGED = _CHANGED;
	};

	class accelerometer : private __tridevice {
	  public:
		accelerometer(triport::port& port, bool bHighSensitivity = false);
		~accelerometer();
		int32_t value(analogUnits units);
		int32_t value(percentUnits units) { return value(analogUnits::pct); };

		double acceleration();
		void changed(void (*callback)(void));

		mevent& CHANGED = _CHANGED;

	  private:
		bool highSensitivity;
	};

	class analog_in : private __tridevice {
	  public:
		analog_in(triport::port& port);
		~analog_in();
		int32_t value(analogUnits units);
		int32_t value(percentUnits units) { return value(analogUnits::pct); };
		void changed(void (*callback)(void));

		mevent& CHANGED = _CHANGED;
	};

	class encoder : private __tridevice {
	  public:
		encoder(triport::port& port);
		~encoder();
		int32_t value();
		operator int();

		void resetRotation(void);
		void setRotation(double val, rotationUnits units);

		void setPosition(double val, rotationUnits units);
		double rotation(rotationUnits units);

		double position(rotationUnits units);
		double velocity(velocityUnits units);
		void changed(void (*callback)(void));

		mevent& CHANGED = _CHANGED;
	};

	class sonar : private __tridevice {
	  public:
		sonar(triport::port& port);
		~sonar();
		int32_t value();
		operator int();
		double distance(distanceUnits units);
		void changed(void (*callback)(void));

		mevent& CHANGED = _CHANGED;

		void setMaximum(double distance, distanceUnits units);

		bool foundObject();

	  private:
		uint32_t _maxdistance;
		uint32_t _mindistance;

		void setMinimum(double distance, distanceUnits units);
	};

	class pwm_out : private __tridevice {
	  public:
		pwm_out(triport::port& port);
		~pwm_out();
		void state(int32_t value, percentUnits units);
	};

	class servo : private __tridevice {
	  public:
		servo(triport::port& port);
		~servo();
		void setPosition(int32_t value, percentUnits units);
		void setPosition(double value, rotationUnits units);
		void startRotateTo(int32_t value, percentUnits units) { setPosition(value, units); }
		void startRotateTo(double value, rotationUnits units) { setPosition(value, units); }
	};

	class motor29 : private __tridevice {
	  private:
		bool _reversed;
		int32_t _velocity;
		bool _spinMode;

	  public:
		motor29(triport::port& port);
		motor29(triport::port& port, bool reverse);
		~motor29();
		void setVelocity(double velocity, percentUnits units);
		void setReversed(bool value);
		void spin(directionType dir);
		void spin(directionType dir, double velocity, velocityUnits units);

		void spin(directionType dir, double velocity, percentUnits units) { spin(dir, velocity, static_cast<velocityUnits>(units)); };

		void stop(void);
	};

	class motor_victor : private __tridevice {
	  private:
		bool _reversed;
		int32_t _velocity;
		bool _spinMode;

	  public:
		motor_victor(triport::port& port);
		motor_victor(triport::port& port, bool reverse);
		~motor_victor();
		void setVelocity(double velocity, percentUnits units);
		void setReversed(bool value);
		void spin(directionType dir);
		void spin(directionType dir, double velocity, velocityUnits units);

		void spin(directionType dir, double velocity, percentUnits units) { spin(dir, velocity, static_cast<velocityUnits>(units)); };

		void stop(void);
	};

}; // namespace vex

#endif
