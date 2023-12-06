#include "Component.h"
#include "Core.h"
#include "Components/Transform.h"

namespace trojan_engine
{
	std::shared_ptr<Entity> Component::GetEntity() const
	{
		return m_entity.lock();
	}

    std::shared_ptr<Core> Component::GetCore() const
    {
        return m_core.lock();
    }

    std::shared_ptr<Transform> Component::GetTransform() const
    {
		return m_transform.lock();
    }

    void Component::OnTick()
	{
	}

	void Component::OnDisplay()
	{
	}

	void Component::OnKill()
	{
	}

	void Component::Tick()
	{
		OnTick();
	}

	void Component::Display()
	{
		OnDisplay();
	}

	void Component::Kill()
	{
		OnKill();
	}

	void Component::Initialize()
	{

	}
}
