//
// Created by NAT20 on 03/12/2023.
//

#ifndef TROJAN_ENGINE_RESOURCES_H
#define TROJAN_ENGINE_RESOURCES_H

#include <string>
#include <memory>
#include <vector>
#include "Resource.h"

namespace trojan_engine
{
    struct Resource;

    struct Resources
    {
        template <typename T>
        std::shared_ptr<T> Load(const std::string& _path)
        {
            //Search for previously loaded resource
            for(const auto & m_resource : m_resources)
            {
                if(m_resource->GetPath() == _path)
                {
                    return std::static_pointer_cast<T>(m_resource);
                }
            }

            //create new instance, construct it and add to cache
            std::shared_ptr<T> newResource = std::make_shared<T>();
            newResource->SetResources(m_self);
            newResource->m_path = _path;
            newResource->Load();
            m_resources.push_back(newResource);

            return newResource;
        }

    private:
        std::weak_ptr<Resources> m_self;
        std::vector<std::shared_ptr<Resource> > m_resources;
    };
}

#endif //TROJAN_ENGINE_RESOURCES_H
