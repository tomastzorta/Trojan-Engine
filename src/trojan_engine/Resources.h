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
    struct Resource;
    struct Resources
    {
        template <typename T>
        std::shared_ptr<T> load(const std::string& _path);

    private:
        std::vector<std::shared_ptr<Resource> > m_resources;
    };
}

#endif //TROJAN_ENGINE_RESOURCES_H
