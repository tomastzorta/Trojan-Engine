//
// Created by NAT20 on 03/12/2023.
//

#ifndef TROJAN_ENGINE_RESOURCES_H
#define TROJAN_ENGINE_RESOURCES_H

#include <string>
#include <memory>
#include <vector>

namespace trojan_engine
{
    struct Core;
    struct Resource;

    struct Resources
    {
        template <typename T>
        std::shared_ptr<T> load(const std::string& _path)
        {
            //Search for previously loaded resource
            for(size_t i = 0; i < m_resources.size(); i++)
            {
                if(m_resources.at(i)->getPath() == _path)
                {
                    return std::static_pointer_cast<T>(m_resources.at(i));
                }
            }

            //create new instance, construct it and add to cache
            std::shared_ptr<T> rtn = std::make_shared<T>();
            rtn->m_path = _path;
            rtn->load();
            m_resources.push_back(rtn);

            return rtn;
        }

    private:
        std::weak_ptr<Resources> m_self;
        std::weak_ptr<Core> m_core;
        std::vector<std::shared_ptr<Resource> > m_resources;
    };
}

#endif //TROJAN_ENGINE_RESOURCES_H
