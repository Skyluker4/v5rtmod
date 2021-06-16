#include "vex_task.h"

void vex::task::_stopAll() {}

void vex::task::_dump() {}

vex::task::task() {}

vex::task::~task() {}

void vex::task::stop(const task& t) {}

void vex::task::suspend(const task& t) {}

void vex::task::resume(const task& t) {}

int32_t
vex::task::priority(const task& t) {
	int32_t dummy;

	return dummy;
}

void vex::task::setPriority(const task& t, int32_t priority) {}

void vex::task::stop() {}

void vex::task::suspend() {}

void vex::task::resume() {}

int32_t
vex::task::priority() {
	int32_t dummy;

	return dummy;
}

void vex::task::setPriority(int32_t priority) {}

int32_t
vex::task::index(void) {
	int32_t dummy;

	return dummy;
}

void vex::task::sleep(uint32_t time) {}

void vex::task::yield() {}

void vex::task::stop(void* callback, int callbackId) {}

void vex::task::stopAll() {}

vex::semaphore::semaphore() {}

vex::semaphore::~semaphore() {}

void vex::semaphore::lock() {}

void vex::semaphore::lock(uint32_t time) {}

void vex::semaphore::unlock() {}

bool vex::semaphore::owner() {
	bool dummy;

	return dummy;
}
