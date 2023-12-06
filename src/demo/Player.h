//
// Created by NAT20 on 03/12/2023.
//

#ifndef TROJAN_ENGINE_PLAYER_H
#define TROJAN_ENGINE_PLAYER_H

namespace trojan_engine
{
    struct Keyboard;

    struct Player : Component
    {
        void OnTick() override;

        void Initialize();


    private:
        int m_count_ = 0;
        std::shared_ptr<Keyboard> m_keyboard;
    };
}



#endif //TROJAN_ENGINE_PLAYER_H
