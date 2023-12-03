//
// Created by NAT20 on 03/12/2023.
//

#include "Resource.h"

namespace trojan_engine
{
    std::string Resource::getPath()
    {
        return m_path;
    }

    void Resource::load()
    {
        onLoad();
    }
}