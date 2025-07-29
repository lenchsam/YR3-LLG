#pragma once
#include "Enemy.h"
namespace LLGP {
    class Spawner;
    class WarriorDrone :
        public Enemy
    {
    public:
        WarriorDrone();
        ~WarriorDrone();

        void Init() override;

        void DestroyThis(Spawner* spawner) override;
        void GoToTarget(GameObject* player, sf::Vector2f target = { 0, 0 }) override;
    private:
        float m_minDistnaceFromPlayer = 50.f;
        sf::Vector2f m_target;
    };
}

