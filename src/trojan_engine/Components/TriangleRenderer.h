#pragma once
#include "trojan_engine/Component.h"

namespace trojan_engine
{
    struct TriangleRenderer : Component
    {
        TriangleRenderer();

    private:
        rend::Mesh m_mesh_;
        rend::Shader m_shader_;

        void on_initialize();
        void OnDisplay();
    };
}


