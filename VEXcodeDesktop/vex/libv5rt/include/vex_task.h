#ifndef VEX_TASK_CLASS_H
#define VEX_TASK_CLASS_H

// If using RobotC for somereason, idk
#ifdef task
#undef task
#endif

#include <cstdint>

namespace vex {

	class task {
		friend class competition;

	  private:
		static int _labelId;
		void* _callback;
		int _callbackId;

	  protected:
		static int32_t _index(int (*callback)(void));
		static void _stopAll();
		static void _dump();

	  public:
		task();

		task(int (*callback)(void));
		task(int (*callback)(void*), void* arg);
		task(int (*callback)(void), int32_t priority);
		task(int (*callback)(void*), void* arg, int32_t priority);
		~task();

		static const int32_t taskPrioritylow = 1;
		static const int32_t taskPriorityNormal = 7;
		static const int32_t taskPriorityHigh = 15;
		static void stop(const task& t);
		static void suspend(const task& t);
		static void resume(const task& t);
		static int32_t priority(const task& t);
		static void setPriority(const task& t, int32_t priority);
		void stop();

		void suspend();

		void resume();
		int32_t priority();
		void setPriority(int32_t priority);
		int32_t index(void);
		static void sleep(uint32_t time);

		static void yield();
		static void stop(void* callback, int callbackId = 0);

		static void stopAll();
	};
}; // namespace vex

namespace vex {

	class semaphore {
	  private:
		static bool _initialized;
		uint32_t _sem;

	  protected:
	  public:
		semaphore();
		~semaphore();
		void lock();
		void lock(uint32_t time);

		void unlock();
		bool owner();
	};
}; // namespace vex

#endif
