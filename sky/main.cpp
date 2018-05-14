#include <iostream>
#include <uv.h>
#include <stdio.h>
#include <stdlib.h>

void timer_cb(uv_timer_t *handle)
{
	std::cout << "111" << std::endl;

}

int main(int argc, char *argv[])
{
	std::cout << "hell, world!" << std::endl;

	uv_timer_t handle;
	uv_timer_init(uv_default_loop(), &handle);
	uv_timer_start(&handle, timer_cb, 3000, 2);

	uv_run(uv_default_loop(), UV_RUN_DEFAULT);


	std::cout << "bye bye" << std::endl;
	getchar();
	return 0;
}