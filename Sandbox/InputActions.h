#pragma once

namespace LZSoft
{
	namespace Input
	{
		enum InputActions
		{
			Accelerate	= (1 << 0),
			Break		= (1 << 1),
			RorateLeft	= (1 << 2),
			RotateRight = (1 << 3),
			Max			= (1 << 4)

		};
	}
}