#include "SplitTimer.h"
#include "Timing.h"

namespace LZSoft
{
	namespace Timing
	{
		float SplitTimer::Split()
		{
			QueryPerformanceCounter(&li);
			return float(li.QuadPart - elapsedLast) / Frequency;
		}
		float SplitTimer::SplitAndReset()
		{
			QueryPerformanceCounter(&li);
			elapsed = li.QuadPart - elapsedLast;
			elapsedLast = li.QuadPart;
			return float(elapsed) / Frequency;
		}
	}
}
