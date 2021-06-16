#ifndef VEX_EVENT_CLASS_H
#define VEX_EVENT_CLASS_H

#include <cstdint>

namespace vex {
	class event {
	  private:
		static uint32_t _usereventid;
		void (*_callback)(void);
		int _userid;

	  public:
		event();
		event(uint32_t index, uint32_t mask, void (*callback)(void));
		event(void (*callback)(void));
		event(event v, void (*callback)(void));
		event(void (*callback)(void*), void* arg);
		event(event v, void (*callback)(void*), void* arg);
		~event();

		static void init(uint32_t index, uint32_t mask, void (*callback)(void));

		static void init(uint32_t index, uint32_t mask, void (*callback)(int));
		static void init(uint32_t index, uint32_t mask, void (*callback)(void*), void* arg);
		static int32_t userindex(void);

		void set(void (*callback)(void));
		void operator()(void (*callback)(void));

		void broadcast();

		void broadcastAndWait(int32_t timeout = 60000);
		static void broadcast(uint32_t index);
		static void broadcastAndWait(uint32_t index, int32_t timeout = 60000);
	};
}; // namespace vex

#endif
