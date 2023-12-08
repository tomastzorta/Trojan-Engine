//
// Created by NAT20 on 03/12/2023.
//

#include "Texture.h"

namespace trojan_engine
{

    void Texture::OnLoad()
    {
        m_texture = std::make_shared<rend::Texture>(std::string(GetPath() + ".png").c_str());
    }

}