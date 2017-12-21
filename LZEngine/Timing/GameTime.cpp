#include "GameTime.h"
#include "Timing/FrameTimer.h"
namespace LZSoft
{
	namespace Timing
	{
		GameTime GameTime::theInstance;

		void GameTime::update()
		{
			deltaTime = FrameTimer::Frame();
		}

		float GameTime::getDeltaTime() const
		{
			return deltaTime;
		}

		GameTime& GameTime::getInstance()
		{
			return theInstance;
		}

	}
}