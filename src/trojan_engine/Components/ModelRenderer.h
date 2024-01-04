//
// Created by s5216712 on 04/01/2024.
//

#ifndef MODELRENDERER_H
#define MODELRENDERER_H

#include "trojan_engine/Component.h"


namespace trojan_engine
{
    struct Shader;
    struct Texture;
    struct Model;

    struct ModelRenderer : Component
    {
        void SetModel(std::shared_ptr<Model> a_model);

        private:
            std::shared_ptr<Model> m_model;
            rend::ModelShader m_shader_;
            void OnDisplay();
    };
}




#endif //MODELRENDERER_H
