//
// Created by NAT20 on 06/12/2023.
//

#ifndef MODEL_H
#define MODEL_H

#include "trojan_engine/Resources.h"

namespace trojan_engine
{
    struct Texture;
    struct Model;

    struct Model : Resource
    {
        void OnLoad() override;

    private:
        friend struct ModelRenderer;
        std::shared_ptr<rend::Model> m_model;
    };
}

#endif //MODEL_H
