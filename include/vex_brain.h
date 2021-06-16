#ifndef VEX_BRAIN_CLASS_H
#define VEX_BRAIN_CLASS_H

#include "vex_global.h"
#include "vex_timer.h"
#include "vex_triport.h"
#include <type_traits>

namespace vex {

	class brain {
		friend class competition;

	  private:
	  protected:
		static int32_t _getIndex();

	  public:
		brain();
		~brain();

		enum class tEventType {
			EVENT_LCD_PRESSED = 0,
			EVENT_LCD_RELEASED = 1
		};

		class lcd {
		  private:
			int32_t _row;
			int32_t _maxrows;
			int32_t _rowheight;

			int32_t _col;
			int32_t _maxcols;
			int32_t _colwidth;

			int32_t _penWidth;

			uint32_t _textbase;

			char _textStr[256];

			int32_t rowToPixel(int32_t row);
			int32_t colToPixel(int32_t col);

			bool _transparent;

			int _origin_x;
			int _origin_y;

#define FONT_MONO_CELL_WIDTH 10
#define FONT_MONO_CELL_HEIGHT 20
#define FONT_MONO_CELL_BASE 4

#define FONT_PROP_CELL_WIDTH 10
#define FONT_PROP_CELL_HEIGHT 20
#define FONT_PROP_CELL_BASE 4

		  public:
			lcd();
			~lcd(){};
			void setCursor(int32_t row, int32_t col);
			void setFont(fontType font);
			void setPenWidth(uint32_t width);
			void setOrigin(int32_t x, int32_t y);
			int32_t column();
			int32_t row();

			template <class T>
			void setPenColor(T color) { _setPenColor(static_cast<uint32_t>(color)); }

			void setPenColor(const color& color);
			void setPenColor(const char* color);
			void setPenColor(int hue);

			template <class T>
			void setFillColor(T color) { _setFillColor(static_cast<uint32_t>(color)); }

			void setFillColor(const color& color);
			void setFillColor(const char* color);
			void setFillColor(int hue);
			int32_t getStringWidth(const char* cstr);
			int32_t getStringHeight(const char* cstr);

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
			void printAt(int32_t x, int32_t y, const char* format, ...);
			void printAt(int32_t x, int32_t y, bool bOpaque, const char* format, ...);

			template <class T>
			void clearScreen(T color) { _clearScreen(static_cast<uint32_t>(color)); }

			void clearScreen(void);
			void clearScreen(const color& color);
			void clearScreen(const char* color);
			void clearScreen(int hue);

			template <class T1, class C>
			void clearLine(T1 number, C color) {
				if(std::is_same<C, vex::color>::value)
					clearLine(static_cast<int>(number), color);
				else if(std::is_same<C, const char*>::value)
					clearLine(static_cast<int>(number), color);
				else if(std::is_same<C, int>::value)
					clearLine(static_cast<int>(number), color);
				else
					_clearLine(static_cast<int>(number), static_cast<uint32_t>(color));
			}

			void clearLine(int number, const color& color);
			void clearLine(int number, const char* color);
			void clearLine(int number, int hue);
			void clearLine(int number);

			void clearLine(void);

			void newLine(void);
			void drawPixel(int x, int y);
			void drawLine(int x1, int y1, int x2, int y2);

			template <class T1, class T2, class T3, class T4, class C>
			void drawRectangle(T1 x, T2 y, T3 width, T4 height, C color) {
				if(std::is_same<C, vex::color>::value)
					drawRectangle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), color);
				else if(std::is_same<C, const char*>::value)
					drawRectangle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), color);
				else if(std::is_same<C, int>::value)
					drawRectangle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), color);
				else
					_drawRectangle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), static_cast<uint32_t>(color));
			}

			void drawRectangle(int x, int y, int width, int height);
			void drawRectangle(int x, int y, int width, int height, const color& color);
			void drawRectangle(int x, int y, int width, int height, const char* color);
			void drawRectangle(int x, int y, int width, int height, int hue);

			template <class T1, class T2, class T3, class C>
			void drawCircle(T1 x, T2 y, T3 radius, C color) {
				if(std::is_same<C, vex::color>::value)
					drawCircle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(radius), color);
				else if(std::is_same<C, const char*>::value)
					drawCircle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(radius), color);
				else if(std::is_same<C, int>::value)
					drawCircle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(radius), color);
				else
					_drawCircle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(radius), static_cast<uint32_t>(color));
			}

			void drawCircle(int x, int y, int radius);
			void drawCircle(int x, int y, int radius, const color& color);
			void drawCircle(int x, int y, int radius, const char* color);
			void drawCircle(int x, int y, int radius, int hue);
			void pressed(void (*callback)(void));
			void pressed(void (*callback)(void*), void* arg);
			void released(void (*callback)(void));
			void released(void (*callback)(void*), void* arg);
			int32_t xPosition();
			int32_t yPosition();
			bool pressing();
			bool render();
			bool render(bool bVsyncWait, bool bRunScheduler = true);
			void setClipRegion(int x, int y, int width, int height);
			bool drawImageFromBuffer(uint8_t* buffer, int x, int y, int bufferLen);
			bool drawImageFromBuffer(uint32_t* buffer, int x, int y, int width, int height);
			bool drawImageFromFile(const char* name, int x, int y);

			void waitForRefresh();
			void renderDisable();

			mevent PRESSED = {static_cast<uint32_t>(_getIndex()), static_cast<int>(tEventType::EVENT_LCD_PRESSED)};
			mevent RELEASED = {static_cast<uint32_t>(_getIndex()), static_cast<int>(tEventType::EVENT_LCD_RELEASED)};

		  private:
			void _setPenColor(uint32_t rgb);
			void _setFillColor(uint32_t rgb);
			void _clearScreen(uint32_t rgb);
			void _clearLine(int number, uint32_t rgb);
			void _drawRectangle(int x, int y, int width, int height, uint32_t rgb);
			void _drawCircle(int x, int y, int radius, uint32_t rgb);

			enum class tImageBufferType {
				kImageBufferTypeUnknown = 0,
				kImageBufferTypeBmp,
				kImageBufferTypePng
			};

			tImageBufferType _validateImageBuffer(uint8_t* buffer);

			uint32_t webColorToRgb(const char* color);
			uint32_t hueToRgb(uint32_t color);
		};

		double timer(timeUnits units);

		void resetTimer();
		void setTimer(double value, timeUnits units);

		vex::timer Timer;

		lcd Screen;

		triport ThreeWirePort = triport(PORT22);

		class battery {
		  public:
			battery(){};
			~battery(){};
			uint32_t capacity(percentUnits units = percentUnits::pct);
			double temperature(percentUnits units = percentUnits::pct);
			double temperature(temperatureUnits units);
			double voltage(voltageUnits units = voltageUnits::volt);
			double current(currentUnits units = currentUnits::amp);
		};

		battery Battery;

		class sdcard {
		  public:
			sdcard();
			~sdcard();
			bool isInserted();
			int32_t loadfile(const char* name, uint8_t* buffer, int32_t len);
			int32_t savefile(const char* name, uint8_t* buffer, int32_t len);
			int32_t appendfile(const char* name, uint8_t* buffer, int32_t len);
		};

		sdcard SDcard;
	};
}; // namespace vex

#endif
