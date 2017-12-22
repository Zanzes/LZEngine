#pragma once

namespace LZSoft
{
	namespace Input
	{
		class __declspec(dllexport) IKeyMapper
		{
		public:
			//virtual int getActionFor(int key) const = 0;
			virtual int getKeyFor(int action) const = 0;
		};
	}
}