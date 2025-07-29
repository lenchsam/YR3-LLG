#pragma once
#include "GameObject.h"
namespace LLGP {
    class Bomb :
        public GameObject
    {
    public:
        Bomb();
        ~Bomb();

    private:
        float m_damage;
        float m_timeBeforeDetonation;

    };
}

