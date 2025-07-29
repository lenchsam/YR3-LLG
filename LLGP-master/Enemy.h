#pragma once
#include "GameObject.h"
#include "Health.h"
namespace LLGP {
    class CircleCollider;
    class Spawner;
    class Enemy :
        public GameObject
    {
    public:
        Enemy();
        SpriteRenderer* spriteRenderer;
        Health* health;
        virtual void GoToTarget(GameObject* /*player*/, sf::Vector2f target = { 0, 0 }); //target set to make it optional
        virtual void Init();
        float m_speed = 2.f;
        void OnCollision(GameObject* other) override;

        void RotateTowardsPlayer(GameObject* player);

        void DestroyThis(Spawner* spawner) override;
    protected:
        float m_minDistnaceFromPlayer = 50.f; //0 = no min distance 

        void Draw(sf::RenderWindow* window);

        CircleCollider* circleCollider;
    };
}

