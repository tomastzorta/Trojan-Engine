//
// Created by NAT20 on 06/12/2023.
//

#include "Shader.h"

#include "Model.h"

#include <fstream>

namespace trojan_engine
{
    void Shader::OnLoad()
    {
        m_shader = std::make_shared<rend::Shader>();
        std::string vert;
        {
            std::ifstream file(std::string(GetPath() + ".vert").c_str());
            if (!file.is_open())
            {
                throw std::runtime_error("Failed to open file");
            }

            while (!file.eof()) {
                std::string line;
                std::getline(file, line);
                vert += "\n" + line;
            }
        }
        std::string frag;
        {
            std::ifstream file(std::string(GetPath() + ".frag").c_str());
            if (!file.is_open())
            {
                throw std::runtime_error("Failed to open file");
            }

            while (!file.eof()) {
                std::string line;
                std::getline(file, line);
                frag += "\n" + line;
            }
        }
        m_shader->load(vert.c_str(), frag.c_str());
    }

}

