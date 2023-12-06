//
// Created by s5216712 on 24/11/2023.
//

#ifndef TROJAN_ENGINE_TRANSFORM_H
#define TROJAN_ENGINE_TRANSFORM_H

#include "Component.h"

#include "rend/rend.h"


namespace trojan_engine
{
    struct Transform : Component
    {
        glm::vec3 position = glm::vec3(0.0f, 0.0f, -10.0f);
        glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 scale    = glm::vec3(1.0f, 1.0f, 1.0f);

        glm::mat4 GetModel() const;

        void setPosition(glm::vec3 a_translation);

        void Rotate(glm::vec3 a_rotation);

    };
}

#endif //TROJAN_ENGINE_TRANSFORM_H
