#include "Entity.h"
#include "Component.h"
#include "Core.h"
#include "Resources.h"
#include <iostream>

namespace trojan_engine
{
    Entity::Entity()
    {
        m_transform = addComponent<Transform>(); // Add a Transform component upon creation
    }

    void trojan_engine::Entity::kill()
    {
        std::cout << "I Kill" << std::endl;
        if (!m_alive) return;

        m_alive = false;

        for (size_t ci = 0; ci < m_components.size(); ++ci)
        {
            m_components.at(ci)->kill();
        }
    }

    std::shared_ptr<Core> Entity::getCore()
    {
        return m_core.lock();
    }

    void trojan_engine::Entity::tick()
    {
        for (size_t ci = 0; ci < m_components.size(); ++ci)
        {
            m_components.at(ci)->tick();
        }
    }

    void trojan_engine::Entity::display()
    {
        for (size_t ci = 0; ci < m_components.size(); ++ci)
        {
            m_components.at(ci)->display();
        }
    }

    bool trojan_engine::Entity::alive()
    {
        return m_alive;
    }

    std::shared_ptr<Transform> Entity::getTransform() // Add a getter for the Transform component
    {
        return m_transform.lock();
    }

    std::shared_ptr<Resources> Entity::getResources()
    {
        return m_resources;
    }
}