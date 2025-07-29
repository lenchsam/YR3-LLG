#pragma once
#include "Enemy.h"
namespace LLGP {
    class Sinistar :
        public Enemy
    {
    public:
        Sinistar();
        ~Sinistar();
        void Init() override;

        void DestroyThis(Spawner* spawner) override;
        void GoToTarget(GameObject* player, sf::Vector2f /*target*/ = {0, 0}) override;
        sf::Vector2f ChooseTarget(sf::Vector2f playerPosition);

        void OnCollision(GameObject* other) override;

    private:
        sf::Vector2f m_target;
        std::vector<sf::Vector2f> targetPositions;

        int currentStarLocation;
        std::vector<sf::Vector2f> starLocations = { {-190, 62}, {0, -200}, {190, 62}, {-190, -63}, {190, -62}, {-190, 62} }; //used to get a star shape around the player.
        //bottom left
        //top
        //bottom right
        //top left
        //top right
        //bottom left

        bool isDashing = false;
        bool justDashed = false;
        float m_dashSpeedMultiplier = 2.f;
        float m_waitTimeAfterDash = 0.5f;
    };
}

