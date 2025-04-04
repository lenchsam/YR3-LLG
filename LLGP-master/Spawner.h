#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Health.h"
#include <SFML/Graphics.hpp>


namespace LLGP{
    class GameObject;
    class Planetoid;
    class WarriorDrone;
    class Spawner: public GameObject
    {
    public:
        Spawner(GameObject* player);
        void Spawn(sf::RenderWindow* window);
        void DrawAllEnemies(sf::RenderWindow* window);
        void MoveAllEnemies();
    private:
        void SpawnWorkerDrones();
        void SpawnWarriorDrones();
        void SpawnPlanetoids();
        GameObject* _player;
        sf::Vector2f GetRandomPosition();
        template <typename T>
        T* CreateNewEnemy(std::string path);
        int spawnRadius = 1000;
        std::vector<WarriorDrone*> WarriorDrones;
        std::vector<GameObject*> WorkerDrones;
        std::vector<Planetoid*> Planetoids;
        int m_maxWorkerDroneSpawned = 1;
        int m_maxWarriorDroneSpawned = 1;
        int m_maxPlanetoidSpawned = 15;
    };
}


