//
// Created by NAT20 on 06/12/2023.
//

#ifndef MODEL_H
#define MODEL_H
#include "Resources.h"

namespace trojan_engine
{
    struct Texture;

    struct Model : Resource
    {
        void OnLoad() override;

    private:
        std::shared_ptr<rend::Mesh> m_mesh;
        std::shared_ptr<Texture> m_texture;
    };
}

#endif //MODEL_H
