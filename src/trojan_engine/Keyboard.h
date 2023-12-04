//
// Created by s5216712 on 04/12/2023.
//

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <vector>
#include <algorithm>



namespace trojan_engine
{

    struct Event
    {
        enum EventType
        {
            KEY_PRESSED,
            KEY_RELEASED
        };

        EventType type;
        int key;
    };

    struct Keyboard
    {
        void handleEvent(const Event& a_event);

        bool isKey(int a_key);
        bool isKeyPressed(int a_key);
        bool isKeyReleased(int a_key);

        void onTick();

    private:
        std::vector<int> m_keys;
        std::vector<int> m_pressedKeys;
        std::vector<int> m_releasedKeys;
    };
}




#endif //KEYBOARD_H
