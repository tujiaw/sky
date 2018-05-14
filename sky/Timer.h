#ifndef SKY_TIMER_H
#define SKY_TIMER_H

#include <functional>
#include "Loop.h"

class Timer {
public:
	explicit Timer(Loop &loop);
	Timer(Loop &loop, int timeout, const std::function<void()> &cb);
	~Timer();

	void start(int afterMilliseonds = 0);
	void stop();

	void setCallback(const std::function<void()> &cb);
	void setTimeout(int milliseconds);

private:
	static void timer_cb(uv_timer_t *handle);

private:
	int timeout_;
	uv_timer_t handle_;
	std::function<void()> cb_;
	DISALLOW_COPY(Timer)
};

#endif // SKY_TIMER_H
