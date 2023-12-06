#pragma once
#include <vector>
#include <iostream>
#include <memory>

namespace trojan_engine
{
    struct Core;
    struct Component;
    struct Transform;
    struct Player;

    struct Entity
    {
        Entity();

        template<typename T>
        std::shared_ptr<T> AddComponent()
        {
            std::shared_ptr<T> newComponent = std::make_shared<T>();

            newComponent->m_entity = m_self;
            newComponent->m_core = m_core;
            newComponent->m_transform = m_transform;

            newComponent->Initialize();
            m_components.push_back(newComponent);

            return newComponent;
        }

        std::shared_ptr<Transform> GetTransform() const;

        bool Alive() const;
        void Kill();
        std::shared_ptr<Core> GetCore() const;

    private:
        friend struct Core;
        void Tick() const;
        void Display() const;

        bool m_alive = true;
        std::vector<std::shared_ptr<Component> > m_components;
        std::weak_ptr<Core> m_core;
        std::weak_ptr<Entity> m_self;
        std::weak_ptr<Transform> m_transform;
    };
}