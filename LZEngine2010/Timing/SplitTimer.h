#pragma once
#include <Windows.h>
#include <cassert>

namespace LZSoft
{
	namespace Timing
	{
		class __declspec(dllexport) SplitTimer
		{
		private:
			LARGE_INTEGER li;
			long long elapsed;
			long long  elapsedLast;
		public:
			float Split();
			float SplitAndReset();
		};
	}
}