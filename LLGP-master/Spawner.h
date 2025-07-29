#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Health.h"
#include <SFML/Graphics.hpp>


namespace LLGP{
    class GameObject;
    class Planetoid;
    class WarriorDrone;
    class WorkerDrone;
    class Enemy;
    class Sinistar;
    class Spawner: public GameObject
    {
    public:
        Spawner(GameObject* player);
        void Spawn(sf::RenderWindow* window);
        void DrawAllEnemies(sf::RenderWindow* window);
        void MoveAllEnemies();
        void RotateTowardsPlayer(GameObject* player);

        void DestroyWarriorDroneFromList(GameObject* enemy);
        void DestroyWorkerDroneFromList(GameObject* enemy);
        void DestroyPlanetoidFromList(GameObject* enemy);
    private:
        void AddToDestroyedList(GameObject* enemyToDestroy);
        void DestroyAllNeccessary();

        void SpawnWorkerDrones();
        void SpawnWarriorDrones();
        void SpawnPlanetoids();

        GameObject* _player;
        sf::Vector2f GetRandomPosition();
        template <typename T>
        T* CreateNewEnemy(std::string path);
        int spawnRadius = 1000;
        std::vector<WarriorDrone*> WarriorDrones;
        std::vector<WorkerDrone*> WorkerDrones;
        std::vector<Planetoid*> Planetoids;
        std::vector<GameObject*> DestroyedEnemies;
        int m_maxWorkerDroneSpawned = 15;
        int m_maxWarriorDroneSpawned = 4;
        int m_maxPlanetoidSpawned = 15;

        Sinistar* sinistar;
    };
}


