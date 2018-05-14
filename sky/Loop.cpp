#include "Loop.h"

Loop::Loop(int mode)
	: mode_((uv_run_mode)mode)
{
	if (mode == UV_RUN_DEFAULT) {
		loop_ = uv_default_loop();
	} else {
		loop_ = new uv_loop_t();
		uv_loop_init(loop_);
	}
}

Loop::~Loop()
{
	uv_loop_close(loop_);
	if (mode_ != UV_RUN_DEFAULT) {
		delete loop_;
	}
}

void Loop::run()
{
	uv_run(loop_, mode_);
}

uv_loop_t* Loop::operator()()
{
	return loop_;
}

