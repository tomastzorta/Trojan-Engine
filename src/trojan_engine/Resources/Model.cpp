//
// Created by NAT20 on 06/12/2023.
//

#include "Model.h"

namespace trojan_engine
{

    void Model::OnLoad()
    {
        m_model = std::make_shared<rend::Model>(std::string(GetPath() + ".obj").c_str());
    }
}
