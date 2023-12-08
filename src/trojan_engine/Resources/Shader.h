//
// Created by NAT20 on 06/12/2023.
//

#ifndef SHADER_H
#define SHADER_H
#include "trojan_engine/Resources.h"

namespace trojan_engine
{
    struct Model;
    struct TriangleRenderer;

    struct Shader : Resource
    {
        void OnLoad() override;

    private:
        friend struct TriangleRenderer;
        std::shared_ptr<rend::Shader> m_shader;
    };
}



#endif //SHADER_H
