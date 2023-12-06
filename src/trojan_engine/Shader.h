//
// Created by NAT20 on 06/12/2023.
//

#ifndef SHADER_H
#define SHADER_H
#include "Resources.h"

namespace trojan_engine
{
    struct Model;

    struct Shader : Resource
    {
        void OnLoad() override;

        std::shared_ptr<rend::Shader> GetShader() { return m_shader; }

    private:
        std::shared_ptr<rend::Shader> m_shader;
    };
}



#endif //SHADER_H
