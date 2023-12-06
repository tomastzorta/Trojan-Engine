//
// Created by NAT20 on 03/12/2023.
//

#include "Resource.h"

#include <utility>

namespace trojan_engine
{
    void Resource::SetResources(std::weak_ptr<Resources> a_resources)
    {
        m_resources = a_resources;
    }

    std::string Resource::GetPath()
    {
        return m_path;
    }

    void Resource::Load()
    {
        OnLoad();
    }
}