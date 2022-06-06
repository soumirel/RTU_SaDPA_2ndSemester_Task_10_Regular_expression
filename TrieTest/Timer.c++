#include "Timer.h"

Timer::Timer()
{
	begin = std::chrono::high_resolution_clock::now();
}


Timer::~Timer()
{
	end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Passed time: " << duration.count() << " microseconds.\n";
}