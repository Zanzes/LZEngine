#include "FrameTimer.h"
#include "Timing.h"
#include <Windows.h>

namespace LZSoft
{
	namespace Timing
	{
		LARGE_INTEGER li;
		long long FrameTimer::elapsed;
		long long FrameTimer::elapsedLast;

		float FrameTimer::Frame()
		{
			QueryPerformanceCounter(&li);
			elapsed = li.QuadPart - elapsedLast;
			elapsedLast = li.QuadPart;
			return float(elapsed) / Frequency;
		}
	}
}