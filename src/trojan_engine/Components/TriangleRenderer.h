#pragma once
#include "trojan_engine/Component.h"



namespace trojan_engine
{
    struct Shader;
    struct Texture;

    struct TriangleRenderer : Component
    {
        TriangleRenderer();

        void SetShader(std::shared_ptr<Shader> a_shader);
        void SetTexture(std::shared_ptr<Texture> a_texture);

    private:
        rend::Mesh m_mesh_;
        std::shared_ptr<Texture> m_texture;
        std::shared_ptr<Shader> m_shader_;

        void on_initialize();
        void OnDisplay();
    };
}


