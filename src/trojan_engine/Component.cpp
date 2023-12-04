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
	}
	void Component::onDisplay()
	{
	}
	void Component::onKill()
	{
	}
	void Component::tick()
	{
		onTick();
	}
	void Component::display()
	{
		onDisplay();
	}
	void Component::kill()
	{
		onKill();
	}
	void Component::initialize()
	{

	}
}
