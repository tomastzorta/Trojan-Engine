//
// Created by NAT20 on 03/12/2023.
//

#include "trojan_engine/trojanEngine.h"
#include "Player.h"

namespace trojan_engine
{

    void Player::onTick()
    {
        /*m_count_++;
        if (m_count_ > 10)
        {
            //getEntity()->kill();
            //getCore()->stop();
        }*/
        getEntity()->getTransform()->setPosition(glm::vec3(0.0f, 0.0f, -10.0f));
        getEntity()->getTransform()->Rotate(glm::vec3(0.0f, 1.0f, 0.0f));

    }

    void Player::initialize()
    {
        std::cout << "Player initializing with Core: " << (getEntity()->getCore() ? "Valid" : "Null") << std::endl;
        getEntity()->addComponent<TriangleRenderer>();
        auto keyboard = getCore()->getKeyboard();
    }
}
