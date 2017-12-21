#pragma once


namespace LZSoft
{
	namespace ComponentSystem
	{
		class GameObject;
		class __declspec(dllexport) Component
		{
			friend class GameObject;
			GameObject* gameObject;
		public:
			GameObject * getGameObject() const { return gameObject; }
			virtual void update() {};
			virtual bool initialize() { return true; };
			virtual bool shutdown() { return true; };
		};
	}
}