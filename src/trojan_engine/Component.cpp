#include "Component.h"
#include "Core.h"

namespace trojan_engine {
	std::shared_ptr<Entity> Component::getEntity()
	{
		return m_entity.lock();
	}
    std::shared_ptr<Core> Component::getCore()
    {
        return m_core.lock();
    }
	void Component::onTick()
	{
		std::cout << "OnTick called" << std::endl;
	}
	void Component::onDisplay()
	{
		std::cout << "onDisplay called" << std::endl;
	}
	void Component::onKill()
	{
		std::cout << "onKill called" << std::endl;
	}
	void Component::tick()
	{
		onTick();
		std::cout << "tick called" << std::endl;
	}
	void Component::display()
	{
		onDisplay();
		std::cout << "display called" << std::endl;
	}
	void Component::kill()
	{
		onKill();
		std::cout << "kill called" << std::endl;
	}
	void Component::initialize()
	{
		std::cout << "initialize called" << std::endl;
	}
}
