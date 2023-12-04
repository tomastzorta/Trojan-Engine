//
// Created by NAT20 on 03/12/2023.
//

#ifndef TROJAN_ENGINE_PLAYER_H
#define TROJAN_ENGINE_PLAYER_H

namespace trojan_engine
{

    struct Player : Component
    {
        void onTick() override;

        void initialize();


    private:
        int m_count_ = 0;
    };
}



#endif //TROJAN_ENGINE_PLAYER_H
