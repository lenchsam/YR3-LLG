#pragma once
#include "GameObject.h"
#include "Player.h"
#include "SpriteRenderer.h"

namespace LLGP {
    class Bullet :
        public GameObject
    {
    public:
        Bullet(bool firedByPlayer);
        ~Bullet();

        void SetPlayer(Player* player);
        Transform* transform;

        bool firedByPlayer;

        SpriteRenderer* spriteRenderer;

        void Fire(GameObject* player, sf::RenderWindow* window);

        void MoveBullet();
        float m_Damage;
    private:

        Player* m_player;
        float m_Speed;
        sf::Vector2f m_directionToFire;
    };
}

