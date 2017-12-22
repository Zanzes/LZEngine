#pragma once
#include <Input/IKeyMapper.h>

namespace LZSoft
{
	namespace Input
	{
		class NewKeyMapper: public IKeyMapper
		{
		public:
			//int getActionFor(int key) const;
			int getKeyFor(int action) const;
		};
	}
}