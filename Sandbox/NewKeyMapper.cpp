#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "NewKeyMapper.h"
#include "InputActions.h"

namespace LZSoft
{
	namespace Input
	{
		/*int NewKeyMapper::getActionFor(int key) const
		{
			switch (key)
			{
			case Accelerate:
				return VK_UP;
			case Break:
				return VK_DOWN;
			case RorateLeft:
				return VK_LEFT;
			case RotateRight:
				return VK_RIGHT;
			case Max:
				return VK_SPACE;
			default:
				return 0;
			}	
			return -1;
		}*/

		int NewKeyMapper::getKeyFor(int action) const
		{
			switch (action)
			{
			case Accelerate:
				return VK_UP;
			case Break:
				return VK_DOWN;
			case RorateLeft:
				return VK_LEFT;
			case RotateRight:
				return VK_RIGHT;
			case Max:
				return VK_SPACE;
			default:
				return 0;
			}
			return -1;
		}
	}
} 