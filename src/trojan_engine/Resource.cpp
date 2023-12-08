//
// Created by NAT20 on 03/12/2023.
//

#include "Resource.h"

#include <utility>

namespace trojan_engine
{
    std::string Resource::GetPath()
    {
        return m_path;
    }

    void Resource::Load()
    {
        OnLoad();
    }
}