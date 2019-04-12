#include "FrameTimer.h"

ccm::FrameTimer::FrameTimer()
{
	start = Clock::now();
}

float ccm::FrameTimer::mark()
{
	end = Clock::now();
	Duration dur = end - start;
	start = end;
	return dur.count();
}
