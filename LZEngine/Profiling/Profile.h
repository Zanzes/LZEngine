#pragma once
#ifdef PROFILING_ON
#include <Timing/SplitTimer.h>
#endif

namespace LZSoft
{
	namespace Profiling
	{
		class __declspec(dllexport) Profile
		{
#ifdef PROFILING_ON
			Timing::SplitTimer stimer;
			const char * const Name;
#endif
		public:
#ifdef PROFILING_ON
			Profile(const char * const name);
			~Profile();
#else
			Profile(const char * const name) {};
			~Profile() {};
#endif
		};
#ifdef PROFILING_ON
#define  PROFILE(text) LZSoft::Profiling::Profile P(text)
#else
#define  PROFILE(text)
#endif
	}
}
