//
// Created by NAT20 on 03/12/2023.
//

#include "trojan_engine/trojanEngine.h"
#include "Player.h"

namespace trojan_engine
{

    void Player::Initialize()
    {
        //std::shared_ptr<TriangleRenderer> tr = GetEntity()->AddComponent<TriangleRenderer>();
        //std::shared_ptr<Texture> text = GetCore()->GetResources()->Load<Texture>("../assets/image");
        std::shared_ptr<Model> model = GetCore()->GetResources()->Load<Model>("../assets/models/curuthers");
        //tr->SetShader(GetCore()->GetResources()->Load<Shader>("../assets/shaders/shader"));
       // tr->SetTexture(text);
        std::shared_ptr<ModelRenderer> mr = GetEntity()->AddComponent<ModelRenderer>();
        mr->SetModel(model);
        m_keyboard = GetCore()->GetKeyboard();
    }

    void Player::OnTick()
    {
        /*m_count_++;
        if (m_count_ > 10)
        {
            //getEntity()->kill();
            //getCore()->stop();
        }*/

        glm::vec3 position = GetTransform()->position;

        if (m_keyboard->isKeyPressed(SDLK_w)) {
            position.y += 1.0f;
        }
        if (m_keyboard->isKeyPressed(SDLK_s)) {
            position.y -= 1.0f;
        }
        if (m_keyboard->isKeyPressed(SDLK_a)) {
            position.x -= 1.0f;
        }
        if (m_keyboard->isKeyPressed(SDLK_d)) {
            position.x += 1.0f;
        }

        GetTransform()->setPosition(position);
        GetTransform()->Rotate(glm::vec3(0.0f, 1.0f, 0.0f));
    }


}
