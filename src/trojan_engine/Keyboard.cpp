//
// Created by s5216712 on 04/12/2023.
//

#include "Keyboard.h"

void trojan_engine::Keyboard::handleEvent(const Event& a_event)
{
    if (a_event.type == Event::KEY_PRESSED)
    {
        m_keys.push_back(a_event.key);
        m_pressedKeys.push_back(a_event.key);
    }
    else if (a_event.type == Event::KEY_RELEASED)
        {
        m_keys.erase(std::remove(m_keys.begin(), m_keys.end(), a_event.key), m_keys.end());
        m_releasedKeys.push_back(a_event.key);
    }
}

bool trojan_engine::Keyboard::isKey(int a_key)
{
    return std::find(m_keys.begin(), m_keys.end(), a_key) != m_keys.end();
}

bool trojan_engine::Keyboard::isKeyPressed(int a_key)
{
    return std::find(m_pressedKeys.begin(), m_pressedKeys.end(), a_key) != m_pressedKeys.end();
}

bool trojan_engine::Keyboard::isKeyReleased(int a_key)
{
    return std::find(m_releasedKeys.begin(), m_releasedKeys.end(), a_key) != m_releasedKeys.end();
}

void trojan_engine::Keyboard::onTick()
{
    m_pressedKeys.clear();
    m_releasedKeys.clear();
}
