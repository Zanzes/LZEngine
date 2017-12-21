#ifdef PROFILING_ON
#include "Profile.h"
#include "Profiler.h"

namespace LZSoft
{
	namespace Profiling
	{
		Timing::SplitTimer stimer;
		Profile::Profile(const char * const name) : Name(name)
		{
			stimer.SplitAndReset();
		}
		Profile::~Profile()
		{
			const float split = stimer.Split();
			profiler.addEntry(Name, split);
		}
	}
}
#endif
