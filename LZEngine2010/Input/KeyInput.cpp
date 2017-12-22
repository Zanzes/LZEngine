#include "KeyInput.h"
#include <Input/IKeyMapper.h>
#include <Windows.h>

namespace LZSoft
{
	namespace Input
	{
		KeyInput KeyInput::instance;

		bool KeyInput::initialize(IKeyMapper* keyMapper, int maxActionValue)
		{
			if (keyMapper == 0 || maxActionValue < 0)
				return false;

			this->keyMapper = keyMapper;
			this->maxActionValue = maxActionValue;
			return true;
		}

		bool KeyInput::shutdown()
		{
			return true;
		}

		void KeyInput::update()
		{
			actionsRequested = 0;
			for (int i = 1; i < maxActionValue; i = i << 1)
				if (GetAsyncKeyState(keyMapper->getKeyFor(i)))
					actionsRequested |= i;
		}


		bool KeyInput::keyDown(const int actions) const
		{
			return (actionsRequested & actions) > 0;
		}

		KeyInput& KeyInput::getInstance()
		{
			return instance;
		}

	}
}
