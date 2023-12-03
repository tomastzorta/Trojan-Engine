#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "Transform.h" // Include the Transform component

namespace trojan_engine {
    struct Core;
    struct Component;

    struct Entity {
        Entity()
        {
            m_transform = addComponent<Transform>(); // Add a Transform component upon creation
        }

        template <typename T>
        std::shared_ptr<T> addComponent()
        {
            std::shared_ptr<T> rtn = std::make_shared<T>();

            rtn->m_entity = m_self;

            rtn->initialize();
            m_components.push_back(rtn);

            return rtn;
        }

        std::shared_ptr<Transform> getTransform() // Add a getter for the Transform component
        {
            return m_transform.lock();
        }



        bool alive();
        void kill();
        std::shared_ptr<Core> getCore();

    private:
        friend struct Core;
        void tick();
        void display();

        bool m_alive = true;
        std::vector<std::shared_ptr<Component> > m_components;
        std::weak_ptr<Core> m_core;
        std::weak_ptr<Entity> m_self;
        std::weak_ptr<Transform> m_transform; // Add a weak pointer to the Transform component
    };
}