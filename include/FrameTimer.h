#pragma once

#include <chrono>
namespace ccm
{

	class FrameTimer
	{
	public:
		using Clock = std::chrono::steady_clock;
		using TimeType = float;
		using Duration = std::chrono::duration<TimeType, std::milli>;
	public:
		FrameTimer();
		~FrameTimer() = default;

		float mark();
	private:
		Clock::time_point m_start, m_end;
	};
}