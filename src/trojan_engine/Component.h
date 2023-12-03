#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>
#include <iostream>

namespace trojan_engine
{
	struct Entity;
    struct Core;

	struct Component
    {
		std::shared_ptr<Entity> getEntity();
        std::shared_ptr<Core> getCore();
	private:
		friend struct Entity;

		virtual void onTick();
		virtual void onDisplay();
		virtual void onKill();

		void tick();
		void display();
		void kill();
		void initialize();
		std::weak_ptr<Entity> m_entity;
        std::weak_ptr<Core> m_core;
	};
}

#endif

