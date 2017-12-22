#include "GameObject.h"
#include <ComponentSystem/Component.h>

namespace LZSoft
{
	namespace ComponentSystem
	{
		void GameObject::addComponent(Component* component)
		{
			component->gameObject = this;
			components[componentCount++] = component;
		}

		GameObject::GameObject(): componentCount(0), orientation(0)
		{
		}

		void GameObject::update()
		{
			for (int i = 0; i < componentCount; i++)
				components[i]->update();
		}

		bool GameObject::initialize()
		{
			bool r = true;
			for (int i = 0; i < componentCount; i++)
				 r &= components[i]->initialize();
			return r;
		}

		bool GameObject::shutdown()
		{
			bool r = true;
			for (int i = 0; i < componentCount; i++)
				r &= components[i]->shutdown();
			return r;
		}
	}
}
