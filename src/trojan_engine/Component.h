#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>
#include <iostream>
#include <rend/rend.h>

namespace trojan_engine
{
	struct Entity;
    struct Core;
	struct Transform;

	struct Component
    {
		std::shared_ptr<Entity> GetEntity() const;
        std::shared_ptr<Core> GetCore() const;
		std::shared_ptr<Transform> GetTransform() const;


	private:
		friend struct Entity;

		virtual void OnTick();
		virtual void OnDisplay();
		virtual void OnKill();

		void Tick();
		void Display();
		void Kill();

		virtual void Initialize();

		std::weak_ptr<Entity> m_entity;
        std::weak_ptr<Core> m_core;
		std::weak_ptr<Transform> m_transform;
	};
}

#endif

