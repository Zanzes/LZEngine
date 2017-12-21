#pragma once
#include <Math/Vector3D.h>
#include <ComponentSystem/Components/Initer.h>

namespace LZSoft
{
	namespace ComponentSystem
	{
		class Component;

		class __declspec(dllexport) GameObject : public Initer
		{
			static const int MAX_COMPONENT_COUNT = 10;
			Component* components[MAX_COMPONENT_COUNT];
			int componentCount;
		public:
			float orientation=0.f;
			GameObject();
			void update();
			bool initialize();
			bool shutdown();
			Math::Vector3D position;
			void addComponent(Component* component);

			template <class T>
			T* getComponent() const;
		};

		template <class T>
		T* GameObject::getComponent() const
		{
			for (int i = 0; i < componentCount; i++)
			{
				T* ret = dynamic_cast<T*>(components[i]);
				if (ret != 0)
					return ret;
			}
			return 0;
		}
	}
}
