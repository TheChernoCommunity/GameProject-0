#include "FrameTimer.h"

ccm::FrameTimer::FrameTimer()
{
	m_start = Clock::now();
}

float ccm::FrameTimer::mark()
{
	m_end = Clock::now();
	Duration dur = m_end - m_start;
	m_start = m_end;
	return dur.count();
}
