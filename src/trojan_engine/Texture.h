//
// Created by NAT20 on 03/12/2023.
//

#ifndef TROJAN_ENGINE_TEXTURE_H
#define TROJAN_ENGINE_TEXTURE_H

#include <memory>
#include "Resource.h"
#include "rend/Texture.h"

namespace trojan_engine
{
    struct Texture : Resource
    {
        Texture() = default;

        void onLoad() override;

    private:
        std::shared_ptr<rend::Texture> m_texture;
    };
}

#endif //TROJAN_ENGINE_TEXTURE_H