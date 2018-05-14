#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Timer.h"

void hello()
{
	std::cout << "hello" << std::endl;
}

int main(int argc, char *argv[])
{
	Loop loop;

	Timer t(loop);
	t.setCallback(hello);
	t.start(1000);
	
	loop.run();

	std::cout << "bye bye" << std::endl;
	getchar();
	return 0;
}