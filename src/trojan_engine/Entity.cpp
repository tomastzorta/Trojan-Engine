#include "Entity.h"
#include "Component.h"
#include "Core.h"
#include <iostream>

namespace trojan_engine {

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
}