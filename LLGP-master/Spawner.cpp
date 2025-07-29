#include "Spawner.h"
#include <iostream>
#include <random>
#include "Physics.h"
#include "Planetoid.h"
#include "WarriorDrone.h"
#include "WorkerDrone.h"
#include "SpriteRenderer.h"
#include "Sinistar.h"

using namespace std;
namespace LLGP {
    Spawner::Spawner(GameObject* player) {
        _player = player;
        Physics::OnStepPhysics += std::bind(&Spawner::MoveAllEnemies, this);
        GameObject::OnWorldEndFrame += std::bind(&Spawner::DestroyAllNeccessary, this);
        Health::OnEnemyDeath += std::bind(&Spawner::AddToDestroyedList, this, std::placeholders::_1);

        sinistar = new Sinistar();
        sinistar->spriteRenderer->LoadTexture("assets/SPRITES/HOUSE.png");
        sinistar->Init();
    }

    template <typename T>
    T* Spawner::CreateNewEnemy(std::string path) {
        T* enemy = new T();

        enemy->spriteRenderer->LoadTexture(path);
        enemy->Init();

        return enemy;
    }
    void Spawner::RotateTowardsPlayer(GameObject* player) {
        for (WarriorDrone* enemy : WarriorDrones) {
            enemy->RotateTowardsPlayer(player);
        }
		for (WorkerDrone* enemy : WorkerDrones) {
			enemy->RotateTowardsPlayer(player);
		}
    }
    void Spawner::Spawn(sf::RenderWindow* window) {
        SpawnWorkerDrones();
        SpawnWarriorDrones();
        SpawnPlanetoids();
    }
    
    void Spawner::MoveAllEnemies() {
        for (WarriorDrone* enemy : WarriorDrones) {
            enemy->GoToTarget(_player);
        }
        for (WorkerDrone* enemy : WorkerDrones) {
            enemy->GoToTarget(_player);
        }
        sinistar->GoToTarget(_player);
    }

    void Spawner::DrawAllEnemies(sf::RenderWindow* window) {
        for (WarriorDrone* warrior : WarriorDrones) {
            warrior->GetComponent<SpriteRenderer>()->Draw(window);
        }
        for (WorkerDrone* worker : WorkerDrones) {
            worker->GetComponent<SpriteRenderer>()->Draw(window);
        }
        for (Planetoid* planetoid : Planetoids) {
            planetoid->GetComponent<SpriteRenderer>()->Draw(window);
        }

        window->draw(*sinistar->GetComponent<SpriteRenderer>()->GetSprite());
    }

    void Spawner::DestroyAllNeccessary() {
        for (GameObject* enemy : DestroyedEnemies) {
            enemy->DestroyThis(this);
        }
        DestroyedEnemies.clear();
    }

    void Spawner::DestroyWarriorDroneFromList(GameObject* enemy) {
        WarriorDrones.erase(std::remove(WarriorDrones.begin(), WarriorDrones.end(), enemy), WarriorDrones.end());
    }
    void Spawner::DestroyPlanetoidFromList(GameObject* enemy) {
        Planetoids.erase(std::remove(Planetoids.begin(), Planetoids.end(), enemy), Planetoids.end());
    }
    void Spawner::DestroyWorkerDroneFromList(GameObject* enemy) {
        WorkerDrones.erase(std::remove(WorkerDrones.begin(), WorkerDrones.end(), enemy), WorkerDrones.end());
    }
    
    sf::Vector2f Spawner::GetRandomPosition() {
        
        //sf::Vector2f playerPosition = player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition();
        sf::Vector2f playerPosition = { 0, 0 };

        int minX = playerPosition.x - spawnRadius;
        int maxX = playerPosition.x + spawnRadius;

        int minY = playerPosition.y - spawnRadius;
        int maxY = playerPosition.y + spawnRadius;

        std::random_device rd;
        std::mt19937 gen(rd());
        uniform_int_distribution<> distribX(minX, maxX);
        uniform_int_distribution<> distribY(minY, maxY);

        int randomValueX = distribX(gen);
        int randomValueY = distribY(gen);

        return sf::Vector2f(randomValueX, randomValueY);
    }

    void Spawner::SpawnWorkerDrones() {
        if (WorkerDrones.size() >= m_maxWorkerDroneSpawned) {
            return;
        }
        WorkerDrone* enemy = CreateNewEnemy<WorkerDrone>("assets/sprites/PLAYER.png");

        enemy->GetComponent<SpriteRenderer>()->GetSprite()->setPosition(GetRandomPosition());

        WorkerDrones.push_back(enemy);
    }
    void Spawner::SpawnWarriorDrones() {
        if (WarriorDrones.size() >= m_maxWarriorDroneSpawned) {
            return;
        }
        WarriorDrone* enemy = CreateNewEnemy<WarriorDrone>("assets/sprites/PLAYER.png");

        enemy->GetComponent<SpriteRenderer>()->GetSprite()->setPosition(GetRandomPosition());

        WarriorDrones.push_back(enemy);
    }
    void Spawner::SpawnPlanetoids() {
        if (Planetoids.size() >= m_maxPlanetoidSpawned) {
            return;
        }
        Planetoid* enemy = CreateNewEnemy<Planetoid>("assets/sprites/ROCK.png");

        enemy->GetComponent<SpriteRenderer>()->GetSprite()->setPosition(GetRandomPosition());

        Planetoids.push_back(enemy);
    }

    void Spawner::AddToDestroyedList(GameObject* enemyToDestroy) {
        DestroyedEnemies.push_back(enemyToDestroy);
    }
}
