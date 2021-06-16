#include "vex_thread.h"

vex::thread::~thread() {}

int32_t
vex::thread::get_id() {
	int32_t dummy;

	return dummy;
}

void vex::thread::join() {}

bool vex::thread::joinable() {
	bool dummy;

	return dummy;
}

void* vex::thread::native_handle() { return NULL; }

void vex::thread::swap(thread& __t) {}

void vex::thread::interrupt() {}

void vex::thread::interruptAll() {}

void vex::thread::setPriority(int32_t priority) {}

int32_t
vex::thread::priority() {
	int32_t dummy;

	return dummy;
}

int32_t
vex::thread::hardware_concurrency() {
	int32_t dummy;

	return dummy;
}

int32_t
vex::this_thread::get_id() {
	int32_t dummy;

	return dummy;
}

void vex::this_thread::yield() {}

void vex::this_thread::sleep_for(uint32_t time) {}

void vex::this_thread::sleep_until(uint32_t time) {}

void vex::this_thread::setPriority(int32_t priority) {}

int32_t
vex::this_thread::priority() {
	int32_t dummy;

	return dummy;
}

vex::mutex::mutex() {}

vex::mutex::~mutex() {}

void vex::mutex::lock() {}

bool vex::mutex::try_lock() {
	bool dummy;

	return dummy;
}

void vex::mutex::unlock() {}
