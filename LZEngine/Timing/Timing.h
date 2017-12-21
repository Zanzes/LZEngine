#pragma once
#include <Windows.h>
#include <cassert>

namespace LZSoft
{
	namespace Timing
	{
		class Timing
		{
		public:
			static inline float GetFrequency()
			{
				LARGE_INTEGER li;
				assert(QueryPerformanceFrequency(&li));
				return float(li.QuadPart);
			}
		};
#define Frequency LZSoft::Timing::Timing::GetFrequency()
	}
}