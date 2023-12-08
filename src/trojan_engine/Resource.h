//
// Created by NAT20 on 03/12/2023.
//

#ifndef TROJAN_ENGINE_RESOURCE_H
#define TROJAN_ENGINE_RESOURCE_H

#include <string>
#include <memory>
#include "rend/rend.h"

namespace trojan_engine
{
    struct Resources;
    struct Resource
    {
        friend struct Resources;
        virtual void OnLoad() = 0;


        std::string GetPath();

    private:
        friend struct Resources;
        std::string m_path;
        std::weak_ptr<Resources> m_resources;

        void Load();
    };
}


#endif //TROJAN_ENGINE_RESOURCE_H
