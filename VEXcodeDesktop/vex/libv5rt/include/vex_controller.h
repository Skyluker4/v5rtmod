#ifndef VEX_CONTROLLER_CLASS_H
#define VEX_CONTROLLER_CLASS_H

#include "vex_mevent.h"
#include "vex_units.h"
#include <functional>

namespace vex {

	class controller {
	  private:
		controllerType _controllerId;

		int32_t _index;

		int32_t value(V5_ControllerIndex channel);

	  protected:
		int32_t _getIndex();

	  public:
		controller();

		controller(controllerType id);
		~controller();

		bool installed();
		void rumble(const char* str);

	  private:
		enum class tEventType {
			EVENT_5_UP_PRESSED = 0,
			EVENT_5_UP_RELEASED = 1,
			EVENT_5_DN_PRESSED = 2,
			EVENT_5_DN_RELEASED = 3,

			EVENT_6_UP_PRESSED = 4,
			EVENT_6_UP_RELEASED = 5,
			EVENT_6_DN_PRESSED = 6,
			EVENT_6_DN_RELEASED = 7,

			EVENT_7_UP_PRESSED = 8,
			EVENT_7_UP_RELEASED = 9,
			EVENT_7_DN_PRESSED = 10,
			EVENT_7_DN_RELEASED = 11,

			EVENT_7_L_PRESSED = 12,
			EVENT_7_L_RELEASED = 13,
			EVENT_7_R_PRESSED = 14,
			EVENT_7_R_RELEASED = 15,

			EVENT_8_UP_PRESSED = 16,
			EVENT_8_UP_RELEASED = 17,
			EVENT_8_DN_PRESSED = 18,
			EVENT_8_DN_RELEASED = 19,

			EVENT_8_L_PRESSED = 20,
			EVENT_8_L_RELEASED = 21,
			EVENT_8_R_PRESSED = 22,
			EVENT_8_R_RELEASED = 23,

			EVENT_A_CHANGED = 24,
			EVENT_B_CHANGED = 25,
			EVENT_C_CHANGED = 26,
			EVENT_D_CHANGED = 27
		};

		enum class tButtonType {
			kButton5Up = 0,
			kButton5Down,
			kButton6Up,
			kButton6Down,
			kButton7Up,
			kButton7Down,
			kButton7Left,
			kButton7Right,
			kButton8Up,
			kButton8Down,
			kButton8Left,
			kButton8Right,

			kButtonL1 = 0,
			kButtonL2,
			kButtonR1,
			kButtonR2,
			kButtonUp,
			kButtonDown,
			kButtonLeft,
			kButtonRight,
			kButtonX,
			kButtonB,
			kButtonY,
			kButtonA,

			kButtonUndefined
		};

	  public:
		class button {
		  private:
			tButtonType _id;
			controller* _parent;
			tEventType _buttonToPressedEvent();
			tEventType _buttonToReleasedEvent();

		  public:
			button()
				: _id(tButtonType::kButtonUndefined),
				  _parent(NULL){};

			button(const tButtonType id, controller* parent)
				: _id(id),
				  _parent(parent){};
			~button(){};

			void pressed(void (*callback)(void));
			void released(void (*callback)(void));
			bool pressing(void);

			mevent PRESSED = {static_cast<uint32_t>(_parent->_getIndex()), static_cast<uint32_t>(_buttonToPressedEvent())};
			mevent RELEASED = {static_cast<uint32_t>(_parent->_getIndex()), static_cast<uint32_t>(_buttonToReleasedEvent())};
		};

	  private:
		button button5Up = button(tButtonType::kButton5Up, this);
		button button5Down = button(tButtonType::kButton5Down, this);
		button button6Up = button(tButtonType::kButton6Up, this);
		button button6Down = button(tButtonType::kButton6Down, this);
		button button7Up = button(tButtonType::kButton7Up, this);
		button button7Down = button(tButtonType::kButton7Down, this);
		button button7Left = button(tButtonType::kButton7Left, this);
		button button7Right = button(tButtonType::kButton7Right, this);
		button button8Up = button(tButtonType::kButton8Up, this);
		button button8Down = button(tButtonType::kButton8Down, this);
		button button8Left = button(tButtonType::kButton8Left, this);
		button button8Right = button(tButtonType::kButton8Right, this);

	  public:
		button& ButtonL1 = button5Up;

		button& ButtonL2 = button5Down;

		button& ButtonR1 = button6Up;

		button& ButtonR2 = button6Down;

		button& ButtonUp = button7Up;

		button& ButtonDown = button7Down;

		button& ButtonLeft = button7Left;

		button& ButtonRight = button7Right;

		button& ButtonX = button8Up;

		button& ButtonB = button8Down;

		button& ButtonY = button8Left;

		button& ButtonA = button8Right;

	  private:
		enum class tAxisType {
			kAxisA = 0,
			kAxisB,
			kAxisC,
			kAxisD,

			kAxisUndefined
		};

	  public:
		class axis {
		  private:
			tAxisType _id;
			controller* _parent;
			tEventType _joystickToChangedEvent();

		  public:
			axis()
				: _id(tAxisType::kAxisUndefined),
				  _parent(NULL){};

			axis(const tAxisType id, controller* parent)
				: _id(id),
				  _parent(parent){};
			~axis(){};
			void changed(void (*callback)(void));
			int32_t value(void);
			int32_t position(percentUnits units = percentUnits::pct);

			mevent CHANGED = {static_cast<uint32_t>(_parent->_getIndex()), static_cast<uint32_t>(_joystickToChangedEvent())};
		};

	  private:
		axis AxisA = axis(tAxisType::kAxisA, this);
		axis AxisB = axis(tAxisType::kAxisB, this);
		axis AxisC = axis(tAxisType::kAxisC, this);
		axis AxisD = axis(tAxisType::kAxisD, this);

	  public:
		axis& Axis1 = AxisC;

		axis& Axis2 = AxisD;

		axis& Axis3 = AxisA;

		axis& Axis4 = AxisB;

		class lcd {
		  private:
			controller* _parent;
			int32_t _row;
			int32_t _maxrows;
			int32_t _col;
			int32_t _maxcols;

			char _textStr[32];

			controllerType getControllerId();

		  public:
			lcd();
			lcd(controller* parent);
			~lcd(){};
			void setCursor(int32_t row, int32_t col);
			int32_t column();
			int32_t row();

			template <class T>
			void print(T value) {
				if(std::is_same<T, int>::value)
					print("%d", static_cast<int>(value));
				else if(std::is_same<T, double>::value)
					print("%.2f", static_cast<double>(value));
				else {
					if(static_cast<int>(value) == value)
						print("%d", static_cast<int>(value));
					else
						print("%.2f", static_cast<double>(value));
				}
			}

			void print(const char* format, ...);
			void print(char* format, ...);

			void clearScreen(void);
			void clearLine(int number);

			void clearLine(void);

			void newLine(void);
		};

		lcd Screen = lcd(this);

		lcd& LCD = Screen;
	};
}; // namespace vex

#endif
