//
// Created by NAT20 on 03/12/2023.
//

#include "Transform.h"

namespace trojan_engine
{
    glm::mat4 Transform::getModel() const
    {
        glm::mat4 rtn(1.0f);
        rtn = glm::translate(rtn, position);

        rtn = glm::rotate(rtn, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        rtn = glm::rotate(rtn, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        rtn = glm::rotate(rtn, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

        rtn = glm::scale(rtn, scale);

        return rtn;
    }

    void Transform::setPosition(glm::vec3 a_translation)
    {
        position = a_translation;
    }

    void Transform::Rotate(glm::vec3 a_rotation)
    {
        rotation += a_rotation;
    }
}