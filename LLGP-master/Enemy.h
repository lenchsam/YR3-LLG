#pragma once
#include "GameObject.h"
#include "Health.h"
namespace LLGP {
    class Enemy :
        public GameObject
    {
    public:
        Enemy();
        SpriteRenderer* spriteRenderer;
        Health* health;
        virtual void GoToTarget(GameObject* player);
        virtual void Init();
        float m_speed = 2.f;
        void OnCollision(GameObject* other) override;
    };
}

