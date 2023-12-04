//
// Created by NAT20 on 03/12/2023.
//

#include "trojan_engine/trojanEngine.h"
#include "trojan_engine/Keyboard.h"
#include "Player.h"

namespace trojan_engine
{

    void Player::initialize()
    {
        std::cout << "Player initializing with Core: " << (getEntity()->getCore() ? "Valid" : "Null") << std::endl;
        getEntity()->addComponent<TriangleRenderer>();
    }

    void Player::onTick()
    {
        /*m_count_++;
        if (m_count_ > 10)
        {
            //getEntity()->kill();
            //getCore()->stop();
        }*/
        auto m_keyboard = getEntity()->getCore()->getKeyboard();
        glm::vec3 position = getEntity()->getTransform()->position;

        if (m_keyboard->isKeyPressed(SDLK_w)) {
            position.y += 1.0f;
            std::cout << "W" << std::endl;
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

        getEntity()->getTransform()->setPosition(position);
        getEntity()->getTransform()->Rotate(glm::vec3(0.0f, 1.0f, 0.0f));

    }


}
