#ifndef SKY_LOOP_H
#define SKY_LOOP_H

#include <uv.h>
#include "util.h"

class Loop
{
public:
	explicit Loop(int mode = UV_RUN_DEFAULT);
	~Loop();

	void run();
	uv_loop_t* operator()();
	
private:
	uv_run_mode mode_;
	uv_loop_t *loop_;
	DISALLOW_COPY(Loop);
};

#endif // SKY_LOOP_H