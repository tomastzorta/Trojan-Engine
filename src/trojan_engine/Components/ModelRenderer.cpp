//
// Created by s5216712 on 04/01/2024.
//

#include "ModelRenderer.h"

#include "trojan_engine/Resources/Model.h"
#include "trojan_engine/Resources/Shader.h"
#include "trojan_engine/Entity.h"
#include "trojan_engine/Components/Transform.h"
#include "trojan_engine/Resources/Texture.h"


namespace trojan_engine
{

    void ModelRenderer::OnDisplay()
    {
        if (!m_model) return;

        m_shader_.model(*m_model->m_model);

        m_shader_.projection(rend::perspective(rend::radians(45.0f), 1.0f, 0.1f, 100.0f));
        //m_shader_->m_shader->uniform("u_Model", rend::translate(rend::mat4(1.0f), rend::vec3(0, 0, -10)));

        m_shader_.model(GetEntity()->GetTransform()->GetModel());

        m_shader_.render();

    }

    void ModelRenderer::SetModel(std::shared_ptr<Model> a_model)
    {
        m_model = a_model;
    }

}
