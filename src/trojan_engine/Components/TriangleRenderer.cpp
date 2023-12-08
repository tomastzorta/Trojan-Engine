#include "TriangleRenderer.h"
#include "Transform.h"
#include "../Entity.h"
#include "../Resources/Shader.h"


namespace trojan_engine
{
    TriangleRenderer::TriangleRenderer()
    {
        on_initialize();
    }


    
    void TriangleRenderer::on_initialize()
    {
        m_mesh_.load(rend::TRIANGLE_MESH);

    }

    void TriangleRenderer::OnDisplay()
    {
        m_shader_->m_shader->attribute("a_Position", *m_mesh_.positions());

        m_shader_->m_shader->uniform("u_Projection", rend::perspective(rend::radians(45.0f), 1.0f, 0.1f, 100.0f));
        //m_shader_->m_shader->uniform("u_Model", rend::translate(rend::mat4(1.0f), rend::vec3(0, 0, -10)));

        m_shader_->m_shader->uniform("u_Color", rend::vec4(1.0f, 0.0f, 0.0f, 1.0f));
        m_shader_->m_shader->uniform("u_Model", GetEntity()->GetTransform()->GetModel());

        m_shader_->m_shader->render();
    }

    void TriangleRenderer::SetShader(std::shared_ptr<Shader> a_shader)
    {
        m_shader_ = a_shader;
    }


}
