#ifndef VEX_THREAD_CLASS_H
#define VEX_THREAD_CLASS_H

#include <chrono>

namespace vex {

	class thread {
	  private:
		static int _labelId;
		void* _callback;
		int _callbackId;

	  public:
		thread()
			: _callback(NULL){};

		thread(int (*callback)(void));

		thread(int (*callback)(void*), void* arg);

		thread(void (*callback)(void))
			: thread((int (*)(void))callback) {}

		thread(void (*callback)(void*), void* arg)
			: thread((int (*)(void*))callback, arg) {}

		~thread();

		static const int32_t threadPrioritylow = 1;
		static const int32_t threadPriorityNormal = 7;
		static const int32_t threadPriorityHigh = 15;
		int32_t get_id();

		void join();

		void detach(){};
		bool joinable();

		void* native_handle();
		void swap(thread& __t);
		void interrupt();

		static void interruptAll();
		void setPriority(int32_t priority);
		int32_t priority();
		static int32_t hardware_concurrency();
		static void swap(thread& __x, thread& __y) { __x.swap(__y); }
	};

	namespace this_thread {

		int32_t get_id();

		void yield();
		void sleep_for(uint32_t time);

		template <typename _Rep, typename _Period>
		void
		sleep_for(const std::chrono::duration<_Rep, _Period>& __rtime) {
			if(__rtime <= __rtime.zero()) return;

			int __ms = std::chrono::duration_cast<std::chrono::milliseconds>(__rtime).count();
			sleep_for(static_cast<uint32_t>(__ms));
		}

		void sleep_until(uint32_t time);

		template <typename _Clock, typename _Duration>
		void
		sleep_until(const std::chrono::time_point<_Clock, _Duration>& __atime) {
			auto __now = _Clock::now();
			if(__now < __atime) sleep_for(__atime - __now);
		}

		void setPriority(int32_t priority);

		int32_t priority();
	}; // namespace this_thread

	class mutex {
	  private:
		uint32_t _sem;

	  public:
		mutex();
		~mutex();

		void lock();

		bool try_lock();

		void unlock();
	};
}; // namespace vex

#endif
