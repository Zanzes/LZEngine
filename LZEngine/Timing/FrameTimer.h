// WindowsPerfTools.h
#pragma once
#include <cassert>

namespace LZSoft
{
	namespace Timing
	{
		class __declspec(dllexport) FrameTimer
		{
		private:
			FrameTimer() {};
			FrameTimer(const FrameTimer&);
			FrameTimer& operator=(const FrameTimer&);

			static long long elapsed;
			static long long  elapsedLast;
		public:
			static float Frame();
		};
	}
}