#ifndef VEX_COLOR_CLASS_H
#define VEX_COLOR_CLASS_H

#include <cstdint>

namespace vex {
	class color {
	  private:
		uint32_t _argb;
		bool _transparent;

		color(int value, bool transparent);

	  public:
		color();

		color(int value);

		color(uint8_t r, uint8_t g, uint8_t b);
		~color();

		uint32_t rgb(uint32_t value);
		uint32_t rgb(uint8_t r, uint8_t g, uint8_t b);
		void operator=(uint32_t value);

		uint32_t rgb() const;
		operator uint32_t() const;

		bool isTransparent() const;

		color& hsv(uint32_t hue, double sat, double value);

		color& web(const char* color);

		static const color black;

		static const color white;

		static const color red;

		static const color green;

		static const color blue;

		static const color yellow;

		static const color orange;

		static const color purple;

		static const color cyan;

		static const color transparent;
	};
} // namespace vex

#endif
