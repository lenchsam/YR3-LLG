#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

namespace LLGP {
    class Bullet;
    class Health;
    class Player :
        public GameObject
    {
    public:
        Player(sf::View* view);
        ~Player();
        void MoveCamera(sf::Vector2f movement);
        void SetCameraPosition(sf::Vector2f newPosition);
        sf::View* m_view;
        void Shoot(float deltaTime, sf::RenderWindow* window);

        void MoveAllBullets();

        void DestroyThis(Spawner* spawner = nullptr) override;

        static inline LLGP::Event<> PlayerDead;
    private:
        std::vector<Bullet*> _Bullets;
        float m_shootingSpeed = 0.5f;
        float m_time = 0;

        void DrawAllBullets(sf::RenderWindow* window);
        void DrawAll(sf::RenderWindow* window);
        SpriteRenderer* playerSpriteRenderer;
		Health* playerHealth;
    };
}

