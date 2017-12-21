#pragma once

namespace LZSoft
{
	namespace Input
	{
		class IKeyMapper;
		class __declspec(dllexport) KeyInput
		{
			IKeyMapper* keyMapper;
			int maxActionValue;

			int actionsRequested;

			KeyInput(){};
			KeyInput(const KeyInput&);
			KeyInput& operator=(const KeyInput&);
			static KeyInput instance;

		public:
			bool initialize(IKeyMapper* keyMapper, int maxActionValue);
			bool shutdown();
			void update();
			bool keyDown(int actions) const;
			int actionsThisFrame() const { return actionsRequested; }
			static KeyInput& getInstance();
		};
#define input LZSoft::Input::KeyInput::getInstance()

	}
}