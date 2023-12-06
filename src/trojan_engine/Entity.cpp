#include "Entity.h"
#include "Component.h"
#include "Core.h"
#include "Transform.h"
#include "demo/Player.h"

namespace trojan_engine
{
    Entity::Entity()
    {
        m_transform = AddComponent<Transform>(); // Add a Transform component upon creation
    }

    void Entity::Kill()
    {
        std::cout << "I Kill" << std::endl;
        if (!m_alive) return;

        m_alive = false;

        for (size_t ci = 0; ci < m_components.size(); ++ci)
        {
            m_components.at(ci)->Kill();
        }
    }

    std::shared_ptr<Core> Entity::GetCore() const
    {
        return m_core.lock();
    }

    void Entity::Tick() const
    {
        for (size_t ci = 0; ci < m_components.size(); ++ci)
        {
            m_components.at(ci)->Tick();
        }
    }

    void Entity::Display() const
    {
        for (size_t ci = 0; ci < m_components.size(); ++ci)
        {
            m_components.at(ci)->Display();
        }
    }

    bool Entity::Alive() const
    {
        return m_alive;
    }

    std::shared_ptr<Transform> Entity::GetTransform() const
    // Add a getter for the Transform component
    {
        return m_transform.lock();
    }
}
