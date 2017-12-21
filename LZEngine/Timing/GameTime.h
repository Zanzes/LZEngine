#pragma once

namespace LZSoft
{
	namespace Timing
	{
		class __declspec(dllexport) GameTime
		{
			GameTime() {};
			GameTime(const GameTime&);
			GameTime& operator=(const GameTime&);

			float deltaTime;

			static GameTime theInstance;
		public:
			void update();
			float getDeltaTime() const;

			static GameTime& getInstance();
		};
#define DeltaTime LZSoft::Timing::GameTime::getInstance().getDeltaTime()
	}
}
