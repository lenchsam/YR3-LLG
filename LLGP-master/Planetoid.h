#pragma once
#include "Enemy.h"
namespace LLGP {
    class Spawner;
    class Planetoid :
        public Enemy
    {
    public:
        Planetoid();
        ~Planetoid();

        //void Drawing(sf::RenderWindow* window);

        void OnCollision(GameObject* other);
        void Init() override;

        void GoToTarget(GameObject* player, sf::Vector2f target = { 0, 0 }) override;

        void DestroyThis(Spawner* spawner) override;

        int GetCrystalNumber();

    private:
        void RandomMovements();

        void SpawnCrystals();

        float m_MovementSpeed;

        int m_crystals = 5;

        sf::Vector2f m_target;
        float m_speed;
    };
}

