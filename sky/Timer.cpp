#include "Timer.h"

Timer::Timer(Loop &loop)
	: timeout_(0)
{
	uv_timer_init(loop(), &handle_);
	handle_.data = nullptr;
}

Timer::Timer(Loop &loop, int timeout, const std::function<void()> &cb)
	: timeout_(timeout)
	, cb_(cb)
{
	uv_timer_init(loop(), &handle_);
	handle_.data = nullptr;
}

Timer::~Timer()
{
	stop();
}

void Timer::start(int afterMilliseonds)
{
	stop();
	handle_.data = this;
	uv_timer_start(&handle_, timer_cb, afterMilliseonds, timeout_);
}

void Timer::stop()
{
	if (handle_.data) {
		handle_.data = nullptr;
		uv_timer_stop(&handle_);
	}
}

void Timer::setCallback(const std::function<void()> &cb)
{
	cb_ = cb;
}

void Timer::setTimeout(int milliseconds)
{
	uv_timer_set_repeat(&handle_, milliseconds);
}

void Timer::timer_cb(uv_timer_t *handle)
{
	if (handle && handle->data) {
		Timer *t = (Timer*)handle->data;
		if (t->cb_) {
			t->cb_();
		}
	}
}
