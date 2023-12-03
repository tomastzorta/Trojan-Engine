//
// Created by NAT20 on 03/12/2023.
//

#ifndef TROJAN_ENGINE_RESOURCE_H
#define TROJAN_ENGINE_RESOURCE_H

#include <string>

namespace trojan_engine
{
    struct Resources;
    struct Resource
    {
        friend struct Resources;
        virtual void onLoad() = 0;

        std::string getPath();

    private:
        std::string m_path;

        void load();
    };
}


#endif //TROJAN_ENGINE_RESOURCE_H